
//Mishel Mejia-Ciercom 6"A"- Sistemas Microprocesados

//declarar variables de los pines de arduino
int A=13;
int B=12;
int C=11;
int D=10;
int decenas=9;
int unidades=8;
int valor_decena;
int valor_unidad;
int contador=0;
int motor=3;
double valor_cad=0; // double porque el valor no sera entero

void setup() {
  // En esta parte se declara el estado de los pines
  pinMode(A,OUTPUT);// A declarado como salida(13)
  pinMode(B,OUTPUT);// B declarado como salida(12)
  pinMode(C,OUTPUT);// C declarado como salida(11)
  pinMode(D,OUTPUT);// D declarado como salida(10)
  pinMode(unidades,OUTPUT);// unidades declarado como salida(8)
  pinMode(decenas,OUTPUT);// decenas declarado como salida(9)
  pinMode(motor,OUTPUT);// motr declarado como salida(3)

}

void loop() {
  // put your main code here, to run repeatedly:
      valor_cad=analogRead(0);  // sirve paraa leer la señal analogica que envia el potenciometro. Es de 0 a 1023 porque el potenciometro es de 1k  porque k es 2 a la 10 entonces aproxima a 1023
                                // ESTRUCTURA: analogRead(pin  donde esta conectado el potenciometro)                                              
      valor_decena=(valor_cad/10.3)/10; //calculo para las decenas. 1023/99=10.3 (valor_cad/10.3 representa el contador) 1023 es el mayor numero que da el potenciometro y 99 es el mayor numero que da el display,este paso se realiza con el fin de convertir todo a la misma escala 
      valor_unidad=((valor_cad/10.3)-(valor_decena*10));//calculo para las unidades
 
      digitalWrite(unidades,HIGH);// el display de unidades estara en alto
      digitalWrite(decenas,LOW);//el display de decenas en bajo
      //imprimir dato
      contador_display(valor_unidad);
      delay(100);
      
      digitalWrite(unidades,LOW);//el display de unidades se encuentra en bajo
      digitalWrite(decenas,HIGH);// el display de decenas se encuentra en alto
      //imprimir dato
      contador_display(valor_decena);
      delay(100);
      analogWrite(motor,valor_cad/4);  //% de ciclo util de la señal 
      delay(1);

}


void contador_display(int numero){
  // En esta parte se realiza los diferentes numeros del 0 al 9 que se observaran en los displays, como se puede ver estan en binario.
  // D es el bit menos siginificativo y A el bit mas siginificativo (DCBA)
    switch(numero){

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



