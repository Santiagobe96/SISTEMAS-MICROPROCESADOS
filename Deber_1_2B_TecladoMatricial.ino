/*
                      UNIVERSIDAD TECNICA DEL NORTE
                              CIERCOM
   Nombre:      Bolaños Santiago
   Asignatura:  Sistemas Microprocesados
   Actividad:   Deber 01_Segundo Bimestre
   Tema:        Consultar funcionamiento teclado matricial y validar contraseña de 4 digitos
*/

#include <Keypad.h> // se incluye la libreria Keypad
#include <LiquidCrystal.h> //se incluye la libreria LiquidCrystal

LiquidCrystal lcd(13, 12, 11, 10, 9, 8); //se define los pines del lcd

const byte fil = 4; // define numero de filas
const byte col = 4; // define numero de columnas

char TECLAS[fil][col] = { // define la distribucion de teclas
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFil[fil] = {22, 23, 24, 25}; // pines correspondientes a las filas
byte pinesCol[col] = {26, 27, 28}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(TECLAS), pinesFil, pinesCol, fil, col); // crea objeto "teclado" de tipo keypad, y se craga todos los valores asigados al mapa

char tecla; // almacena la tecla presionada
char claveAlmacenar[5]; // almacena en un array 4 digitos ingresados
char claveOriginal[5] = "0000"; // almacena en un array la contraseña maestra
byte Posicion = 0; // indice del array
int ledRojo = 41; //pin de salida led rojo
int ledVerde = 40; //pin de salida del verde

void setup()
{
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, LOW);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO");
  lcd.setCursor(0, 1);
  lcd.print("INGRESE SU CLAVE");
}
void loop() {

  tecla = teclado.getKey(); // se obtiene tecla el caaracter de la tecla presionada y asigna a variable
  if (tecla) // comprueba que se haya presionado un boton del teclado
  {
    claveAlmacenar[Posicion] = tecla; // almacena en array la tecla presionada
    Posicion++; // incrementa indice en uno
    Serial.print(tecla); // envia a monitor serial la tecla presionada
    //*************************************//
    //lo que se hace a continaucion es solamente por estetica del sistema
    //cada vez que se presiona una tecla, se muestra un "*" en el lcd
    // es decir que all final de ingresar los 4 digitos, el lcd mostrara 4 asteriscos
    if (Posicion == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SU CLAVE: ");
      lcd.setCursor(0, 1);
      lcd.print("*");
    }
    if (Posicion == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SU CLAVE: ");
      lcd.setCursor(0, 1);
      lcd.print("**");
    }
    if (Posicion == 3) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SU CLAVE: ");
      lcd.setCursor(0, 1);
      lcd.print("***");
    }
  }
  //**************************************
  // la siguiente condicion valida que una vez que se ha ingresado los 4 digitos y la posicion actual es 4
  //se establece la condicion para que posteriormente realice el proceso de verificar la clave
  if (Posicion == 4) // si ya se almacenaron los 4 digitos
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SU CLAVE: ");
    lcd.setCursor(0, 1);
    lcd.print("****");

    if (!strcmp(claveAlmacenar, claveOriginal)) { //compara clave ingresada con clave original
      Serial.println(" ");
      Serial.println("CLAVE CORRECTA"); //imprime en monitor serial que es correcta la clave

      //***********************
      //lo siguinete es para que si la clave es correcta, se activa el led verde por 0,5 segundos 
      // y ademas se muestra el mensaje de verificacion y se espera 0,5 segundos para volver a la panalla de inicio en el lcd 
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CLAVE VALIDA");
      delay(500);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BIENVENIDO");
      lcd.setCursor(0, 1);
      lcd.print("INGRESE SU CLAVE");
    }
    else {
      Serial.println(" ");
      Serial.println("CLAVE INCORRECTA"); //imprime en monitor serial que es incorrecta la clave

      //***********************
      //lo siguinete es para que si la clave es incorrecta, se muestra el error y se espera 0,5 segundos para volver a la panalla de inicio en el lcd 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("CLAVE INVALIDA");
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BIENVENIDO");
      lcd.setCursor(0, 1);
      lcd.print("INGRESE SU CLAVE");
    }
    Posicion = 0;//resetea la posicion para que limpie la variable y pueda repetir el ciclo el sistema
  }
}
