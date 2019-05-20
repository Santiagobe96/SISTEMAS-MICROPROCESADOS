/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
   FICA - CIERCOM
   NOMBRE: SANTIAGO BOLAÑOS
   CURSO: 6to "A"
   FECHA: 19/05/2019
   TEMA: Valide la cédula ecuatoriana que se ingresa por comunicación serial con el Formato. 100124578-9 
  */
String cedula;
String dato1;
String Cadena1;
String Cadena2;
int Vector [] = {2, 1, 2, 1, 2, 1, 2, 1, 2};  //coeficientes para realizar la verificaciòn
int dato2 = 0;
int total = 0;
int val=0;
int TamCedula = 10;
int NumProvin = 24;
int TercerDigito = 6;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese su numero de cedula en el formato 012345678-9");
  Serial.println(" ");
}

void loop() {
   
  if(Serial.available()>0 ){
  dato1=Serial.readString();
  Serial.println(" ");
  Cadena1=dato1.substring(0,dato1.indexOf("-"));  
  Cadena2=dato1.substring(dato1.indexOf("-")+1,dato1.length()); 
  cedula=(Cadena1+Cadena2);

  if (cedula.length() == TamCedula) {  // si la longitud de la cedula es igual al tamaño 10 sigue el proceso        
    int Provin = (cedula.substring(0,2)).toInt(); 
    int DigTres = (cedula.substring(2,3)).toInt();  
               
    if ((Provin > 0 && Provin <= NumProvin) && DigTres < TercerDigito) {  
      int DigVeriRecibido = (cedula.substring(9,10)).toInt();
        for (int i = 0; i < 9; i++) {
          val = Vector[i] * (cedula.substring(i,i+1)).toInt();
          total = val >= 10 ? total + (val - 9) : total + val;
        }

      int DigVeriObtenido = (total % 10) > 0 ? 10 - (total % 10) : (total % 10);
        if (DigVeriObtenido == DigVeriRecibido) {
          Serial.print("El numero de cedula: ");
          Serial.print(dato1);
          Serial.println(" es CORRECTO");
          Serial.println(" ");
          delay(200);
          dato2 = -1;
        } 
        else {
          Serial.print("El numero de cedula: ");
          Serial.print(dato1);
          Serial.println(" es INCORRECTO, por favor vuelva");
          Serial.println("a ingresar su numero de cedula"); 
          Serial.println(" ");
          delay(200);
        }  
    } 
    else{
          Serial.print("El numero de cedula: ");
          Serial.print(dato1);
          Serial.println(" es INCORRECTO,  por favor vuelva"); 
          Serial.println("a ingresar su numero de cedula"); 
          Serial.println(" ");
          delay(200);
    }
  } 
  else if (cedula.length() < TamCedula) { //si la longitud de la cedula es menor al tamaño 10 envia un mensaje para volver a escribir la cedula
    Serial.println("");
    Serial.print("El numero de cedula: "); 
    Serial.print(dato1);
    Serial.println(" es INCORECTO, por favor vuelva");
    Serial.println("a ingresar su numero de cedula"); 
    Serial.println(" ");
    delay(200);

  }
  else if (cedula.length() > TamCedula) { //si la longitud de la cedula es mayor al tamaño 10 envia un mensaje para volver a escribir la cedula
    Serial.println("");    
    Serial.print("El numero de cedula: "); 
    Serial.print(dato1);
    Serial.println(" es INCORRECTO, por favor vuelva");
    Serial.println("a ingresar su numero de cedula"); 
    Serial.println(" ");
    delay(200);
  } 
  }
  total=0;
  val=0;
}
