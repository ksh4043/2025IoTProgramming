# LCD를 이용한 먼지 농도 실시간 출력

## week03-01 : LCD 텍스트 기본 예제

```cpp
#include <Wire.h>                // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h>  // I2C LCD 제어 라이브러리

LiquidCrystal_I2C lcd(0x27, 16, 2); // 주소 0x27, 16x2 LCD

void setup()
{
  lcd.init();        // LCD 초기화
  lcd.backlight();   // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);       // 2초 대기 후 클리어
  lcd.clear();
}

void loop()
{
  lcd.setCursor(16, 0);           // 시작 위치를 우측 바깥쪽으로 지정
  lcd.print("Hello, World!");     // 텍스트 출력

  for (int position = 0; position < 16; position++) {
    lcd.scrollDisplayLeft();      // 왼쪽으로 한 칸씩 스크롤
    delay(50);
  }
}
```

## week03-02 : 먼지 센서 값 LCD로 출력하기
```cpp
#include <Wire.h>				
#include <LiquidCrystal_I2C.h>

int Vo = A0;              // 센서 출력 연결 핀
int V_led = 12;           // 센서 제어용 LED 핀

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD (주소 0x27, 16x2)

void setup()
{
  Serial.begin(9600);
  pinMode(Vo, INPUT);
  pinMode(V_led, OUTPUT);

  lcd.init();            
  lcd.backlight();       
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // 센서에서 데이터 읽기
  digitalWrite(V_led, LOW);
  delayMicroseconds(280);
  Vo_value = analogRead(Vo);
  delayMicroseconds(40);
  digitalWrite(V_led, HIGH);
  delayMicroseconds(9600);

  // 전압 → 농도 변환
  Voltage = Vo_value * 5.0 / 1023.0;
  dustDensity = (Voltage - 0.5) / 0.005;

  // LCD에 표시
  lcd.setCursor(0, 0);
  lcd.print(dustDensity);   // 먼지 농도 값 출력
  delay(1000);
  lcd.clear();              // 매초 초기화
}
```

![LCD 회로도](../Dazzling Juttuli.png)
