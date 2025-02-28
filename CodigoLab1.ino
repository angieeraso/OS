
int sensorValue;
float temp;
const int ledR = 13; 
const int motorPin = 12; 
const int sensorPin = A0; 

void setup() {
    pinMode(ledR, OUTPUT);
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600); 
    Serial.println("Monitor de Temperatura");
}

void loop() {
    sensorValue = analogRead(sensorPin); 
    Serial.print("Valor del sensor: ");
    Serial.println(sensorValue);
    
    temp = (sensorValue * (500.0 / 1023.0)); // Conversión a temperatura en °C para LM35
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" °C");
    
    // Validaciones
    if (temp < 5) {
        // Intermitencia con retardo de 0.5 seg
        digitalWrite(ledR, HIGH);
        delay(500);
        digitalWrite(ledR, LOW);
        delay(500);
        digitalWrite(motorPin, LOW);
    } else if (temp >= 6 && temp <= 25) {
        // Apagar el LED y Motor
        digitalWrite(ledR, LOW);
        digitalWrite(motorPin, LOW);
    } else if (temp > 25) {
        // Encender el LED y Motor
        digitalWrite(ledR, HIGH);
        digitalWrite(motorPin, HIGH);
    }
    
    delay(2000); 
}
