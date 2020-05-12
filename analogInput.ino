// 아날로그 입력 제어
// 아날로그 입력 PIN(A0 ~ A5) (UNO)
// 가변저항이나 센서 등의 아날로그 신호를 A/D변환하여 0 ~ 1023 값을 읽을 수 있다.

// 가변저항을 이용하여 LED를 제어하는 예
void setup() {
  // 아날로그는 pinMode 함수 생략이 가능하다
  // pinMode(A0, INPUT);
  Serial.begin(9600); 
  pinMode(3, OUTPUT); 
}

void loop() {
  // analogRead(A0)
  //A0핀의 가변저항 아날로그 신호를 읽는다.
  int data = analogRead(A0);
  // 아날로그 입력값은 0 ~ 1023 값이고
  // 아날로그 출력값은 0 ~ 255 값이므로 4로 나누어준다.
  Serial.println(data / 4);
  analogWrite(3, data / 4);
}
