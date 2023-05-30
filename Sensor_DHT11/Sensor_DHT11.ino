#include <DHT.h>
DHT dhtsensor(8, DHT11);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //preparar libreria para comunicarse con el sensor
  dhtsensor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  //leer la humedad y temperatura se guardan en dos variables
  float h = dhtsensor.readHumidity();
  float t = dhtsensor.readTemperature();

  //revisar que las variables tengas un valor numerico
  if(isnan(h) || isnan(t)){
    Serial.println(F("Falla al leer el sensor"));
    return;
  }

  //imprimir la medida del sensor
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F(" % "));
  Serial.print(F("Temperatura: "));
  Serial.print(t);
  Serial.println(" *C");
}
