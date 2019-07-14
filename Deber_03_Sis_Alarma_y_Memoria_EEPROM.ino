/*
                    UNIVERSIDAD TECNICA DEL NORTE
                              CIERCOM
   Nombre:      Bolaños Santiago
   Asignatura:  Sistemas Microprocesados
   Actividad:   Deber 03_Segundo Bimestre
   Tema:        Realice un sistema reloj con alarma almacenada en la EEPROM
*/

#include <TimerOne.h>
#include <MsTimer2.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

//****************DECLARACION DE VARIABLES*****************
String hora;
String minu;
int HORAS;// variables de comparacion
int MINUTOS;//variables de comparacion
int segundero; // variable para segundero
int minutero;// variable para minutero
int horero;// variable para horero
int menu = 0;
int funcion = 0;// variable para llamar a la peticion de pass

void setup() {
  //******************CELDAS DE MEMORIA PARA DATOS DE RELOJ Y CONFIGURACION DE ALARMA POR CX SERAIL*****************
//  EEPROM.write(0, 0);
//  EEPROM.write(1, 0);
//  EEPROM.write(2, 0);
//  EEPROM.write(3, 0);
//  EEPROM.write(4, 0);
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  HORAS = EEPROM.read(3);
  MINUTOS = EEPROM.read(4);
  
  MsTimer2::set(1000, reloj);
  MsTimer2::start();
  Serial.begin(9600);
  attachInterrupt(0, funcionamiento, FALLING);
  attachInterrupt(1, alarma, FALLING);
  lcd.begin(16, 2);
  //*pines de alarma
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  //*
  Serial.println(" ");
  Serial.println("          *****************************************");
  Serial.println("                       BIENVENIDO A SU");
  Serial.println("                      SISTEMA DE ALARMA");
  Serial.println("          *****************************************");
}

void loop() {
  //  //*********************CILOS REPETITIVOS PARA SELECIONAR LA HORA Y MINUTOS DE ALARMA Y ACTIVARLA*******************
  if (funcion == 1) {
    if (Serial.available() > 0) {
      hora = Serial.readString();
      HORAS = hora.toInt();
      EEPROM.update(3, HORAS);
    }
  }
  if (funcion == 0) {
    if (Serial.available() > 0) {
      minu = Serial.readString();
      MINUTOS = minu.toInt();
      EEPROM.update(4, MINUTOS);
    }
  }
  if (menu == 1) {
    if ((horero == HORAS) && (minutero == MINUTOS)) {
      digitalWrite (22, HIGH);
      digitalWrite (23, HIGH);
      delay (1000);
    } else {
      digitalWrite (22, LOW);
      digitalWrite (23, LOW);
    }
  }
  if (menu == 0) {
    digitalWrite (23, LOW);
    digitalWrite (22, LOW);
  }
}
//***************INTERRUPCION DEL PULSADOR PARA INGRESAR POR CX SERAIL HORA Y MINUTOS********************
void funcionamiento() {
  funcion = 1 - funcion;
  if (funcion == 1) {
    Serial.println(" ");
    Serial.println("--> 1.Por Favor Ingrese La Hora De Alarma");
    
  } else if (funcion == 0) {
    Serial.println(" ");
    Serial.println("-> 2.Por Favor Ingrese Los Minutos De Alarma");
  }
}
//***************INTERRUPCION DEL PULSADOR PARA ACTIVAR O DESACTIVAR LA ALARMA********************
void alarma() {
  menu = 1 - menu;
  if (menu == 1) {
    Serial.println(" ");
    Serial.println("** Alarma Encendida **");
  } else if (menu == 0) {
    Serial.println(" ");
    Serial.println("** Alarma Apagada **");
  }
}
//*****************INTERRUPCION DEL TIMER2**************
void reloj() {
  if (segundero < 3) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
    segundero++;
    tiempo();
    //tiempoS();
    EEPROM.write(0, segundero);
  }
  else {
    segundero = 0;
    if (minutero < 3) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
      minutero++;
      tiempo();
      //tiempoS();
      EEPROM.write(1, minutero);
    }
    else {
      minutero = 0;
      if (horero < 1) {// la condicion debe ser menor que 23, debido a que al ser i=0, imprime el valor de 1 en el reloj
        horero++;
        tiempo();
        //tiempoS();
        EEPROM.write(2, horero);

      }
      else {
        horero = 0;
        tiempo();
        //tiempoS();
      }
    }
  }
}
//************************METODO DE RELOJ PARA VISUALIZAR EN LCD************************
void tiempo() {
  if (segundero < 10) {
    lcd.clear();
    lcd.setCursor(11, 0);
    lcd.print("0");
    lcd.setCursor(12, 0);
    lcd.print(segundero);
  } else {
    lcd.clear();
    lcd.setCursor(10, 0);
    lcd.print(':');
    lcd.setCursor(11, 0);
    lcd.print(segundero);
  }
  if (minutero < 10) {
    lcd.setCursor(7, 0);
    lcd.print(':');
    lcd.setCursor(8, 0);
    lcd.print("0");
    lcd.setCursor(9, 0);
    lcd.print(minutero);
    lcd.setCursor(10, 0);
    lcd.print(':');
  } else {
    lcd.setCursor(7, 0);
    lcd.print(':');
    lcd.setCursor(8, 0);
    lcd.print(minutero);
    lcd.setCursor(10, 0);
    lcd.print(':');
  }
  if (horero < 10) {
    lcd.setCursor(5, 0);
    lcd.print("0");
    lcd.setCursor(6, 0);
    lcd.print(horero);
    lcd.setCursor(7, 0);
    lcd.print(':');
  } else {
    lcd.setCursor(5, 0);
    lcd.print(horero);
    lcd.setCursor(7, 0);
    lcd.print(':');
  }
}
//************************METODO DE RELOJ PARA VISUALIZAR EN CX SERIAL************************
void tiempoS() {
  Serial.print(horero);
  Serial.print(':');
  Serial.print(minutero);
  Serial.print(':');
  Serial.print(segundero);
  Serial.println(" ");
}
