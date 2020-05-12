// 인터럽트
// 프로그램이 실행중인 상태에서 인터럽트 조건을 만족하는 어떤 변화가 감지될 경우
// 현재 실행되는 프로그램을 중단시키고 인터럽트 처리 프로그램을 실행 하는 것

// 스위치를 이용하여 인터럽트를 발생시키는 예
volatile byte state = HIGH;
int duration = 500;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

void isr(){
  // 채터링을 소프트웨어적으로 해결하는 알고리즘
  cur_time = millis();
  if(cur_time - pre_time >= duration){
    Serial.println(state);
    digitalWrite(13, state);
    state = !state;
    pre_time = cur_time;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  // attachInterrupt(intNo, ISR, mode)
  // intNo : 인터럽트 번호 0,1 (UNO)
  // ISR : 인터럽트 발생 시 호출될 함수
  // mode : 인터럽트 선택 모드 
  // FALLING (핀의 상태가 HIGH에서 LOW로 바뀔경우)
  // RISING (핀의 상태가 LOW에서 HIGH로 바뀔경우)
  // CHANGE (핀의 상태가 바뀔경우)
  // LOW (핀의 상태가 LOW일 경우)
  attachInterrupt(0, isr, FALLING);
}

void loop() {
}
