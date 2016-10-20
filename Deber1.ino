int contador=0; // declaracion de la variable contador inicializada con un valor de 0
int contador1=0;//declaracion de la variable contador1 inicializada con un valor de 0
int contador2=0;//declaracion de la variable contador2 inicializada con un valor de 0
int leds [14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13}; // declaracion de un vector
void setup() {  
  pinMode (0, OUTPUT);//pin 0 declarado como salida
   pinMode (1, OUTPUT);//pin 1 declarado como salida.
   pinMode (2,OUTPUT);//pin 2 declarado como salida.
   pinMode (3, OUTPUT);//pin 3 declarado como salida.
   pinMode (4,OUTPUT);//pin 4 declarado como salida.
   pinMode (5, OUTPUT);//pin 5 declarado como salida.
   pinMode (6,OUTPUT);//pin 6 declarado como salida.
   pinMode (7, OUTPUT);//pin 7 declarado como salida.
   pinMode (8, OUTPUT);//pin 8 declarado como salida.
   pinMode(9,OUTPUT);//pin 9 declarado como salida.
   pinMode (10, OUTPUT);//pin 10 declarado como salida.
   pinMode(11,OUTPUT);//pin 11 declarado como salida.
   pinMode (12, OUTPUT);//pin 12 declarado como salida.
   pinMode(13,OUTPUT);//pin 13 declarado como salida.
}

void loop() 
{
 luces1(); //llama a la clase luces1 ();
 delay(500);//tiempo de retardo en milisegundos
 luces2();//llama a la clase luces2 ();
 delay(500);//tiempo de retardo en milisegundos
 luces3 ();//llama a la clase luces3 ();
 delay (500);//tiempo de retardo en milisegundos
}
  
  void luces1()//Primer juego de luces, Luz que persigue a otra
  {
    for(;contador<14;contador++)//  el numero del contador será la limitacion del ciclo for
   { 
    digitalWrite (leds[contador],HIGH);// en la posicion contador es decir 0 se le dara un valor alto es la primera luz que saldra
    digitalWrite (leds[contador-2],HIGH); //En la posicion contador -2 se le dara un valor alto, esta estará retardada de la anterior en dos posiciones pues arduino lee linea a linea
       delay(300); //retardo
    digitalWrite (leds[contador],LOW); // el contador se encuentra en estado bajo es decir en un tiempo de 300ms la posicion que arriba se encontraba en alto pasara a bajo
    digitalWrite (leds[contador-2],LOW); //el contador-2 se encuentra en estado bajo es decir en un tiempo de 300ms la posicion que arriba se encontraba en alto pasara a bajo
    delay (300);//retardo
   }
    }

  void luces2 () //segundo juego de luces, Las luces se encienden desde los extremos hacia el medio
  {
     for(;contador1<14;contador1++)// el numero del contador serán las veces que sudecera el ciclo for, contador1++ es para mostrar que se incrementara en uno
{ 
   digitalWrite (leds[14-contador1],HIGH);//en la posicion 14-el contador que es el que varia habrá un estado alto
   digitalWrite (leds[contador1],HIGH);//en la posicion del contador que es la variable que ira aumentando tambien estara en alto al mismo tiempo que arriba porque no hay un delay
      delay(500);//retardo
      }
      
  }
    void luces3 () //tercer juego de luces, las luces que en la clase anterior se prendian, en esta clase se apagan desde los extremos hacia el centro
    {
      for(;contador2>=0;contador2--)// el numero del contador es el limite hasta cual llega el ciclo for, contador1-- es para mostrar que se decrementará en uno
{ 
   digitalWrite (leds[14-contador2],LOW);//en la posicion 14-el contador que es el que varia habrá un estado bajo
   digitalWrite (leds[contador2],LOW);//en la posicion de el contador que es la posicion que ira aumentado habrá un estado bajo
      delay(500);//este es el retardo
  }
   }
        
        
    
    
    
    
    

    

