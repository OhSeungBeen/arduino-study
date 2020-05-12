// SoftwareSerial
// Serial통신은 1대 1통신으로 하나의 통신만 가능하다.
// 디지털핀 0번과 1번은 아두이노와 컴퓨터를 연결해주는 통신통로로 이미 사용되고 있다.
// Serial포트가 모자랄 때 다른 기기와의 Serial 통신을 하기위해
// SoftwareSerial 라이브러리를 사용하여 통신 할 수 있다.

#include <SoftwareSerial.h>

// Software Serial 라이브러리를 이용하여 2개의 아두이노 통신의 예
int TX = 11;
int RX = 12;
SoftwareSerial my_blue(TX, RX);

void setup() {
  Serial.begin(9600);
  my_blue.begin(9600);
}

void loop() {
  // 다른 아두이노로 부터 받은 데이터가 있다면
  // 읽어서 컴퓨터로 보낸다.
  if(my_blue.available()){
    Serial.write(my_blue.read());
  }
  // 컴퓨터로 부터 받은 데이터가 있다면
  // 읽어서 다른 아두이노로 보낸다.
  if(Serial.available()){
    my_blue.write(Serial.read());
  }
  
  Serial.println();
}
