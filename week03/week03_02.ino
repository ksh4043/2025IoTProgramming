#include <Wire.h>				// I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>	// I2C LCD 라이브러리

int Vo = A0;
int V_led = 12;
float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  pinMode(Vo, INPUT);
  pinMode(V_led, OUTPUT);
  lcd.init();		// I2C 초기화
  lcd.backlight();	// 백라이트 켜기
  lcd.print("LCD init");
  delay (2000);
  lcd.clear();
}

void loop()
{
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9600);


  Voltage = Vo_value * 5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;
  lcd.setCursor(0,0);
  lcd.print(dustDensity);
  delay(1000);
  lcd.clear();
}
