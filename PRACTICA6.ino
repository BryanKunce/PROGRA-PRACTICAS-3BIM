#include <Wire.h> //Libreria I2C
#include <Adafruit_Sensor.h> // Libreria para Acelerometro
#include <Adafruit_ADXL345_U.h> //Libreria para Acelerometro
#include <Servo.h>//Librerias

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(); //Coloco Nombre al Acelerometro
int Eje_X = 0; //Variable para la aceleracion en eje X
int Eje_Y = 0; //Variable para la aceleracion en eje Y
int Eje_Z = 0; //Variable para la aceleracion en eje Z
int servoPin1 = 9;
int servoPin2 = 10;
int X =0;
int Y =0;
Servo servo;
Servo servo1;

void setup(void) {
Serial.begin(9600); //Inicializo el monitor serial a 9600bps
accel.begin();// Inicializo libreria del acelerometro
servo.attach(9);
servo1.attach(10);
}

void loop(void) {
sensors_event_t event; //Le coloco un nombre a las lecturas del acelerometro
accel.getEvent(&event); //los datos de las lecturas del acelerometro se pasan a la funcion que envia los datos
Eje_X = event.acceleration.x; //Asigna la lectura del acelerometro en el eje X
Eje_Y = event.acceleration.y; //Asigna la lectura del acelerometro en el eje Y
Eje_Z = event.acceleration.z; //Asigna la lectura del acelerometro en el eje Z
X = map(Eje_X,-10,9,-90,90);  
servo.write(X);
Y = map(Eje_Y,-3,3,-90,90);  
servo1.write(Y);
Serial.print("X: "); Serial.println(X); Serial.print(" ");
Serial.print("Y: "); Serial.println(Y); Serial.print(" ");



delay(100);
}