#define LEDG 8

int led_r = 7;

void setup()
{
  pinMode(led_r, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void loop()
{
  digitalWrite(led_r, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led_r, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDG, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDG, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
