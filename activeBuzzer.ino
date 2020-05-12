// 능동부저 제어
// 음계를 나타내기 어렵고 미리 설계된 회로의 단일음을 출력할 수 있다.

// 능동부저 1예
void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(5, HIGH); // 1초간 부저음 출력
  delay(1000);
  digitalWrite(5, LOW); // 1초간 부저음 출력하지 않음
  delay(1000);
}
