#include <Arduino.h>

// Pin analogico de entrada para el LDR
int pinLDR = 7;

// Variable donde se almacena el valor del LDR
int valorLDR = 0;

const int ledPin = 13;

void setup(){
  //  Configurar el puerto serial
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop(){
  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valorLDR= analogRead(pinLDR);

  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino
  Serial.print(valorLDR);

  int valorluz = valorLDR;
 valorluz = map(valorluz, 600, 0, 100, 0);
 //analogWrite(0, val);
 Serial.print("  luz: ");
 Serial.print(valorluz);
 Serial.println(" % ");


  // Esperar unos milisegundos antes de actualizar
  delay(200);
}
