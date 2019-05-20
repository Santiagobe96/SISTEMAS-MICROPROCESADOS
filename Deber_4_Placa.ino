/*
   UNIVERSIDAD TÉCNICA DEL NORTE
   FICA - CIERCOM
   NOMBRE: SANTIAGO BOLAÑOS
   CURSO: 6to "A"
   FECHA: 19/05/2019
   TEMA: Valide la cédula ecuatoriana que se ingresa por comunicación serial con el Formato. 100124578-9
*/
String Placa;
String dato1;
String Cadena1;
String Cadena2;
int TamPlaca = 7;

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese su placa en el formato ABC-0123");
  Serial.println(" ");
}

void loop() {

  if (Serial.available() > 0 ) {
    dato1 = Serial.readString();
    dato1.toUpperCase();
    Serial.println(" ");
    Cadena1 = dato1.substring(0, dato1.indexOf("-"));
    Cadena2 = dato1.substring(dato1.indexOf("-") + 1, dato1.length());
    Placa = (Cadena1 + Cadena2);

    if (Placa.length() == TamPlaca) {  // si la longitud de la cedula es igual al tamaño 10 sigue el proceso
      if (Cadena2.substring(3, 4) != "0" && Cadena2.substring(3, 4) != "1" && Cadena2.substring(3, 4) != "2" &&
          Cadena2.substring(3, 4) != "3" && Cadena2.substring(3, 4) != "4" && Cadena2.substring(3, 4) != "5" &&
          Cadena2.substring(3, 4) != "6" && Cadena2.substring(3, 4) != "7" && Cadena2.substring(4, 4) != "8" &&
          Cadena2.substring(3, 4) != "9") {

        if (Cadena2.substring(4, 5) != "0" && Cadena2.substring(4, 5) != "1" && Cadena2.substring(4, 5) != "2" &&
            Cadena2.substring(4, 5) != "3" && Cadena2.substring(4, 5) != "4" && Cadena2.substring(4, 5) != "5" &&
            Cadena2.substring(4, 5) != "6" && Cadena2.substring(4, 5) != "7" && Cadena2.substring(4, 5) != "8" &&
            Cadena2.substring(4, 5) != "9") {

          if (Cadena2.substring(5, 6) != "0" && Cadena2.substring(5, 6) != "1" && Cadena2.substring(5, 6) != "2" &&
              Cadena2.substring(5, 6) != "3" && Cadena2.substring(5, 6) != "4" && Cadena2.substring(2, 3) != "5" &&
              Cadena2.substring(5, 6) != "6" && Cadena2.substring(5, 6) != "7" && Cadena2.substring(2, 3) != "8" &&
              Cadena2.substring(5, 6) != "9") {

            if (Cadena2.substring(6, 7) != "0" && Cadena2.substring(6, 7) != "1" && Cadena2.substring(6, 7) != "2" &&
                Cadena2.substring(6, 7) != "3" && Cadena2.substring(6, 7) != "4" && Cadena2.substring(6, 7) != "5" &&
                Cadena2.substring(6, 7) != "6" && Cadena2.substring(6, 7) != "7" && Cadena2.substring(6, 7) != "8" &&
                Cadena2.substring(6, 7) != "9") {

              if (Cadena1.substring(0, 1) == "A") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "B") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Bolivar");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Bolivar");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Bolivar");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Bolivar");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Bolivar");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "C") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Carchi");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Carchi");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Carchi");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Carchi");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Carchi");
                  Serial.println("y su vehiculo es privado");
                }
              }
              else {
                Serial.print(" jajaj");
              }
              if (Cadena1.substring(0, 1) == "X") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z") {
                  Serial.println("Su placa pertenece a Cotopaxi");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Cotopaxi");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Cotopaxi");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Cotopaxi");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Cotopaxi");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "H") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Chimborazo");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Chimborazo");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Chimborazo");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Chimborazo");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Chimborazo");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "O") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a El Oro");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a El Oro");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a El Oro");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Azuay");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a El Oro");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "E") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Esmeraldas");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Esmeraldas");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Esmeraldas");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Esmeraldas");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Esmeraldas");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "W") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a Galapagos");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Galapagos");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Galapagos");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Galapagos");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Galapagos");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "G") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Guayas");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Guayas");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Guayas");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Guayas");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Guayas");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "I") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a Imbabura");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Imbabura");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Imbabura");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Imbabura");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Imbabura");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "L") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Loja");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Loja");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Loja");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Loja");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Loja");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "R") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Los Rios");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Los Rios");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Los Rios");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Los Rios");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Los Rios");
                  Serial.println("y su vehiculo es privado");
                }
              }
              if (Cadena1.substring(0, 1) == "M") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Manabi");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Manabi");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Manabi");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Manabi");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Manabi");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "V") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Morona Santiago");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Morona Santiago");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Morona Santiago");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Morona Santiago");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Morona Santiago");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "N") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Napo");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Napo");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Napo");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Napo");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Napo");
                  Serial.println("y su vehiculo es privado");
                }
              }
              
              if (Cadena1.substring(0, 1) == "S") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Pastaza");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Pastaza");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Pastaza");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Pastaza");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Pastaza");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "P") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Pichincha");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Pichincha");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Pichincha");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Pichincha");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Pichincha");
                  Serial.println("y su vehiculo es privado");
                }
              }
              
              if (Cadena1.substring(0, 1) == "Q") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Orellana");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Orellana");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Orellana");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Orellana");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Orellana");
                  Serial.println("y su vehiculo es privado");
                }
              }
              
              if (Cadena1.substring(0, 1) == "K") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Sucumbios");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Sucumbios");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Sucumbios");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Sucumbios");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Sucumbios");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "T") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a Tungurahua");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Tungurahua");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Tungurahua");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Tungurahua");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Tungurahua");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "Z") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z" ) {
                  Serial.println("Su placa pertenece a Zamora Chimchipe");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Zamora Chimchipe");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Zamora Chimchipe");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Zamora Chimchipe");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Zamora Chimchipe");
                  Serial.println("y su vehiculo es privado");
                }
              }
           
              if (Cadena1.substring(0, 1) == "Y") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a Santa Elena");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Santa Elena");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Santa Elena");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Santa Elena");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Santa Elena");
                  Serial.println("y su vehiculo es privado");
                }
              }
             
              if (Cadena1.substring(0, 1) == "J") {
                if (Cadena1.substring(1, 2) == "A" || Cadena1.substring(1, 2) == "U" ||
                    Cadena1.substring(1, 2) == "Z"  ) {
                  Serial.println("Su placa pertenece a Santo Domingo");
                  Serial.println("y su vehiculo es de uso comercial");
                }
                else if (Cadena1.substring(1, 2) == "E") {
                  Serial.println("Su placa pertenece a Santo Domingo");
                  Serial.println("y su vehiculo es de uso gubernamental");
                }
                else if (Cadena1.substring(1, 2) == "X") {
                  Serial.println("Su placa pertenece a Santo Domingo");
                  Serial.println("y su vehiculo es de uso oficial");
                }
                else if (Cadena1.substring(1, 2) == "M") {
                  Serial.println("Su placa pertenece a Santo Domingo");
                  Serial.println("y su vehiculo es de uso no gumernamental");
                }
                else {
                  Serial.println("Su placa pertenece a Santo Domingo");
                  Serial.println("y su vehiculo es privado");
                }
              }

            }
            else {
              Serial.println("Placa INCORRECTA, Verifique que su placa tenga los numeros y letras correctos");
            }
          }
          else {
            Serial.println("Placa INCORRECTA, Verifique que su placa tenga los numeros y letras correctos");
          }
        }
        else {
          Serial.println("Placa INCORRECTA, Verifique que su placa tenga los numeros y letras correctos");
        }
      }
      else {
        Serial.println("Placa INCORRECTA, Verifique que su placa tenga los numeros y letras correctos");
      }

    }
    else if (Placa.length() < TamPlaca) { //si la longitud de la cedula es menor al tamaño 7 envia un mensaje para volver a escribir la cedula
      Serial.println("");
      Serial.print("Su placa: ");
      Serial.print(dato1);
      Serial.println(" es INCORECTA, por favor vuelva");
      Serial.println("a ingresar su placa");
      Serial.println(" ");
      delay(200);

    }
    else if (Placa.length() > TamPlaca) { //si la longitud de la cedula es mayor al tamaño 7 envia un mensaje para volver a escribir la cedula
      Serial.println("");
      Serial.print("Su placa: ");
      Serial.print(dato1);
      Serial.println(" es INCORRECTA, por favor vuelva");
      Serial.println("a ingresar su placa ");
      Serial.println(" ");
      delay(200);
    }
  }
}
