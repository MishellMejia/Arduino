 /*      2 JUEGOS DE 6 LUCES EMPLEANDO CICLOS FOR 
 * 
 * Este programa consta de 2 juegos de luces con 6 leds.
 *  
 * NOMBRE: Mishel Mejía
 * FECHA DE ENTREGA: 27/10/2016
 */


// declarar Variables Globales
int sw_1=7; //switch 1
int sw_2=6; //switch 2


void setup() {
  //Poner la funcion de los pines
  pinMode(8,OUTPUT); //pin 8 como salida
  pinMode(9,OUTPUT); //pin 9 como salida
  pinMode(10,OUTPUT); //pin 10 como salida
  pinMode(11,OUTPUT); //pin 11 como salida
  pinMode(12,OUTPUT); //pin 12 como salida
  pinMode(13,OUTPUT); //pin 13 como salida
  pinMode(sw_1,INPUT); //pin 7 como entrada
  pinMode(sw_2,INPUT); //pin 6 como entrada

}

void loop() {

  luces_1 ();// llamar clase luces_1
  luces_2 ();//llamar clase luces_2
 
     
}

void luces_1 ()// FOR RANDOMICO
{
   int  leds [6]={8,9,10,11,12,13}; // declara vector
   int j; //variable de for1 tipo int
   int lim=0; //variable limite que contendra el random
   int contador=0;// variable for2
      delay(200);//retardo
      lim=random(6);// variable que guarda el limite del random de 0 a 6
         if(digitalRead(sw_1)==HIGH&&digitalRead(sw_2)==LOW){ //condicion para que se efectue el for randomico
           for(j=0;j<=lim;j++){//for 1 este for decidira el número de veces que se repite el for 2
              for(;contador<6;contador++)// for2 el numero del contador será la limitacion de posiciones del ciclo for
   { 
    digitalWrite (leds[contador],HIGH);// en la posicion contador es decir 0 se le dara un valor alto es la primera luz que saldra. Esta variable aumentará en uno cuando se acabe el ciclo for2
    digitalWrite (leds[contador-2],HIGH); //En la posicion contador -2 se le dara un valor alto, esta estará retardada de la anterior en dos posiciones pues arduino lee linea a linea, variara segun aumente el contador
       delay(300); //retardo
    digitalWrite (leds[contador],LOW); // el contador se encuentra en estado bajo es decir en un tiempo de 300ms la posicion que arriba se encontraba en alto pasara a bajo
    digitalWrite (leds[contador-2],LOW); //el contador-2 se encuentra en estado bajo es decir en un tiempo de 300ms la posicion que arriba se encontraba en alto pasara a bajo
    delay (300);//retardo
   }contador=0;// inicializa la variable en 0, fin for 2
              }//for 1    
              delay(2500);//(ATENCION)Tiempo de espera antes de empezar la siguiente secuencia que generará el for randómico.
                         //El ciclo no termina despues de la primera secuencia es decir las luces no se apagara, se espera 2500 ms para la siguiente secuencia que se repetira un numero de veces distinto al primero segun lo decida el for
            } //Final juego de luces 1 
           
  }

  void luces_2 ()// GENERAR UN JUEGO DE LUCES QUE VAYA DESDE LOS EXTREMS HASTA EL CENTRO Y LUEGO REBOTE DEL CENTRO HACIA LOS EXTREMOS
  
  { int leds [6]={8,9,10,11,12,13};// declara vector
    int j;//variable de for1 tipo int
    int lim=0;//variable limite que contendra el random
     if(digitalRead(sw_1)==LOW&&digitalRead(sw_2)==HIGH){//condicion para que se efectue el for randomico
           delay(200);// retardo
           lim=random(6);//variable que contiene el random de 0 a 6
           for(j=0;j<=lim;j++){//for 1 este for decidira el número de veces que se repite el for 2
            int contador1=0;
              for(;contador1<=6;contador1++)//  for 2 el numero del contador será la limitacion de posiciones del vector en el ciclo for
                   { 
                   digitalWrite (leds[5-contador1],HIGH); digitalWrite (leds[contador1],HIGH);//en la posicion 5 el contador que es el que varia habrá un estado alto
                   delay (200);
                   digitalWrite (leds[5-contador1],LOW); digitalWrite (leds[contador1],LOW);//en la posicion del contador que es la variable que ira aumentando tambien estara en alto al mismo tiempo que arriba porque no hay un delay
                   delay(200);//retardo
                   }contador1=0;// inicializa la variable en 0
                              }//for 1    
              delay(2500);//(ATENCION)Tiempo de espera antes de empezar la siguiente secuencia que generará el for randómico.
                         //El ciclo no termina despues de la primera secuencia se espera el tiempo de 2500 ms para la siguiente secuencia que se repetira un numero de veces distinto al primero segun lo decida el for
            } //Final juego de luces 2 
           }
