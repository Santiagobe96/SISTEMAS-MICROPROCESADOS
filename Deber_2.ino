/*
   UNIVERSIDAD TÉCNICA DEL NORTE
   FICA - CIERCOM
   NOMBRE: SANTIAGO BOLAÑOS
   CURSO: 6a "A"
   FECHA: 05/05/2019
   TEMA: DEBER # 2_Realice un programa que mediante dos pulsadores 
   (operando 1 y operando 2) sumen su valor de veces 
   (hasta 25 cada uno)que han sido presionados. 
   Dicho valos se mostrará en displas 
   multiplexados al presionar un tercer pulsados.
*/
int on = 0;
int pul1 = 28;
int cont1 = 0;
int a1 = 24;
int b1 = 25;
int c1 = 26;
int d1 = 27;
int decenas1;
int unidades1;
int dec1 = 22;
int uni1 = 23;

int pul2 = 36;
int dec2 = 30;
int uni2 = 31;
int cont2 = 0;
int a2 = 32;
int b2 = 33;
int c2 = 34;
int d2 = 35;
int decenas2;
int unidades2;

int pul3 = 44;
int dec3 = 38;
int uni3 = 39;
int Sum = 0;
int a3 = 40;
int b3 = 41;
int c3 = 42;
int d3 = 43;
int decenas3;
int unidades3;
void setup() {
  pinMode(pul1, INPUT);
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(dec1, OUTPUT);
  pinMode(uni1, OUTPUT);

  pinMode(pul2, INPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(dec2, OUTPUT);
  pinMode(uni2, OUTPUT);

  pinMode(pul3, INPUT);
  pinMode(a3, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(dec3, OUTPUT);
  pinMode(uni3, OUTPUT);
}

void loop() {

  if (digitalRead(pul1) == LOW) {
    delay(100);// delay antirebote, software 200-500 y hardware 15-20 ms
    on = 1 - on;
    if (cont1 < 25)
      cont1++;
    else
      cont1 = 0;
  }
  decenas1 = cont1 / 10;
  unidades1 = cont1 - decenas1 * 10;
  digitalWrite(dec1, HIGH);
  digitalWrite(uni1, LOW);
  contador1(decenas1);
  delay(100);
  digitalWrite(dec1, LOW);
  digitalWrite(uni1, HIGH);
  contador1(unidades1);
  delay(100);

  if (digitalRead(pul2) == LOW) {
    delay(100);// delay antirebote, software 200-500 y hardware 15-20 ms
    on = 1 - on;
    if (cont2 < 25)
      cont2++;
    else
      cont2 = 0;
  }
  decenas2 = cont2 / 10;
  unidades2 = cont2 - decenas2 * 10;
  digitalWrite(dec2, HIGH);
  digitalWrite(uni2, LOW);
  contador2(decenas2);
  delay(100);
  digitalWrite(dec2, LOW);
  digitalWrite(uni2, HIGH);
  contador2(unidades2);
  delay(100);

  if (digitalRead(pul3) == LOW) {
    delay(100);// delay antirebote, software 200-500 y hardware 15-20 ms
    on=1-on;
    Sum = cont1 + cont2;
  }
    decenas3 = Sum / 10;
    unidades3 = Sum - decenas3 * 10;
    digitalWrite(dec3, HIGH);
    digitalWrite(uni3, LOW);
    suma(decenas3);
    delay(100);
    digitalWrite(dec3, LOW);
    digitalWrite(uni3, HIGH);
    suma(unidades3);
    delay(100);
    
  }

  void contador1 (int dato) { // no retorna nada, si esta ->(), no necesita
    switch (dato) {
      case 0:
        digitalWrite(a1, LOW);
        digitalWrite(b1, LOW);
        digitalWrite(c1, LOW);
        digitalWrite(d1, LOW);
        break;
      case 1:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, LOW);
        digitalWrite(c1, LOW);
        digitalWrite(d1, LOW);
        break;
      case 2:
        digitalWrite(a1, LOW);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, LOW);
        digitalWrite(d1, LOW);
        break;
      case 3:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, LOW);
        digitalWrite(d1, LOW);
        break;
      case 4:
        digitalWrite(a1, LOW);
        digitalWrite(b1, LOW);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        break;
      case 5:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, LOW);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        break;
      case 6:
        digitalWrite(a1, LOW);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        break;
      case 7:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, HIGH);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        break;
      case 8:
        digitalWrite(a1, LOW);
        digitalWrite(b1, LOW);
        digitalWrite(c1, LOW);
        digitalWrite(d1, HIGH);
        break;
      case 9:
        digitalWrite(a1, HIGH);
        digitalWrite(b1, LOW);
        digitalWrite(c1, LOW);
        digitalWrite(d1, HIGH);
        break;
    }
  }

  void contador2 (int dato1) { // no retorna nada, si esta ->(), no necesita
    switch (dato1) {
      case 0:
        digitalWrite(a2, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(c2, LOW);
        digitalWrite(d2, LOW);
        break;
      case 1:
        digitalWrite(a2, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(c2, LOW);
        digitalWrite(d2, LOW);
        break;
      case 2:
        digitalWrite(a2, LOW);
        digitalWrite(b2, HIGH);
        digitalWrite(c2, LOW);
        digitalWrite(d2, LOW);
        break;
      case 3:
        digitalWrite(a2, HIGH);
        digitalWrite(b2, HIGH);
        digitalWrite(c2, LOW);
        digitalWrite(d2, LOW);
        break;
      case 4:
        digitalWrite(a2, LOW);
        digitalWrite(b1, LOW);
        digitalWrite(c1, HIGH);
        digitalWrite(d1, LOW);
        break;
      case 5:
        digitalWrite(a1, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(c2, HIGH);
        digitalWrite(d2, LOW);
        break;
      case 6:
        digitalWrite(a2, LOW);
        digitalWrite(b2, HIGH);
        digitalWrite(c2, HIGH);
        digitalWrite(d2, LOW);
        break;
      case 7:
        digitalWrite(a2, HIGH);
        digitalWrite(b2, HIGH);
        digitalWrite(c2, HIGH);
        digitalWrite(d2, LOW);
        break;
      case 8:
        digitalWrite(a2, LOW);
        digitalWrite(b2, LOW);
        digitalWrite(c2, LOW);
        digitalWrite(d2, HIGH);
        break;
      case 9:
        digitalWrite(a2, HIGH);
        digitalWrite(b2, LOW);
        digitalWrite(c2, LOW);
        digitalWrite(d2, HIGH);
        break;
    }
  }
  void suma (int dat3) { // no retorna nada, si esta ->(), no necesita
    switch (dat3) {
      case 0:
        digitalWrite(a3, LOW);
        digitalWrite(b3, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(d3, LOW);
        break;
      case 1:
        digitalWrite(a3, HIGH);
        digitalWrite(b3, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(d3, LOW);
        break;
      case 2:
        digitalWrite(a3, LOW);
        digitalWrite(b3, HIGH);
        digitalWrite(c3, LOW);
        digitalWrite(d3, LOW);
        break;
      case 3:
        digitalWrite(a3, HIGH);
        digitalWrite(b3, HIGH);
        digitalWrite(c3, LOW);
        digitalWrite(d3, LOW);
        break;
      case 4:
        digitalWrite(a3, LOW);
        digitalWrite(b3, LOW);
        digitalWrite(c3, HIGH);
        digitalWrite(d3, LOW);
        break;
      case 5:
        digitalWrite(a3, HIGH);
        digitalWrite(b3, LOW);
        digitalWrite(c3, HIGH);
        digitalWrite(d3, LOW);
        break;
      case 6:
        digitalWrite(a3, LOW);
        digitalWrite(b3, HIGH);
        digitalWrite(c3, HIGH);
        digitalWrite(d3, LOW);
        break;
      case 7:
        digitalWrite(a3, HIGH);
        digitalWrite(b3, HIGH);
        digitalWrite(c3, HIGH);
        digitalWrite(d3, LOW);
        break;
      case 8:
        digitalWrite(a3, LOW);
        digitalWrite(b3, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(d3, HIGH);
        break;
      case 9:
        digitalWrite(a3, HIGH);
        digitalWrite(b3, LOW);
        digitalWrite(c3, LOW);
        digitalWrite(d3, HIGH);
        break;
    }
  }
