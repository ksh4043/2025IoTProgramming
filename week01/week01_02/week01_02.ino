#define TRIG 13
#define ECHO 12

void setup()
{
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration,distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH);
  
  distance = duration / 58.2;
  Serial.println(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  
  delay(1000);
}
