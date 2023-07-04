/*BRYAN KUNCE 2022096 PRACTICA 5*/

// INCLUIMOS LIBRERIAS
#include "Ticker.h" // LIBRERIA QUE SIRVE PARA LA interrupcion POR SOFTWARE
#include <LedControl.h> // LIBRERIA PARA LA Mled LED

void printed();// FUNCION SIN RETORNO PARA QUE LEEA EL VALOR DEL SENSOR

Ticker interrupcion(printed, 500); // CADA MEDIO SEGUNDO REALIZA UNA INTERRUPCION
LedControl Mled = LedControl(11,13,10,1);	// CREAMOS EL OBJETO


// DECLARAMOS VARIABLES Y DEFINIMOS LOS PINES
int lectura; // EVALUARA LOS VALORES QUE ARROJE EL SENSOR MQ2 
int buzzerer=2; // INDICAMOS EL PIN DEL BUZZER
int gas = A0; // PIN ANALOGICO DLE SENSOR MQ2


// HACEMOS LOS ARREGLOS PARA LOS CARACTERES QUE MOSTRARA LA Mled LED
byte form[8]  {		// MUESTRA LA LETRA K		
0x66, 0x6c, 0x78, 0x70, 0x70, 0x78, 0x6c, 0x66
};

byte form2[8]  { // MUESTRA LA LETRA U
0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x3c
};

byte form3[8]  { // MUESTRA LA LETRA N
0xc6, 0xc6, 0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6
};

byte form4[8]  { // MUESTRA LA LETRA C
0x3c, 0x7e, 0xe3, 0xe1, 0xe0, 0xe3, 0x7e, 0x3c
};

byte form5[8]  { // MUESTRA LA LETRA E
0x7e, 0x7e, 0x60, 0x7e, 0x7e, 0x60, 0x7e, 0x7e
};

byte form6[8]  { // MUESTRA UNA CALAVERA POR EL INCENDIO
0x7e, 0x81, 0xa5, 0xa5, 0x81, 0x66, 0x24, 0x1c
};

byte form7[8]  { // MUESTRA UNA ALERTA VISUAL
0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55
};

byte form8[8]  { // MUESTRA UNA ALERTA VISUAL
0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa
};





void setup() {

  interrupcion.start();   // INICIAMOS LA LIBRERIA PARA LA INTERRUPCION
  
  Serial.begin(9600);  // INICIALIZAMOS EL MONITOR SERIAL

  Mled.shutdown(0,false);	// ENCENDEMOS LA MATRIZ
  Mled.setIntensity(0,1);	// AJUSTAMOS EL BRILLO DE LA MATRIZ
  Mled.clearDisplay(0);	// LIMPIA LA MATRIZ

  pinMode(buzzerer, OUTPUT); // DEFINIMOS EL PIN DEL BUZZER COMO UNA SALIDA
  

  // NOMBRES DE LAS FUNCIONES SIN RETORNO QUE MOSTRARAN LOS ARRAYS
   see1();
  delay(500);

  see2();
  delay(500);

  see3();
  delay(500);
  
  see4();
  delay(500);
  
  see5();
  delay(500);
  
  see6();
  delay(500);
  
  see7();
  delay(10);
  
  see8();
  delay(10);
    
 
 
}

void loop() {
  interrupcion.update(); // ACTUALIZACION DE LA LIBRERIA PARA LA INTERRUCION

  lectura = analogRead(gas);
  if(lectura >100){
    digitalWrite(buzzerer, HIGH);// ENCIENDE EL BUZZER
    Mled.clearDisplay(0);	// BACIA LA Mled
    see7();
    delay(10);
    Mled.clearDisplay(0);	// BACIA LA Mled
        see8();
    delay(10);
    Mled.clearDisplay(0);	// BACIA LA Mled
  }else{
    digitalWrite(buzzerer, LOW);// SE APAGA EL BUZZER
    delay(10);
    Mled.clearDisplay(0);	// BACIA LA Mled
  }

}

 
void see1(){ //FORMA 1
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     Mled.setRow(0,i,form[i]);
     delay(100);
     }
}

 
void see2(){ //FORMA 2
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     Mled.setRow(0,i,form2[i]);
     delay(100);
     }
}

   
void see3(){ // FOMRA 3
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     Mled.setRow(0,i,form3[i]);
     delay(100);
     }
}

 
void see4(){ // FORMA 4
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++) 
     {
     Mled.setRow(0,i,form4[i]);
     delay(100);
     }
}

 
void see5(){ //  FORMA 4
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++)  
     {
     Mled.setRow(0,i,form5[i]);
     delay(100);
     }
}

 
void see6(){ // FORMA 5
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++)  
     {
     Mled.setRow(0,i,form6[i]);
     delay(100);
     }
}

 
void see7(){ // FORMA 6
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++)  
     {
     Mled.setRow(0,i,form7[i]);	
     delay(100);
     }
}

 
void see8(){ // FORMA 7
     Mled.clearDisplay(0);
      for (int i = 0; i < 8; i++)  
     {
     Mled.setRow(0,i,form8[i]);	
     delay(100);
     }
}




// FUNCION SIN RETORNO PARA LA INTERRUPCION 
void printed(){
 Serial.println(lectura); // NOS IMPRIME EL VALOR QUE ARROJE EL SENSOR EN EL MONITOR SERIAL
 delay(300);
}
