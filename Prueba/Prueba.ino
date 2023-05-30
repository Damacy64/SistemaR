// Librerías necesarias
#include <DHT.h>
//Constantes
#define SENSOR_PIN A0 // Pin analógico del Arduino al que está conectado el sensor HW-080
#define MIN_VALOR_SENSOR 0 // Valor mínimo del sensor HW-080
#define MAX_VALOR_SENSOR 1023 // Valor máximo del sensor HW-080
// Pin para el sensor DHT11
DHT dhtsensor(8, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //preparar libreria para comunicarse con el sensor
  dhtsensor.begin();
}

void loop() {
  //leer la humedad y temperatura se guardan en dos variables
  float h = dhtsensor.readHumidity();
  float t = dhtsensor.readTemperature();
  //revisar que las variables tengas un valor numerico
  if(isnan(h) || isnan(t)){
    Serial.println(F("Falla al leer el sensor"));
    return;
  }
  //imprimir la medida del sensor
  Serial.print(F("Humedad ambiental: "));
  Serial.print(h);
  Serial.print(F(" % "));
  Serial.print(F("Temperatura ambiental: "));
  Serial.print(t);
  Serial.println(" *C");
  //codigo para el sensor de humedad suelo
  int Valorsensor = analogRead(SENSOR_PIN); // Leer el valor analógico del sensor

  float porcentaje = ((float)Valorsensor - MAX_VALOR_SENSOR) * 100 / (MIN_VALOR_SENSOR - MAX_VALOR_SENSOR);
  porcentaje = constrain(porcentaje, 0, 100); // Asegurar que el porcentaje esté entre 0 y 100

  Serial.print("Porcentaje de humedad suelo: ");
  Serial.print(porcentaje);
  Serial.println("%");
   delay(5000); //esperar 2 segundos para volver a leer los datos de los sensores
}
