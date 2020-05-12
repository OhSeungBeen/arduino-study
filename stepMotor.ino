// 스텝모터 제어
// 모터의 회전을 잘게 쪼개서 쪼갠 조각(스텝)을 이용하여 제어하는 모터
// 정밀한 제어가 가능하다.
// stepper 라이브러리 사용
#include <Stepper.h>

// 1024(180도를 의미)
// 스텝모터가 한번 동작할 때마다 180도를 움직이도록 설정
const int cycle = 1024; 

// 스텝당 회전각도와 연결할 핀 번호를 설정(cycle, IN4, IN3, IN2, IN1)
Stepper motor(cycle,11,9,10,8);

// 스텝모터 제어 예
void setup() {
  // 스텝모터의 회전속도를 지정
  motor.setSpeed(14);
}

void loop() {
  // 스텝모터를 한스텝 작동
  motor.step(cycle);
  delay(500);
}
