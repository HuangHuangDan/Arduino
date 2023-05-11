
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define POT_PIN A2
#define LED_PIN 4

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  LedRun();
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  int distance = duration / 58;

  int potValue = analogRead(POT_PIN);
  int brightness = map(potValue, 0, 1023, 0, 255);
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.print("\tBrightness: ");
  Serial.print(brightness);
  Serial.println();

  delay(500);
}

void LedRun(){

  digitalWrite(LED_PIN, HIGH);  
  delay(500);                   
  digitalWrite(LED_PIN, LOW);   
  delay(500);  

}

