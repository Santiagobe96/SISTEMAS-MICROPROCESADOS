/*
                    UNIVERSIDAD TECNICA DEL NORTE
                              CIERCOM
   Nombre:      Bolaños Santiago
   Asignatura:  Sistemas Microprocesados
   Actividad:   Deber 02_Segundo Bimestre
   Tema:        Realizar un programa de seguridad domótica que permita encender las luces de un domicilio de 5 habitaciones
                de forma aleatoria solo en horario nocturno. El sistema se activa al ingresar una contraseña por comunicación serial
*/

#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

//****************DECLARACION DE VARIABLES*****************
int segundero = 0; // variable para segundero
int minutero = 0;// variable para minutero
int horero = 0;// variable para horero
int funcion = 0;// variable para llamar a la peticion de pass
int i;// variable para asignar valor aleatorio de los leds
String pass;// variable para pass por Cx serial
boolean validar;// variable para validar pass


void setup() {
  //******************INTERRUPCIONES*****************
  Serial.begin(9600);
  attachInterrupt(0, funcionamiento, FALLING);
  Timer1.initialize(1000000); //tiempo de 1 segundo
  Timer1.attachInterrupt(reloj);//interrupcion del Timer1
  Timer1.stop();
  lcd.begin(16, 2);
  //*pines de los leds
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(23, OUTPUT);
  //*
}

void loop() {
  //*********************VALIDACION DE PASS*******************
  if (funcion == 1) {
    if (Serial.available() > 0) {
      pass = Serial.readString();
      if (pass.length() != 4) {//verificacion del tamaño del pass
        //**********la comunicacion es serial, y solamente la verificacion es además vista por lcd**********************
        Serial.println(" ");
        Serial.println("PASS INVALIDO");
        Serial.println(" ");
        lcd.setCursor(0, 1);
        lcd.print("PASS INVALIDO");
        delay(1000);
        lcd.clear();
      }
      else {
        validar = pass.equals("QWER");
        if (validar == true) {//si  la clave es valida se visualiza en lcd y Cx serial
          Serial.println(" ");
          Serial.println("PASS VALIDO");
          Serial.println(" ");
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("PASS VALIDO");// una vez que se valida la clave se inicializa el Timer1
          Timer1.start();
          delay(1000);
          lcd.clear();
        }
        else {
          Serial.println(" ");
          Serial.println("PASS INVALIDO");
          Serial.println(" ");
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print("PASS INVALIDO");
          delay(1000);
          lcd.clear();
        }
      }
    }
  }
}
//***************INTERRUPCION DEL PULSADOR PARA PASS********************
void funcionamiento() {
  switch (funcion) {
    case 0:
      Serial.println("SISTEMA INICIADO");
      Serial.println("INGRESE PASS");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SIS. INICIADO");
      lcd.setCursor(0, 1);
      lcd.print("INGRESE PASS");
      funcion++;
      break;
  }
}
//*****************INTERRUPCION DEL TIMER1**************
void reloj() {

  if (segundero < 59) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
    segundero++;
    Serial.print(horero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.print(segundero);
    Serial.println(" ");
  }
  else {
    segundero = 0;
    if (minutero < 59) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
      minutero++;
      Serial.print(horero);
      Serial.print(':');
      Serial.print(minutero);
      Serial.print(':');
      Serial.print(segundero);
      Serial.println(" ");
    }
    else {
      minutero = 0;
      if (horero < 23) {// la condicion debe ser menor que 23, debido a que al ser i=0, imprime el valor de 1 en el reloj
        horero++;
        Serial.print(horero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.print(segundero);
        Serial.println(" ");
      }
      else {
        horero = 0;
        Serial.print(horero);
        Serial.print(':');
        Serial.print(minutero);
        Serial.print(':');
        Serial.print(segundero);
        Serial.println(" ");
      }
    }
  }
  //*********** LOS LEDS SE ENCIENDEN ALEATORIAMENTE EN EL HORARIO DE 0AM a 6AM Y DE 7PM A 12PM******************
  if (((horero >= 19 && horero <= 23) || (horero >= 0 && horero <= 5)) && (minutero >= 0 && minutero <= 59)  && (segundero >= 0 && segundero <= 59)) {
    i = random(23, 28);//se asigna a la variable i un numero aleatorio de leds y se encienden
    digitalWrite (i, HIGH);
    delay (10000);
  } if (((horero >= 19 && horero <= 23) || (horero >= 0 && horero <= 5)) && (minutero >= 0 && minutero <= 59)  && (segundero >= 0 && segundero <= 59)) {
    i = random(23, 28);//se asigna a la variable i un numero aleatorio de leds y se apagan
    digitalWrite (i, LOW);
    delay (1000);
  } else {// y en el caso de que sea cualqueir otro horario que no sea nocturno, todos los leds se apagan
    digitalWrite (23, LOW);
    digitalWrite (24, LOW);
    digitalWrite (25, LOW);
    digitalWrite (26, LOW);
    digitalWrite (27, LOW);
  }
}
