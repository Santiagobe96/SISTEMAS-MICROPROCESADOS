/*
                    UNIVERSIDAD TECNICA DEL NORTE
                              CIERCOM
   Nombre:      Bolaños Santiago
   Asignatura:  Sistemas Microprocesados
   Actividad:   Deber 05_Segundo Bimestre
   Tema:        Realizar un sistema que permita en intervalos de tiempo  (puede ser cada 2 segundos)
                establecidos dormir al sistema y levantarse para lecturas de un conversor análogo digital. 
                Toma la lectura, la envía por comunicación serial y se vuelve a dormir.
*/
//*************LIBRERIAS USADAS*************
#include<avr/sleep.h>
#include<avr/power.h>
#include<avr/wdt.h>
#include <EEPROM.h>

//********DECLARACION DE VARIABLES*******
int dato;
int cad;
float tope;
int tope2;
void setup() {
  //****ALMACENA ESTADO DEL DATO EN MEMORIA*******
  //EEPROM.write(0, 0);
  dato = EEPROM.read(0);
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("          REINICIO DEL SISTEMA");

  //**********SI DATO=0 SE HABILITA EL MODO**********
  if (dato == 0) {
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0, 1);
    wdt_enable(WDTO_1S);
  } 

  //**********SI DATO=1 SE DESHABILITA EL MODO**********
  else {
    sleep_disable();
    EEPROM.write(0, 0);
    wdt_enable(WDTO_1S);
  }
}
void loop() {

  //**********SE ACTIVA EL MODO SLEEEP******************
  if (dato == 0) {
    Serial.println("--> SISTEMA APAGADO");
    sleep_mode();
    delay(100);
  } 

  //**********SE DESACTIVA EL MODO SLEEEP E IMPRIME POR CX SERIAL EL VALOR DEL DATO DEL CONVERSOR CAD******************
  else {
    Serial.println("--> SISTEMA ENCENDIDO");
    cad = analogRead(A0);
    tope = (cad * 5.0) /  1023.0;
    //tope2 = (int)tope;
    Serial.print("                Voltaje: ");
    Serial.println(tope);
    Serial.println(" ");
    delay(10000);
  }
}
