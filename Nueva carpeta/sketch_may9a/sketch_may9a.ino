#include <DHT.h> 

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin(9600);  
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error leyendo datos del sensor !!!");
    return;
  }

  // ENVÍO EN FORMATO CSV
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(temperature);

  delay(2000);
}
