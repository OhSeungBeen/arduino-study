// 서보모터 제어
// 0 ~ 180도의 각도를 조절할 수 있다.
// servo 라이브러리 사용
#include<Servo.h>

// 서브모터를 제어를 위한 객체를 정의
Servo motor;

void setup() {
  // attach() 서브모터의 신호선이 연결된 핀을 설정 pinMode와 유사
  motor.attach(6); //아날로그 출력을위해 PWM핀 사용
  Serial.begin(9600);
}

// 시리얼 통신을 이용하여 모터의 각도를 제어하는 예
void loop() {
  // read() 모터의 현재 각도 값을 읽는다. 0 ~ 180
  // 실제 신호선으로 아날로그값을 읽는게 아니다.
  // servo 라이브러리의 함수
  Serial.println(motor.read());
  if(Serial.available()){
    // 모터의 현재 위치값을 now 변수에 저장한다.
    static int now = 0;
    Serial.println(now);
    int data = Serial.read();
    // 서브모터 90도
    if(data == '1'){
      motor.write(90);
      now = 90;
    // 서브모터 180도
    }else if(data == '2'){
      motor.write(180);
      now = 180;
    // 서브모터 180도 또는 0도로 이동하였다가 원래의 각도로 돌아온다.
    }else if(data == '3'){
      //for문을 이용한방법
      int i = now;
      if(now == 180){
        for(i; i > 0; i--){
        Serial.println(i);
        motor.write(i);
        delay(20);
        }
        for(i; i <= now ; i++){
        Serial.println(i);
        motor.write(i);
        delay(20);
        }
        return;
      }
      
      for(i; i < 180; i++){
        Serial.println(i);
        motor.write(i);
        delay(20);
      }
      for(i; i >= now; i--){
        Serial.println(i);
        motor.write(i);
        delay(20);
      }
    // 서브모터 0도
    }else if(data == '4'){
      motor.write(0);
      now = 0;
    }
  }
}
