사물인터넷 5주차 - 아두이노 프로그래밍

1. 사물인터넷 개요

초연결 사회와 4차 산업혁명

- 초연결 사회: 모든 사물과 데이터, 인간의 행동이 네트워크로 연결됨
- IoT: 센서부터 도시까지 연결된 기술 기반

산업혁명의 변화

1. 1차: 증기기관
2. 2차: 전기, 대량 생산
3. 3차: 디지털, 네트워크
4. 4차: AI, IoT, 자율주행 등

IoT의 개념

- 1999년 Kevin Ashton 제안
- 좁은 의미: 사물 간 통신
- 넓은 의미: 인간/사물/서비스의 지능적 연결

IoT의 요소

- 연결: 유/무선 네트워크
- 정보: 센싱 기술
- 서비스: 정보 가공 제공

2. IoT의 주요 기술

센싱 기술

- 스마트 센서, 가상 센싱
- 특징:
  - 다양한 프로토콜
  - 보안 문제
  - 자원 제약
  - 이동성

네트워크 기술

- 근거리: Zigbee, Bluetooth, NFC
- 무선: Wi-Fi, LTE, 5G, 위성 등
- 유선: Ethernet 등

서비스 인터페이스 기술

- 인간-사물-서비스 연결

3. IoT 플랫폼

구성 요소

- 디바이스 플랫폼: 하드웨어+소프트웨어 제공
- 연결 플랫폼: 데이터 전송 (MQTT, CoAP 등)
- 데이터 플랫폼: 수집, 분석, 시각화
- 서비스 플랫폼: 스마트시티, 헬스케어 등 응용

4. IoT 활용 분야

- 스마트홈
- 스마트시티
- 스마트팩토리
- 헬스케어

5. Arduino C++ 프로그래밍

변수 형식

- 필수 변수형: int, unsigned long, char, String, bool, float, byte, uint8_t
- 변수명 작성 규칙:
  - camelCase 사용
  - 영문자, 숫자, 언더스코어 사용 가능

변수의 적용 범위

- 전역 변수: setup() 앞에 선언 → 전체 사용 가능
- 지역 변수: 함수/블록 내부에서만 사용

변수 속성 지정자

- const: 값 변경 불가
- static: 함수 내에서 값 유지

정수형 변수 상세

- int: 2~4 byte
- unsigned long: 4 byte, 0~약 42억
- float: 소수 표현
- byte, uint8_t: 1 byte 무부호 정수

6. 배열과 문자 처리

배열
```
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
  Serial.println(arr[i]);
}
```
char와 ASCII
```
char letter = 'A';
Serial.println((int)letter); // ASCII 출력
```
String 클래스
```
String s = "Hello";
Serial.println(s.length());
Serial.println(s.substring(1, 3));
```
7. 조건문과 반복문

조건문
```
if (x > 10) {
  Serial.println("x is greater than 10");
} else {
  Serial.println("x is 10 or less");
}
```
반복문
```
while (true) {
  // loop forever
  break;
}
```
타이머 사용 예시
```
unsigned long now = millis();
if (now - lastTime > 1000) {
  lastTime = now;
  // 1초마다 실행
}
```
8. 함수와 클래스

함수 정의 및 호출
```
int add(int a, int b) {
  return a + b;
}

void setup() {
  Serial.println(add(3, 4));
}
```
클래스 예시
```
class LED {
  public:
    LED(int pin);
    void on();
    void off();

  private:
    int _pin;
};
```
9. 시리얼 통신

기본 함수
```
void setup() {
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    Serial.print("You typed: ");
    Serial.println(c);
  }
}
```
