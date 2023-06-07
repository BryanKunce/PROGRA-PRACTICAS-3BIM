//INSTALAMOS LAS LIBRERIAS DE MODULOS A USAR
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//DEFINIMOS FILAS Y COLUMNAS DEL LCD
#define lcdAddress 0x27  
#define filas 2
#define columnas 16
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);

//INDICAMOS LAS PINES QUE USAREMOS
const int pulsador = 2;  
const int buzzerer = 8;
const int pot = A0;
const int pot_1 = A1;
const int pot_2 = A2;

//VARIABLES PARA LOS POTENCIOMETROS
int potval;
int potval1;
int potval2;

//VARIABLES Y PINES PARA LOS PULSADORES DE POCICIONES
const int botton1 = 4;
const int botton2 = 5;
const int botton3 = 6;
const int botton4 = 7;

int lectura;
int lectura1;
int lectura2;
int lectura3;



//CREAMOS VARIABLES PARA LOS SERVOS 
Servo servoa;
Servo servob;
Servo servoc;

#define buzzout() pinMode(buzzerer,OUTPUT)
#define encenbuzzerer() tone(buzzerer,983)
#define apagbuzzerer() noTone(buzzerer)


void setup() {
 pantallalcd.init();//INICIALIZA EL LCD
 pantallalcd.backlight();//ENCENDEMOS EL LED DEL LCD
 buzzout();//INDICAMOS QUE EL BUZZER ES UNA SALIDA
 servoa.attach(51);
 servob.attach(52);
 servoc.attach(53);
 attachInterrupt(digitalPinToInterrupt(2), Interrupcion, LOW);//INDICAMOS LOS PARAMETROS PARA LA INTERRUPCION
}
void loop() {
   pantallalcd.setCursor(0,0);//POCICION DEL CURSOR EN LA LCD
   pantallalcd.print("GIRE LOS");//LO QUE QUEREMOS QUE MUESTRE EL LCD

      pantallalcd.setCursor(0,1);//POCICION DEL CURSOR EN LA LCD
   pantallalcd.print("POTENCIOMETROS");//LO QUE QUEREMOS QUE MUESTRE EL LCD
   
   servon1();
   servon2();
   servon3();

   pocicionn1();
   pocicionn2();
   pocicionn3();
   pocicionn4();
}

//AQUI USAMOS LAS FUNCIONES SIN RETORNO PARA LAS 4 DISTINTAS POCICIONES CON LOS 4 PULSADORES

void Interrupcion(){
   servoa.write(0);
   servob.write(0);
   servoc.write(0);
    encenbuzzerer();
    delay(1000);
    apagbuzzerer();
}


void servon1(){
  potval = analogRead(pot);
  potval = map(potval, 0, 1023, 0, 180);
  servoa.write(potval);
  delay(10);
}


void servon2(){
  potval1 = analogRead(pot_1);
  potval1 = map(potval1, 0, 1023, 0, 180);
  servob.write(potval1);
  delay(10);
}


void servon3(){
  potval2 = analogRead(pot_2);
  potval2 = map(potval2, 0, 1023, 0, 180);
  servoc.write(potval2);
  delay(10);
}

void pocicionn1(){
  lectura = digitalRead(botton1);
  if(lectura==HIGH){
    encenbuzzerer();
   servoa.write(45);
   servob.write(45);
   servoc.write(45);
    delay(3000);
    apagbuzzerer();
  }
}

void pocicionn2(){
  lectura1 = digitalRead(botton2);
  if(lectura1==HIGH){
    encenbuzzerer();
   servoa.write(90);
   servob.write(90);
   servoc.write(90);
    delay(3000);
    apagbuzzerer();
  }
}
void pocicionn3(){
    lectura2 = digitalRead(botton3);
  if(lectura2==HIGH){
    encenbuzzerer();
   servoa.write(135);
   servob.write(135);
   servoc.write(135);
    delay(3000);
    apagbuzzerer();
  }
}
void pocicionn4(){
   lectura3 = digitalRead(botton4);
  if(lectura3==HIGH){
   encenbuzzerer();
   servoa.write(180);
   servob.write(180);
   servoc.write(180);
   delay(3000);
   apagbuzzerer();
  }
 
}