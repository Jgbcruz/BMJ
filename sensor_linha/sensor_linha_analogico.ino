#define sensor 3 
#define LED 12

int valorAnalog = 0;   

void setup() {
  Serial.begin(115200); 
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  
  valorAnalog = analogRead(sensor);
 
  Serial.print("Valor lido: ");
  Serial.println(valorAnalog);
  
  
  if (valorAnalog > 900) {
    Serial.println(" -> Linha não detectada!");
  } else {
    digitalWrite(LED, HIGH);
    Serial.println(" -> Linha detectada!");
  }

  delay(100); 
}
