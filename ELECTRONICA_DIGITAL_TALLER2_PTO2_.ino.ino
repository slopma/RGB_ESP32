#define S 35
#define R 27          
#define G 26        
#define B 25         

void setup() {
  pinMode(S, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600); 
}

void loop() {

  int sensorValue = analogRead(S);

  float voltage = sensorValue * (5 / 4095.0); // ESP32 utiliza ADC de 12 bits
  float temperatureC = voltage * 100.0; // LM35 entrega 10mV por grado Celsius
  
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  if (temperatureC >= 20 && temperatureC <= 25) {
    // Azul
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, HIGH);
  } else if (temperatureC > 25 && temperatureC <= 30) {
    // Naranja 
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(B, LOW);
  } else if (temperatureC > 30) {
    // Rojo
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  } else {
    // Apaga el LED
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }

  // Esperar un momento antes de la siguiente lectura
  delay(1000);
}

