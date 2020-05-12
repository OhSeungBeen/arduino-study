// 타이머 인터럽트
// MsTimer2 라이브러리 사용 
#include <MsTimer2.h>

// 타이머 인터럽트를 사용하여 led를 제어하는 예
void setup() {
  pinMode(13, OUTPUT);
  // 타이머 세팅
  // 1초 마다 ISR(인터럽트 서비스 루틴) 실행 설정
  MsTimer2::set(1000, isr);
  // 타이머 시작
  MsTimer2::start();
}

void loop() {

}

// 타이머 인터럽트 함수 정의
void isr(){
  static boolean state = HIGH;
  digitalWrite(13, state);
  state = !state;  
}
