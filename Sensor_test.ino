
const int trigPin = 9;
const int echoPin = 7;

long duration, cm;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration/2) / 29.1;

  Serial.print(cm);
  Serial.print("cm");

}
