//Mishel Mejia-Ciercom 6"A"- Sistemas Microprocesados

//declarar variables de pines arduino
int A= 13;//bit mas siginificativo
int B=12;
int C=11;
int D=10;//bit menos significativo
int unidades=9;
int decenas=8;
int pulsador=7;
//declar variables parametricas
int valor_decena;
int valor_unidad;
// variable contador inicializada en 0
int contador=0;

void setup() {
// declarar el estado de los pines del arduino, en este caso todos se han puesto como salidas
pinMode (A,OUTPUT);//BIT MAS SIGNIFICATIVO
pinMode (B,OUTPUT);
pinMode (C,OUTPUT);     
pinMode (D,OUTPUT);//BIT MENOS SIGNIFICATIVO
pinMode (unidades, OUTPUT);
pinMode (decenas, OUTPUT);
pinMode (pulsador, INPUT);
}

void loop() {
 
 if (digitalRead(pulsador)==HIGH){//condicion para que cuando el pulsador este en alto el contaodr aumente en uno.
  
 contador++;
 if(contador==100){contador=0;}}// condición para que cuando el contador llegue a 99 se vuelva a inicializar en 0 despues de este.
 
    valor_decena= contador/10;// Cálculo de las decenas
    valor_unidad= (contador -(valor_decena*10));//Cálculo para las unidades
    //Multiplexacion
    digitalWrite (unidades, HIGH);
    digitalWrite (decenas, LOW);
    //Imprimir dato
    contador_display (valor_unidad);// para imprimir ese parametro
    delay (100);
    digitalWrite (unidades, LOW);
    digitalWrite (decenas, HIGH);
    //imprimir dato
     contador_display (valor_decena);// para imprimir ese parametro
      delay (100);
 
}
void contador_display(int numero)// en int numero se almacena decena y unidad
{ // En esta parte se realiza los diferentes numeros del 0 al 9 que se observaran en los displays, como se puede ver estan en binario.
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

