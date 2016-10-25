#include<Wire.h>
#include<SPI.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define OLED_MOSI 11
#define OLED_CLK 12
#define OLED_DC 9
#define OLED_CS 8
#define OLED_RESET 10
#define Light_PIN A0 
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void splash(){
  int light = analogRead(Light_PIN);
  display.clearDisplay(); // 清除清除螢幕和緩衝區

display.setTextColor(WHITE); // 設定文字顏色

display.setTextSize(2); // 調整文字大小

display.setCursor(0, 10); // 調整文字座標位置

display.print("Light: "); // 印出想顯示的文字
display.setTextSize(2); // 調整文字大小

display.setCursor(70, 10); // 調整文字座標位置

display.print(light); // 印出想顯示的文字

display.display(); // 顯示畫面
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Light_PIN,INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D); // 初始化OLED

display.clearDisplay(); // 清除清除螢幕和緩衝區

display.setTextWrap(false); // 設定文字超出螢幕會不會換行


}

void loop() {
  // put your main code here, to run repeatedly:
  splash();
  //delay(1000);
}
