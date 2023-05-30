                                                                  /*BRYAN KUNCE - 2022096 - EB5BM - PRACTICA 1 - TERCER BIMESTRE*/


#include <LiquidCrystal_I2C.h>//Incluimos la libreria para el LCD con el I2C

#define lcdAddress 0x27//Definimos las filas y columas del LCD
#define filas 2
#define columnas 16
LiquidCrystal_I2C lcd (0x27, 2, 16);

#define buzz 7//Definimos que el pin del buzzer sera una salida y cuando este on/off
#define outbuzz() pinMode(buzz,OUTPUT)
#define buzzon() tone(buzz, 958)
#define buzzoff() noTone(buzz)

#define pinBuzzer = 7;
#define Do = 261;
#define Re = 293;
#define Mi = 329;
#define Fa = 349;
#define Sol = 392;
#define La = 440;
#define Si = 493;

#define negra = 250; 
#define blanca = 500; 
#define retardo = 3000;  

#define negra2 = 100; 
#define blanca2 = 200;



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

#define velocidad 0.0343



void setup() {
 lcd.init();//Inicializar el lcd
 lcd.backlight();//Activar el led del lcd
 outbuzz();//Salida del buzzer

 outsonic();//Definimos como salida el pin del trig
 insonic();//Definimos como entrada el pin de echo
 Serial.begin(9600);//Inicializamos el monitor serial
 attachInterrupt(digitalPinToInterrupt(2),cambio,LOW);//Hacer la interupcion

}

void loop() {
 

  onsonic();
  delay(1);
  offsonic();
  float time = pulseIn(echo,HIGH);
  float distancia = (time*velocidad)/2;

  lcd.setCursor(0,1);//Colocamos en que fila y que clumna queremos que este el cursor  
  lcd.print("DISTANCIA");
  
  Serial.println(distancia);

  if (distancia > 500){
 buzzon();
 
  }

 if(distancia > 200){
  lcd.print("**");
  }

  if(distancia > 200){
  lcd.print("****");
  }

  if(distancia > 200){
  lcd.print("******");
  }

  if(distancia > 200){
  lcd.print("********");
  }

  if(distancia > 200){
  lcd.print("**********");
  }

  if(distancia > 200){
  lcd.print("************");
  }

  if(distancia > 200){
  lcd.print("**************");
  }

  if(distancia > 200){
  lcd.print("****************");
  }

}

void cambio(){
Serial.println("Interrupcion");
  }
                                             