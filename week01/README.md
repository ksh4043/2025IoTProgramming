# week01-01

## 아두이노 LED 깜빡이 예제

7번 핀(빨간 LED)과 8번 핀(녹색 LED)에 연결된 LED를 번갈아 가며 1초 간격으로 깜빡이는 코드입니다.

```cpp
#define LEDG 8         // LEDG라는 이름으로 8번 핀을 정의 (녹색 LED)

int led_r = 7;         // 빨간색 LED는 7번 핀에 연결됨

void setup()
{
  pinMode(led_r, OUTPUT); // led_r 핀(7번)을 출력 모드로 설정
  pinMode(LEDG, OUTPUT);  // LEDG 핀(8번)을 출력 모드로 설정
}

void loop()
{
  digitalWrite(led_r, HIGH);  // 빨간 LED ON
  delay(1000);                // 1초 대기
  digitalWrite(led_r, LOW);   // 빨간 LED OFF
  delay(1000);                // 1초 대기

  digitalWrite(LEDG, HIGH);   // 녹색 LED ON
  delay(1000);                // 1초 대기
  digitalWrite(LEDG, LOW);    // 녹색 LED OFF
  delay(1000);                // 1초 대기
}
```

# week01-02

## 아두이노 초음파 센서 거리 측정 + LED 표시 예제

초음파 센서를 이용해 거리를 측정하고,  
- 거리가 **100cm 이상**이면 빨간 LED 점등  
- 거리가 **100cm 미만**이면 초록 LED 점등

---

### 사용 핀 정리

| 부품           | 핀 번호 | 설명           |
|----------------|---------|----------------|
| 초음파 TRIG핀  | 13      | 출력 (신호 보냄) |
| 초음파 ECHO핀  | 12      | 입력 (신호 받음) |
| 빨간 LED       | 7       | 경고용 표시등   |
| 초록 LED       | 8       | 안전 표시등     |

---

### 🧾 코드

```cpp
#define TRIG 13            // 초음파 센서의 TRIG 핀을 13번으로 설정
#define ECHO 12            // 초음파 센서의 ECHO 핀을 12번으로 설정

int led_r = 7;             // 빨간 LED 핀
int led_g = 8;             // 초록 LED 핀

void setup()
{
  Serial.begin(9600);         // 시리얼 통신 시작 (모니터 출력용)
  pinMode(TRIG, OUTPUT);      // TRIG는 출력
  pinMode(ECHO, INPUT);       // ECHO는 입력
  pinMode(led_r, OUTPUT);     // 빨간 LED 출력 설정
  pinMode(led_g, OUTPUT);     // 초록 LED 출력 설정
}

void loop()
{
  long duration, distance;    // 초음파 측정 시간과 거리 변수

  digitalWrite(TRIG, LOW);    // TRIG 핀 LOW로 초기화
  delayMicroseconds(2);       // 잠깐 대기
  digitalWrite(TRIG, HIGH);   // TRIG 핀 HIGH로 펄스 생성
  delayMicroseconds(10);      // 10마이크로초 유지
  digitalWrite(TRIG, LOW);    // 다시 LOW로 종료

  duration = pulseIn(ECHO, HIGH);        // ECHO 핀으로부터 HIGH 펄스 시간 측정

  distance = duration / 58.2;            // 시간 -> 거리(cm)로 변환
  Serial.println(duration);              // 측정된 시간 출력
  Serial.print("\nDistance : ");         
  Serial.print(distance);                
  Serial.println(" Cm");                 // 거리 출력

  if (distance >= 100)                   // 100cm 이상일 때
  {
    digitalWrite(led_r, HIGH);           // 빨간 LED ON
    digitalWrite(led_g, LOW);            // 초록 LED OFF
  }
  else                                   // 100cm 미만일 때
  {
    digitalWrite(led_g, HIGH);           // 초록 LED ON
    digitalWrite(led_r, LOW);            // 빨간 LED OFF
  }

  delay(1000);                           // 1초 간격으로 반복
}
```
![초음파 센서 개념도](https://www.tinkercad.com/things/hXwJfa2Carq-surprising-kieran)
