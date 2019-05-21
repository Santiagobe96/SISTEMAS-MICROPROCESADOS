/*
   UNIVERSIDAD TÉCNICA DEL NORTE
   FICA - CIERCOM
   NOMBRE: SANTIAGO BOLAÑOS
   CURSO: 6to "A"
   FECHA: 19/05/2019
   TEMA: Valide la placa ecuatoriana que se ingresa por comunicación serial con el Formato. ABC-0123
*/
String placa;
char VectorPlaca[8];

void setup() {
  Serial.begin(9600);
  Serial.println("Ingrese su placa en el formato ABC-0123");
  Serial.println(" ");
}

void loop() {

  if (Serial.available() > 0) {
    placa = Serial.readString();
    if (placa.length() == 7) {
      placa = placa.substring(0, 4) + "0" + placa.substring(4, 8);
    }

    for (int i = 0; i < placa.length(); i++) {
      VectorPlaca[i] = placa.charAt(i);
    }

    if (VectorPlaca[0] >= 'A' && VectorPlaca[0] <= 'Z') {
      if (VectorPlaca[1] >= 'A' && VectorPlaca[1] <= 'Z') {
        if (VectorPlaca[4] >= '0' && VectorPlaca[4] <= '9') {
          if (VectorPlaca[5] >= '0' && VectorPlaca[5] <= '9') {
            if (VectorPlaca[6] >= '0' && VectorPlaca[6] <= '9') {
              if (VectorPlaca[7] >= '0' && VectorPlaca[7] <= '9') {
                Serial.println(" ");
                Serial.print("su placa: ");
                Serial.println(placa);
                Provin(VectorPlaca[0]);
                TipoAuto(VectorPlaca[1]);
              }else {
                Serial.println(" ");
                Serial.print("su placa: ");
                Serial.println(placa);
                Serial.println("es INCORRECTA");
                Serial.println("Por favor revise que los nuemros de su placa sean los ");
                Serial.println("correctos o no existan letras ingresadas despues del guion");
              }
            }else
            {
              Serial.println(" ");
              Serial.print("su placa: ");
              Serial.println(placa);
              Serial.println("es INCORRECTA");
              Serial.println("Por favor revise que los nuemros de su placa sean los ");
              Serial.println("correctos o no existan letras ingresadas despues del guion");
            }
          }else{
            Serial.println(" ");
            Serial.print("su placa: ");
            Serial.println(placa);
            Serial.println("es INCORRECTA");
            Serial.println("Por favor revise que los nuemros de su placa sean los ");
            Serial.println("correctos o no existan letras ingresadas despues del guion");
          }
        }else {
          Serial.println(" ");
          Serial.print("su placa: ");
          Serial.println(placa);
          Serial.println("es INCORRECTA");
          Serial.println("Por favor revise que los nuemros de su placa sean los ");
          Serial.println("correctos o no existan letras ingresadas despues del guion");
        }
      }else
      {
        Serial.println(" ");
        Serial.print("su placa: ");
        Serial.println(placa);
        Serial.println("es INCORRECTA");
        Serial.println("Por favor revise que las letras de su placa esten en ");
        Serial.println("mayusculas o no existan numeros ingresados antes del guion");
      }
    }else{
      Serial.println(" ");
      Serial.print("su placa: ");
      Serial.println(placa);
      Serial.println("es INCORRECTA");
      Serial.println("Por favor revise que las letras de su placa esten en ");
      Serial.println("mayusculas o no existan numeros ingresados antes del guion");
    }
  }
}
void Provin(char P) {
  switch (P) {
    case 'A':
      Serial.println("Pertence a la provincia Azuay");
      break;
    case 'B':
      Serial.println("Pertence a la provincia Bolivar");
      break;
    case 'C':
      Serial.println("Pertence a la provincia Carchi");
      break;
    case 'X':
      Serial.println("Pertence a la provincia Cotopaxi");
      break;
    case 'H':
      Serial.println("Pertence a la provincia Chiborazo");
      break;
    case 'O':
      Serial.println("Pertence a la provincia El Oro");
      break;
    case 'E':
      Serial.println("Pertence a la provincia Esmeraldas");
      break;
    case 'W':
      Serial.println("Pertence a la provincia Galapagos");
      break;
    case 'G':
      Serial.println("Pertence a la provincia Guayas");
      break;
    case 'I':
      Serial.println("Pertence a la provincia Imbabura");
      break;
    case 'L':
      Serial.println("Pertence a la provincia Loja");
      break;
    case 'R':
      Serial.println("Pertence a la provincia Los Rios");
      break;
    case 'M':
      Serial.println("Pertence a la provincia Manabi");
      break;
    case 'V':
      Serial.println("Pertence a la provincia Morona Santiago");
      break;
    case 'N':
      Serial.println("Pertence a la provincia Napo");
      break;
    case 'S':
      Serial.println("Pertence a la provincia Pastaza");
      break;
    case 'P':
      Serial.println("Pertence a la provincia Pichincha");
      break;
    case 'Q':
      Serial.println("Pertence a la provincia Orellana");
      break;
    case 'K':
      Serial.println("Placa de la provincia Sucumbios");
      break;
    case 'T':
      Serial.println("Pertence a la provincia Tungurahua");
      break;
    case 'Z':
      Serial.println("Pertence a la provincia Zamora Chimchipe");
      break;
    case 'Y':
      Serial.println("Pertence a la provincia Santa Elena");
      break;
    case 'J':
      Serial.println("Pertence a la provincia Santo Domingo");
      break;
  }
}
void TipoAuto(char T) {
  switch (T) {
    case 'A':
      Serial.println("Su vehiculo es de uso comercial");
      break;
    case 'U':
      Serial.println("Su vehiculo es de uso comercial");
      break;
    case 'Z':
      Serial.println("Placa de la provincia Bolivar");
      break;
    case 'E':
      Serial.println("Su vehiculo es de uso gumernamental");
      break;
    case 'X':
      Serial.println("Su vehiculo es de uso oficial");
      break;
    case 'M':
      Serial.println("Su vehiculo es de uso no gumernamental");
      break;
    default:
      Serial.println("Su vehiculo es de uso privado");
      break;
  }
}
