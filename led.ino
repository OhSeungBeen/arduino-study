//led 제어
void setup() {
  pinMode(7, OUTPUT); // 7번 PIN 출력으로 설정
  pinMode(3, OUTPUT); // 7번 PIN 출력으로 설정
}

void loop() {
  digitalWrite(7, HIGH); // 5V 7번 LED ON
  digitalWrite(3, LOW); // 0V 3번 LED OFF
  delay(500); // delay 0.5초
  digitalWrite(7, LOW); // 0V 7번 LED OFF
  digitalWrite(3, HIGH); // 5V 3번 LED ON
  delay(500); // delay 0.5초
}
