// 수동부저 제어
// 음계를 사용하여 멜로디를 출력할 수 있다.

// 수동부저 도레미파솔라시도 출력하는 예
void setup() {
  pinMode(5, OUTPUT);
}

void loop() {
  tone(5, 523); //도 (5옥타브)
  delay(1000);
  tone(5, 587); // 레
  delay(1000);
  tone(5, 659); // 미
  delay(1000);
  tone(5, 698); // 파
  delay(1000);
  tone(5, 784); // 솔
  delay(1000);
  tone(5, 880); // 라
  delay(1000);
  tone(5, 988); // 시
  delay(1000);
  tone(5, 1406); // 도 (6옥타브)
  noTone(5);
  delay(1000);
}
