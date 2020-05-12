// LCD 제어
// LiquidCrystal_I2C 라이브러리 사용
// SPA와 SCL은 아날로그 Pin에 연결
#include <LiquidCrystal_I2C.h>
// I2C의 채널의 주소 0x27
// 열 16개 행2개 LCD 사용하겠다.
LiquidCrystal_I2C lcd(0x27, 16, 2);

// LCD 제어 예
void setup()
{
  Serial.begin(9600);
  lcd.init(); // LCD 초기화
  lcd.backlight(); //LCD 백라이트 ON
}
 
void loop()
{
  // setCurosor()
  // 커서를 (열, 행)으로 이동
  lcd.setCursor(0, 1);
  // clear()
  // LCD의 모든 내용을 초기화
  lcd.clear();
  // print()
  // 현재커서위치에 입력
  lcd.print("hi");
  delay(100);
}
