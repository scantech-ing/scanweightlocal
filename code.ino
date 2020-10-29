#include "HX711.h"
#define DOUT  2 // Se define pin 2 arduino como DOUT
#define CLK  3 // Se define pin 3 arduino como CLK
#include <RS232.h>
HX711 weighingScales;
void setup() {
  RS232.begin(9600); //Velocidad RS232 impresora Zebra
  Serial.begin(9600); // Puerto Serial Balanza/PC
  weighingScales.begin(DOUT, CLK); // Inicio HX 711 con valores DOUT/CLK
  while(!Serial); 
  Serial.println("Calculando Tara...");
  Serial.println("...");
  weighingScales.set_scale(105); //Se calcula la escala y la Tara
  weighingScales.tare(20);  
  Serial.println("Balanza Lista"); 
}
void loop() {
Serial.println("Subir objeto a la balanza: ");
  delay(1000);
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
Serial.println("Pesando: ");
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
Serial.println("Resultado: ");
delay(1000);
  Serial.print("  Peso: ");
  Serial.print(weighingScales.get_units());
  Serial.println(" Gramos");
  int val0 = (weighingScales.get_value());
  if (val0>1000){
    String txtpeso = "^XA^FO40,40^A0N,80,80^FDPeso: ";
    String txtvalorpeso = String(weighingScales.get_units());
    String txtgramos = " Gramos ^FS^XZ";
    String zebra = txtpeso + txtvalorpeso + txtgramos;
    Serial.println("  Peso alto detectado, Imprimiendo");
    //RS232.print(zebra); // Código a imprimir
    }
    delay(200);
Serial.println("Sacar objeto de la balanza");
delay(1000);
Serial.println("3");
delay(1000);
Serial.println("2");
delay(1000);
Serial.println("1");
delay(1000);
}
