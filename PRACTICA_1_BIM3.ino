                                                                  /*BRYAN KUNCE - 2022096 - EB5BM - PRACTICA 1 - TERCER BIMESTRE*/


#include <LiquidCrystal_I2C.h>//Incluimos la libreria para el LCD con el I2C

#define lcdAddress 0x27//Definimos las filas y columas del LCD
#define filas 2
#define columnas 16
LiquidCrystal_I2C lcd
(lcdAddress, columnas, filas);

#define buzz 7//Definimos que el pin del buzzer sera una salida y cuando este on/off
#define outbuzz() pinMode(buzz,OUTPUT)
#define buzzon() tone(buzz, 958)
#define buzzoff() noTone(buzz)

#define bom 22//Definimos el pin de la bomba de agua y los estados de HIGH/LOW
#define outbom() pinMode(bom, OUTPUT)
#define onbom() digitalWrite (bom, HIGH)
#define offbom() digitalWrite (bom, LOW)

#define Trig 24//Definimos pines para el sensor ultrasonico IN/OUT HIGH/LOW
#define echo 25
#define onsonic() digitalWrite(Trig,HIGH)
#define offsonic() digitalWrite(Trig,LOW)
#define outsonic() pinMode(Trig,OUTPUT)
#define insonic() pinMode(Trig,INPUT)
const float velo = 0.0343;
float tiempo;
float distancia;



void setup() {
 lcd.init();//Inicializar el lcd
 lcd.backlight();//Activar el led del lcd
 outbuzz();//Salida del buzzer

 outsonic();//Definimos como salida el pin del trig
 insonic();//Definimos como entrada el pin de echo
 Serial.begin(9600);//Inicializamos el monitor serial
 attachInterrupt(digitalPinToInterrupt(2),cambio,LOW);

}

void loop() {
 


  onsonic();
  delay(1);
  offsonic();
  tiempo = pulseIn(echo,HIGH);
  distancia = tiempo*velo/2;
  Serial.println(distancia);
  Serial.println("cm");


}

void cambio(){
Serial.println("Interrupcion");
  }
