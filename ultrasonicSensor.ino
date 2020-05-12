// 초음파 센서
// 송신부(트리거) 일정한 시간의 간격을 둔 짧은,초음파 펄스 방출하고
// 수신부(에코) 대상물에 부딪혀 돌아온 신호를 받음

// 트리거, 에코 pin 정의
int trig = 4;
int echo = 3;

// 초음파 센서를 이용하여 거리를 물체의 거리를 측정하여 부저를 제어하는 예
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // 송신부(트리거)에서 초음파를 보낸다.
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 수신부(에코)에서 신호를 받는다.
  // echoPin이 Highf를 유지한 시간 즉, 초음파가 보냈다가 다시 들어온 시간
  long duration = pulseIn(echo, HIGH); //마이크로 초
  /*
  초음파 속도 : 340m/s
  거리는 시간 * 속도입니다.
  속도는 음속으로 초당 340mm이므로 시간 * 340m이고 cm단위로 바꾸기 위해 34000cm로 변환합니다.
  시간 값이 저장된 duration은 마이크로초 단위로 저장되어 있어, 변환하기 위해 1000000을 나눠줍니다.
  그럼 시간 * 34000 / 1000000이라는 값이 나오고, 정리하여 거리 * 34 / 1000이 됩니다.
  하지만 시간은 장애물에 닿기까지와 돌아오기까지 총 두 번의 시간이 걸렸으므로 2를 나누어줍니다.
  그럼 시간 * 17 / 1000이라는 공식이 나옵니다.
  */
  long distance = duration * 17 / 1000;
  Serial.println(dis_ms);

  if(distance < 3){
    digitalWrite(5, HIGH);
  }else if(distance < 100){
    digitalWrite(5, HIGH);
    delay(distance + 20);
    digitalWrite(5, LOW);
    delay(distance + 20);
  }
  delay(100);
}
