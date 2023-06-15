#include <Stepper.h> // incluimos libreria del stepper
Stepper motor(2048,8,10,9,11);  //pines y pasos para el moto

const int nivel1 = 5; //boton para ir a nivel 1 
const int nivel2 = 6; //boton para ir a niuvel 2
const int nivel3 = 7; //boton para ir a nivel 3

int estadoNVL1; //LECTURA DE BOTON
int estadoNVL2; //LECTURA DE BOTON2
int estadoNVL3; //LECTURA DE BOTON3
int RPM = 2048; // RPM DE STEPPER (HASTA 6144 RPM)

#define int buzz = 10; //pin para buzzer

void setup(){
  
  pinMode(nivel1, INPUT);
  pinMode(nivel2, INPUT);
  pinMode(nivel3, INPUT);
  motor.setSpeed(10);  
  //attachInterrupt(digitalPinToInterrupt(2), interrupcion, FALLING);

}
/*
void interrupcion(){ // INTERRUPCION DEL PROGRAMA PARA REGRESAR A NIVEL 1
motor.step(100);
}
*/

void loop(){
estadoNVL1 = digitalRead(nivel1); //DECLARAMOS LA LECTURA PARA EL NIVEL 1
estadoNVL2 = digitalRead(nivel2); // PARA NIVEL 2 
estadoNVL3 = digitalRead(nivel3); // PARA NIVEL 3
}

void nivel_1(){ //FUNCION PARA NIVEL 1
if(estadoNVL1 == HIGH); 
 motor.step(RPM);
  delay(2000);
}

void nivel_2(){ //FUNCION PARA NIVEL 2 
 if(estadoNVL2 == HIGH);
  motor.step(RPM);
   delay(2000);
}
void nivel_3(){ //FUNCION PARA NIVEL 3
  if(estadoNVL3 == HIGH);
   motor.step(RPM);
     delay(2000);
}
void mostrar(){			// funcion mostrar_1
  for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void mostrar_2(){
    for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void mostrar_3(){
    for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void interruptor(){
  estado = 1;
}