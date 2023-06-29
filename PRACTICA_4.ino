//INTALAMOS LIBRERIAS

#include <SoftwareSerial.h>

#include <Servo.h>




SoftwareSerial blutuch(8, 9);




//DECLARAMOS VARIABLES Y PINES




char valor;

int leda = 3;

int ledb = 4;

int ledc = 5;

int ledd = 6;

const int servomot = 22;

bool estado = 0;
bool estadob = 0;
bool estadoc = 0;
bool estadod = 0;




Servo servom;




void setup() {

  Serial.begin(9600);//INIZIALISA MONITOR SERIAL

  blutuch.begin(9600);// INICIAMOS EL MODULO

  pinMode(leda, OUTPUT);// MODO DE LOS PINES

  pinMode(ledb, OUTPUT);

  pinMode(ledc, OUTPUT);

  pinMode(ledd, OUTPUT);

  servom.attach(servomot);//NOMBRE SERVO

}




void loop() {




//gira();//NOMBRE FUNCION SIN RETORNO




  if(blutuch.available() > 0){// PONEMOS UN IF

    valor = blutuch.read();

    Serial.println(valor);

 




  if(valor == 'A'){//SI EL VALOR QUE RECIBE ES A
estadoa = !estadoa
    digitalWrite(leda, estadoa); // ENCIENDE EL LED 1

  }




  if(valor == 'B'){ // SI EL VALOR QUE RECIBE ES B
estadob = !estadob
    digitalWrite(ledb, estadob);// ENCIENDE LED 2

  }




  if(valor == 'C'){// SI EL VALOR QUE RECIBE ES C
estadoc = !estadoc
    digitalWrite (ledc, estadoc);// ENCIENDE LED 3

  }




  if(valor == 'D'){// SI EL VALOR QUE RECIBE ES D
estadod = !estadod
    digitalWrite (ledd, estadod);// ENCIENDE LED 4

  }




    }

}




void gira(){// FUNCION SIN RETORNO PARA MOVER SERVO

  while(blutuch.available() > 0){

    valor = blutuch.read();

    Serial.println(valor);

    servom.write(valor);

    delay(100);

  }

}