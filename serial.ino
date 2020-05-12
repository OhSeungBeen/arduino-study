// serial 통신
// 시리얼 통신은 직렬 통신을 말하며, 연속적으로 통신채널이나 컴퓨터 버스를 거쳐 한번에 하나의
// 비트 단위로 데이터를 전송하는 과정을 말한다.

// serial 통신을 이용하여 LED를 제어하는 예
void setup() {
  Serial.begin(9600); // Serial 통신 9600baud rate(초당 9600비트의 통신속도)
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
    // Serail.availabel()
    // 시리얼 포트로 수신된 데이터의 갯수를 반환한다. 받지않았다면 0을 반환한다.
    if(Serial.available()){ 
      // Serial.read()
      // 시리얼 통신 수신 버퍼에서 첫번째 문자열을 읽어 반환한다. 수신버퍼가 비어있으면 -1을 반환한다.
      int data = Serial.read(); 
      if(data == '1'){
        digitalWrite(3, HIGH);
      }    
      else if(data == '2'){
        digitalWrite(5, HIGH);
      }
     else if(data == '3'){
        digitalWrite(3, LOW);
      }
      else if(data == '4'){
        digitalWrite(5, LOW);
      }
      else if(data == '5'){
        for(int i = 0; i < 5; i++){
          digitalWrite(3, HIGH);
          digitalWrite(5, HIGH);
          delay(1000);
          digitalWrite(3, LOW);
          digitalWrite(5, LOW);
          delay(1000);
        }
      }
      else{
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
      }
  }
}
