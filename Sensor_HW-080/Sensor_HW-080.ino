#define SENSOR_PIN A0 // Pin analógico del Arduino al que está conectado el sensor HW-080
#define MIN_VALOR_SENSOR 0 // Valor mínimo del sensor HW-080
#define MAX_VALOR_SENSOR 1023 // Valor máximo del sensor HW-080

void setup() {
  Serial.begin(9600); // Iniciar comunicación serial para mostrar los datos en el monitor
}

void loop() {
  int Valorsensor = analogRead(SENSOR_PIN); // Leer el valor analógico del sensor

  float porcentaje = ((float)Valorsensor - MAX_VALOR_SENSOR) * 100 / (MIN_VALOR_SENSOR - MAX_VALOR_SENSOR);
  porcentaje = constrain(porcentaje, 0, 100); // Asegurar que el porcentaje esté entre 0 y 100


  Serial.print("Porcentaje de humedad: ");
  Serial.print(porcentaje);
  Serial.println("%");


  delay(2000); // Esperar 2 segundos antes de leer los datos nuevamente
}

