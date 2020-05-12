// IRremote(리모컨) 제어
// IRremote 라이브러리 사용
#include <IRremote.h>

// 리모컨을 이용하여 LED 제어하는 예
int RECV_PIN = 2; // 핀번호 정의
IRrecv irrecv(RECV_PIN); // IRremote 사용을위한 객체 생성
decode_results results; // decode한 결과값

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // 수광 다이오드 시작
  pinMode(12, OUTPUT);
}

void loop() {
  if(irrecv.decode(&results)){ // 적외선 리모컨 신호를 받을 때
    Serial.println(results.value, HEX);
    if(results.value == 0xC101E57B)
      digitalWrite(12, HIGH);
    else if(results.value == 0x9716BE3F)
      digitalWrite(12, LOW);
    irrecv.resume(); // 다음 신호 받기
  }
  delay(100);
}
