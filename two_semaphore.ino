// Vehicles LEDs
const int vehicleRed = 10;
const int vehicleYellow = 9;
const int vehicleGreen = 8;

// Pedestrian LEDs
const int pedestrianRed = 7;
const int pedestrianGreen = 6;

// Non-LEDS
const int pedestrianButton = 5;
const int buzzer = 4;
const int ultrasonicTriggerPing = 3;
const int ultrasonicEchoPin = 3;
const int semaphoreButton = 2;

// Ultrasonic constants
const int speedSoundInCmDividedByTwo = 0.01723;
const int minRangeInCm = 20;
const int maxRangeInCm = 330;
int distanceInCm = 0;

// Buttons States
bool semaphoreState = false;
bool buttonState = false;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);

    return pulseIn(echoPin, HIGH);
}

void blinkPedestrianRed(int onDuration, int offDuration) {
    digitalWrite(pedestrianRed, HIGH);
    tone(buzzer, 100, onDuration);
    delay(onDuration);
    digitalWrite(pedestrianRed, LOW);
    delay(offDuration);
}

void startSemaphore()
{
    digitalWrite(pedestrianRed, HIGH);
    digitalWrite(vehicleGreen, HIGH);
    delay(3000);

    digitalWrite(vehicleGreen, LOW);
    digitalWrite(vehicleYellow, HIGH);
    delay(10000);

    digitalWrite(vehicleYellow, LOW);
    digitalWrite(vehicleRed, HIGH);
    delay(3000);

    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);
    tone(buzzer, 400, 10000);
    delay(10000);

    digitalWrite(pedestrianGreen, LOW);

    for (int counter = 0; counter < 4; ++counter) {
        blinkPedestrianRed(500, 1000);
    }

    digitalWrite(pedestrianRed, HIGH);
    delay(2000);
    digitalWrite(vehicleRed, LOW);
    digitalWrite(vehicleGreen, HIGH);
}

void letPedestrianCross()
{
    tone(buzzer, 100, 10000);
    digitalWrite(vehicleRed, HIGH);
    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);
    delay(10000);
    digitalWrite(pedestrianGreen, LOW);
    digitalWrite(vehicleRed, LOW);
}

void setup()
{
    pinMode(pedestrianButton, INPUT);
    pinMode(semaphoreButton, INPUT);

    pinMode(vehicleRed, OUTPUT);
    pinMode(vehicleYellow, OUTPUT);
    pinMode(vehicleGreen, OUTPUT);
    pinMode(pedestrianRed, OUTPUT);
    pinMode(pedestrianGreen, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
  	semaphoreState = digitalRead(semaphoreButton);
    if (semaphoreState == HIGH) {
        buttonState = digitalRead(pedestrianButton);
        distanceInCm = speedSoundInCmDividedByTwo * readUltrasonicDistance(ultrasonicTriggerPing, ultrasonicEchoPin);
        Serial.println(distanceInCm);
        delay(100);

        if (distanceInCm >= 2 && distanceInCm <= 330 || buttonState != LOW) {
            letPedestrianCross();
        } else {
            startSemaphore();
        }
    }
}