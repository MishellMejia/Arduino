//Mishel Mejia-Ciercom 6"A"- Sistemas Microprocesados

// Declarar variables de los pines del arduino
int A= 13;
int B=12;
int C=11;
int D=10;
int unidades=7;
int decenas=8;
int centenas=9;
int valor_centena;
int valor_decena;
int valor_unidad;
int contador=0;

void setup() {
//declarar el estado de los pines del arduino en este caso todos los pines se han declarado como salida
pinMode (A,OUTPUT);//BIT MAS SIGNIFICATIVO
pinMode (B,OUTPUT);
pinMode (C,OUTPUT);     
pinMode (D,OUTPUT);//BIT MENOS SIGNIFICATIVO
pinMode (unidades, OUTPUT);
pinMode (decenas, OUTPUT);
pinMode (centenas, OUTPUT);
}

void loop() {
  
  for (;contador<999; contador++){// este for limita el numero al que llegará nuestros display
    valor_centena= contador/100;
    valor_decena= (contador/10)-(valor_centena*10); // el contador de decenas hasta el 9 será 0 porque la division es con (/) y de tipo int. Una vez que llegue al 10 empezará a salir 1, y cuando llegue al 20 2 y asi sucesivamente
    valor_unidad= (contador -((valor_centena*100)+(valor_decena*10))); // cálculo para las unidades
    //como arduino lee linea por linea en este caso por la multiplexación se prenderan las unidades,decenas y centenas en tiempos diferentes aunque el ojo humano no lo notará porque ocurre muy rapido
    digitalWrite (unidades, HIGH);
    digitalWrite (decenas, LOW);
    digitalWrite (centenas, LOW);
    //Imprimir dato
    contador_display (valor_unidad);// para imprimir ese parametro
    delay (100);
    digitalWrite (unidades, LOW);
    digitalWrite (decenas, HIGH);
    digitalWrite (centenas, LOW);
    //imprimir dato
     contador_display (valor_decena);// para imprimir ese parametro
      delay (100);
    digitalWrite (unidades, LOW);
    digitalWrite (decenas, LOW);
    digitalWrite (centenas, HIGH);
    //imprimir dato
     contador_display (valor_centena);// para imprimir ese parametro
      delay (100);
    }
 
    
    }

void contador_display(int numero)// en int numero se almacena decena y unidad
{// switch para evaluar los diferentes casos
  switch (numero) {
  // En esta parte se realiza los diferentes numeros del 0 al 9 que se observaran en los displays, como se puede ver estan en binario.
  // D es el bit menos siginificativo y A el bit mas siginificativo (DCBA)  
   case 0:  
  //0, el cero en binario  es 0000 
   digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 1:
  //1 el uno en binario es 0001
   digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 2:
  //2 el dos en binario es 0010
   digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 3:
  //3  el tres en binario es 0011
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 4:
  
  //4  el cuatro en binario es 0100
   digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 5:
  //5   el cinco en binario es 0101
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 6:
  //6 el seis en binario es 0110
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 7:
  //7 el siete en binario es 0111
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 8:
  //8 el ocho en binario es 1000
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
    break;
    case 9:
  //9  el nueve en binario es 1001
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
break;
  }
  }

