// PWM 방식
// 디지털출력이지만 값을 아날로그화 시켜 출력하는 방식
// PWM PIN 3,5,6,10,11 (UNO)
// analogWrite(pin, value)
// pin : PWM파형이 출력될 핀의 번호
// value : 0 ~255 파형의세기

// LED 밝기를 조절하는 예제
void setup() {
  Serial.begin(9600); // Serial 통신 9600baud rate(초당 9600비트의 통신속도)
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  for(int i = 0; i < 256; i++){
    Serial.println(i); 
    analogWrite(3, i);
    delay(5);
  }
  
  for(int i = 254; i >= 0; i--){
    Serial.println(i);
    analogWrite(3, i);
    delay(5);
  }
}
