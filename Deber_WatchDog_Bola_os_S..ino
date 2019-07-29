/*
                    UNIVERSIDAD TECNICA DEL NORTE
                              CIERCOM
   Nombre:      Bolaños Santiago
   Asignatura:  Sistemas Microprocesados
   Actividad:   Deber 04_Segundo Bimestre
   Tema:        Realizar un programa que reinicie el sistema al tener la hora 00:10:50. Cuando vuelva a funcionar, 
                deberá empezar con la hora 00:11:10. Es proceso se observa en una LCD.
*/
#include <LiquidCrystal.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include<avr/wdt.h>
#include <EEPROM.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

int dato;
int segundero = 0; // variable para segundero
int minutero = 0;// variable para minutero
int horero = 0;// variable para horero

void setup() {
  Serial.begin(9600);
  Serial.println("HOLA");
  //  EEPROM.write(0, 0);
  //  EEPROM.write(1, 0);
  //  EEPROM.write(2, 0);
  //  EEPROM.write(3, 0);
  dato = EEPROM.read(3);
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  //Timer1.initialize(5000000); //tiempo de 1 segundo
  //Timer1.attachInterrupt(reloj1);//interrupcion del Timer1
  //Timer1.stop();
  MsTimer2::set(1000, reloj);


  if (dato == 0) {
    MsTimer2::start();
    EEPROM.write(3, 1);

  } else {
    //Timer1.start();
    MsTimer2::start();
    Serial.println("ENCENDIDO NUEVAMENTE");
    EEPROM.write(3, 0);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
void reloj() {
  if (segundero < 59) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
    segundero++;
    tiempo();
    //tiempoS();
    EEPROM.write(0, segundero);
  }
  else {
    segundero = 0;
    if (minutero < 59) {// la condicion debe ser menor que 59, debido a que al ser i=0, imprime el valor de 1 en el reloj
      minutero++;
      tiempo();
      //tiempoS();
      EEPROM.write(1, minutero);
    }
    else {
      minutero = 0;
      if (horero < 23) {// la condicion debe ser menor que 23, debido a que al ser i=0, imprime el valor de 1 en el reloj
        horero++;
        tiempo();
        //tiempoS();
        EEPROM.write(2, horero);

      }
      else {
        horero = 0;
        tiempo();
        //tiempoS();
        EEPROM.write(2, horero);
      }
    }
  }

  if (minutero == 10 && segundero == 50) {
    lcd.noDisplay();
    wdt_enable(WDTO_8S);
  }
}
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
void tiempoS() {
  Serial.print(horero);
  Serial.print(':');
  Serial.print(minutero);
  Serial.print(':');
  Serial.print(segundero);
  Serial.println(" ");
}
