// C++ code
//
int ultrassonic = 0;

int semaphoreState = 0;

int pedestrianButton = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

int counter;

void setup()
{
  pinMode(2, INPUT);
  pinMode(5, INPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  semaphoreState = digitalRead(2);
  while (semaphoreState == HIGH) {
    pedestrianButton = digitalRead(5);
    ultrassonic = 0.01723 * readUltrasonicDistance(3, 3);
    Serial.println(ultrassonic);
    delay(100); // Wait for 100 millisecond(s)
    if (ultrassonic >= 2 && ultrassonic <= 330 || pedestrianButton != LOW) {
      tone(4, 294, 10000); // play tone 50 (D4 = 294 Hz)
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      delay(10000); // Wait for 10000 millisecond(s)
      digitalWrite(6, LOW);
      digitalWrite(10, LOW);
    } else {
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      delay(3000); // Wait for 3000 millisecond(s)
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      delay(10000); // Wait for 10000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      delay(3000); // Wait for 3000 millisecond(s)
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      tone(4, 69, 10000); // play tone 25 (C#2 = 69 Hz)
      delay(10000); // Wait for 10000 millisecond(s)
      digitalWrite(6, LOW);
      for (counter = 0; counter < 4; ++counter) {
        digitalWrite(7, HIGH);
        tone(4, 294, 1000); // play tone 50 (D4 = 294 Hz)
        delay(500); // Wait for 500 millisecond(s)
        digitalWrite(7, LOW);
        delay(1000); // Wait for 1000 millisecond(s)
      }
      digitalWrite(7, HIGH);
      delay(2000); // Wait for 2000 millisecond(s)
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
    }
  }
  digitalWrite(2, LOW);
}
