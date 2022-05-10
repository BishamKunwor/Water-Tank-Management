#define trigPin 2
#define echoPin 3
#define relayPin 4
#define ledZero 6
#define ledOne  7
#define ledTwo  8
#define ledThree 9
#define buzzer 11

/* indicator turns on on this distance */

float total_distance = 25.0;

float oneQuaterFilledIndicator = total_distance * 0.86;
float halfFilledIndicator = total_distance * 0.55;
float quaterToFullIndicator = total_distance * 0.33;
float fullIndicator = total_distance * 0.17;

float duration, distance;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledZero, OUTPUT);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) * 0.0343;

  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of Range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= fullIndicator) {
      tone(buzzer, 500, 80);
      digitalWrite(relayPin, LOW);
      digitalWrite(ledZero, HIGH);
      digitalWrite(ledOne, HIGH);
      digitalWrite(ledTwo, HIGH);
      digitalWrite(ledThree, HIGH);
    } else if (distance <= quaterToFullIndicator) {

      digitalWrite(ledZero, HIGH);
      digitalWrite(ledOne, HIGH);
      digitalWrite(ledTwo, HIGH);
      digitalWrite(ledThree, LOW);
    } else if (distance <= halfFilledIndicator) {
      digitalWrite(ledZero, HIGH);
      digitalWrite(ledOne, HIGH);
      digitalWrite(ledTwo, LOW);
      digitalWrite(ledThree, LOW);
    } else if (distance <= oneQuaterFilledIndicator) {

      digitalWrite(ledZero, HIGH);
      digitalWrite(ledOne, LOW);
      digitalWrite(ledTwo, LOW);
      digitalWrite(ledThree, LOW);
    } else {
      tone(buzzer, 500, 10);
      digitalWrite(relayPin, HIGH);
      digitalWrite(ledZero, LOW);
      digitalWrite(ledOne, LOW);
      digitalWrite(ledTwo, LOW);
      digitalWrite(ledThree, LOW);
    }
    delay(50);
  }
  delay(50);
}
