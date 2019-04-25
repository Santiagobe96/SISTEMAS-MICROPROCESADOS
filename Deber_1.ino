/*
   UNIVERSIDAD TÉCNICA DEL NORTE
   FICA - CIERCOM
   NOMBRE: SANTIAGO BOLAÑOS
   CURSO: 6to "A"
   FECHA: 24/04/2019
   TEMA: DEBER#1_realice 5 juegos de luces diferentes de 8 leds
   1.- Se encienden y se apaguen los leds pares (0,2,4,6)
   2.- Se encienden y se apaguen los leds inpares (1,3,5,7)
*/
int juego[8] = {0, 1, 2, 3, 4, 5, 6, 7}; //vector para la configuracion de encendido y apagado de los leds pares
int i = 0; //variable para recorrer los vectores

void setup() {
  //configuracion de los pines pares de manera grupal
  for (; i < 8; i++) {
    pinMode(juego[i], OUTPUT);
  }
  i = 0;
}
void loop() {//programacion en el bucle infinito para cada juego de luces

  //juego1
  for (i = 0; i < 8; i += 2) {
    digitalWrite(juego[i], HIGH);
    delay(60);
    digitalWrite (juego[i], LOW);
    delay(60);
  }
  i = 0;

  //juego2
  for (i = 1; i < 8; i += 2) {
    digitalWrite(juego[i], HIGH);
    delay(60);
    digitalWrite (juego[i], LOW);
    delay(60);
  }
  i = 0;

  //juego3
  for (i = 4; i < 8; i++) {
    digitalWrite(juego[i], HIGH);
    delay(60);
  }
  for (i = 0; i < 4; i++) {
    digitalWrite(juego[i], HIGH);
    delay(60);
  }
  for (i = 7; i >= 4; i--) {
    digitalWrite(juego[i], LOW);
    delay(20);
  }
  for (i = 3; i >= 0; i--) {
    digitalWrite(juego[i], LOW);
    delay(20);
  }
  i = 0;
  //juego4

  for (i = 0; i < 8; i++) {
    digitalWrite(juego[i], HIGH);
    digitalWrite(juego[7 - i], HIGH);
    delay(60);
    digitalWrite (juego[i], LOW);
    digitalWrite (juego[7 - i], LOW);
    delay(20);
  }
  i = 0;

  //juego5

  for (i = 0; i < 4; i++) {
    digitalWrite(juego[i], HIGH);
    digitalWrite(juego[7 - i], HIGH);
    delay(60);
  }
  for (i = 0; i < 8; i++) {
    digitalWrite (juego[i], LOW);
    //digitalWrite (juego[7 - i], LOW);
    delay(20);
  }

}
