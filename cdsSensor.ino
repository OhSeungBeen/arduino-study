// 조도(cds) 센서 제어
// 주변의 밝기를 측정하는 센서
// analog pin 사용 (A0 ~ A5) (UNO)

// 조도 센서를 이용하여 LED를 제어하는 예
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
}

void loop() {
  // 조도센서 0 ~ 1023범위 값을 읽는다.
  int cds = analogRead(A0);
  Serial.println(cds);
  delay(100);
  // 조도센서의 값이 100보다
  // 크면 LED OFF 
  // 작으면 LED ON
  if(cds > 100)
    digitalWrite(3, LOW);
  else
    digitalWrite(3, HIGH);
}
