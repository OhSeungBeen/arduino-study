// RFID
// 무선 주파수를 이용한 자동인식 기술
// 주파수를 이용해 태그 안에 ID데이터를 저장하고 리더기와 안테나를 이용해 태그가 부착된
// 사물을 관리, 판독, 추적 할 수 있는기술
// SPI, MFRC522 라이브러리 사용
#include <SPI.h>
#include <MFRC522.h>

/reset핀과 ss핀 정의
#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);

// RFID를 이용하여 LED를 제어하는 예
void setup() {
  Serial.begin(9600);
  // 초기화
  SPI.begin();
  mfrc.PCD_Init();
  pinMode(3, OUTPUT);
}

void loop() {
  if(!mfrc.PICC_IsNewCardPresent()) // 태그 접촉이 되지 않았을때
    return; 
  if(!mfrc.PICC_ReadCardSerial())// ID가 읽혀지지 않았을때
    return;
  if(mfrc.uid.uidByte[0] == 243 &&
     mfrc.uid.uidByte[1] == 48 &&
     mfrc.uid.uidByte[2] == 27 &&
     mfrc.uid.uidByte[3] == 3){
      digitalWrite(3, HIGH);
     }else{
      digitalWrite(3, LOW);
     }
  // 태그의 ID출력
  Serial.print("Card UID:");
  for(byte i = 0; i < 4; i++){
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();
}
