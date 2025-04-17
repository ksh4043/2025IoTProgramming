1. 사물인터넷 개요

초연결 사회와 4차 산업혁명

초연결 사회: 모든 사물과 데이터, 인간의 행동이 네트워크로 연결됨

IoT: 센서부터 도시까지 연결된 기술 기반

산업혁명의 변화

1차: 증기기관

2차: 전기, 대량 생산

3차: 디지털, 네트워크

4차: AI, IoT, 자율주행 등

IoT의 개념

1999년 Kevin Ashton 제안

좁은 의미: 사물 간 통신

넓은 의미: 인간/사물/서비스의 지능적 연결

IoT의 요소

연결: 유/무선 네트워크

정보: 센싱 기술

서비스: 정보 가공 제공

2. IoT의 주요 기술

센싱 기술

스마트 센서, 가상 센싱

특징: 다양한 프로토콜, 보안 문제, 자원 제약, 이동성

네트워크 기술

근거리: Zigbee, Bluetooth, NFC

무선: Wi-Fi, LTE, 5G, 위성 등

유선: Ethernet 등

서비스 인터페이스 기술

인간-사물-서비스 연결

3. IoT 플랫폼

구성 요소

디바이스 플랫폼: 하드웨어+소프트웨어 제공

연결 플랫폼: 데이터 전송 (MQTT, CoAP 등)

데이터 플랫폼: 수집, 분석, 시각화

서비스 플랫폼: 스마트시티, 헬스케어 등 응용

4. IoT 활용 분야

스마트홈

스마트시티

스마트팩토리

헬스케어

5. Arduino C++ 프로그래밍

변수 형식

필수 변수형: int, unsigned long, char, String, bool, float, byte, uint8_t

변수명: camelCase, 영문자/숫자/언더스코어 사용

변수의 적용 범위

전역 변수: setup() 앞에 선언

지역 변수: 함수/블록 내부

변수 속성 지정자

const: 변경 불가

static: 함수 내에서 값 유지

정수형 변수 상세

int: 2~4 byte

unsigned long: 4 byte, 0~약 42억

float: 소수 표현

byte, uint8_t: 1 byte 무부호 정수

6. 배열과 문자 처리

배열

선언, 초기화, 반복문 처리

char와 ASCII

char: 문자 저장, 1 byte

ASCII 코드 사용, \0은 null 문자

배열과 포인터 차이

String 클래스

문자열 객체

메소드: .length(), .substring(), .toInt(), .toCharArray(), .c_str() 등

7. 조건문과 반복문

조건문

if, if else, switch, 삼항연산자

비교 연산자, 논리 연산자

반복문

while, do while, for

break, continue

타이머

millis(), delay()

SimpleTimer: 주기적 실행

8. 함수와 클래스

함수

선언과 호출

매개변수 전달: 값 복사 / 참조 (&)

오버로딩, 프로토타입

클래스

선언: class, public, private

생성자, 멤버 함수

헤더(.h), 소스(.cpp), 라이브러리 구성

9. 시리얼 통신

시리얼 개요

UART: TX, RX, GND 연결

USB 통신도 내부적으로 시리얼 사용

주요 함수

Serial.begin(): 통신 속도 설정

Serial.print(), Serial.write(), Serial.printf()

Serial.read(), Serial.available()

시리얼 활용

입력 처리, LED 제어, 조건문 적용 예제 등
