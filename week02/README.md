# Arduino + 미세 먼지 센서 → InfluxDB 연동

## 프로젝트 개요

- **센서**: Sharp GP2Y1010AU0F 먼지 센서
- **MCU**: Arduino
- **데이터 저장**: InfluxDB
- **중간 처리**: Python (Serial 통신 → InfluxDB)

---

## 아두이노 코드

```cpp
int Vo = A0;               // 센서 출력 값 입력 핀
int V_led = 12;            // 센서 내부 LED 제어 핀

float Vo_value = 0;
float Voltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);      // 시리얼 통신 초기화
  pinMode(V_led, OUTPUT);  // LED 핀 출력으로 설정
  pinMode(Vo, INPUT);      // 센서 출력값 입력으로 설정
}

void loop() {
  digitalWrite(V_led, LOW);        // LED 켜기
  delayMicroseconds(280);          // 센서 안정 시간
  Vo_value = analogRead(Vo);       // 센서 값 읽기
  delayMicroseconds(40);          
  digitalWrite(V_led, HIGH);       // LED 끄기
  delayMicroseconds(9600);         // 센서 회복 시간

  Voltage = Vo_value * 5.0 / 1023.0;     // 아날로그 값 → 전압
  dustDensity = (Voltage - 0.5) / 0.005; // 데이터시트 기반 먼지 농도 계산

  Serial.print("dust=");                // 시리얼 출력
  Serial.println(dustDensity);

  delay(1000); // 1초 대기 후 반복
}
```

## Python 코드 : 시리얼 -> InfluxDB

```cpp
import serial
from influxdb_client import InfluxDBClient
import time

# 시리얼 통신 설정
serial_port = 'COM15'
baud_rate = 9600
timeout = 2

# InfluxDB 설정
influxdb_url = "http://localhost:8086"
influxdb_token = "TOKEN_HERE"
influxdb_org = "test"
influxdb_bucket = "dust"

# InfluxDB 클라이언트 초기화
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()

# 시리얼 포트 연결
try:
    ser = serial.Serial(serial_port, baud_rate, timeout=timeout)
    print(f"Connected to {serial_port} at {baud_rate} baud")
except:
    print("Failed to connect to serial port")
    exit()

# 데이터 수신 루프
try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()

            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value)
                    data = f"sensor_data,device=arduino {key}={value}"
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to influxDB: {key}={value}")
                except ValueError:
                    print("Invalid data format")

            time.sleep(1)

except KeyboardInterrupt:
    print("프로그램이 종료되었습니다.")

finally:
    ser.close()
```
