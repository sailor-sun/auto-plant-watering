#include <Arduino.h>
#include <U8x8lib.h>

#define MOSFET 2         // MOSFET for water pump
#define REDLED 4         // Red LED
#define BUTTON 6         // Push button

auto display = U8X8_SSD1306_128X64_NONAME_HW_I2C(U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600);
  display.begin();
  display.setFlipMode(0);
  display.clearDisplay();
  pinMode(MOSFET, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void sendPotentiometerData() {
  const auto value = analogRead(A1);
  const byte data[] = {0, 0, highByte(value), lowByte(value)};
  Serial.write(data, 4);
  Serial.println();
}

void loop() {
  sendPotentiometerData();
  delay(750);
  const auto value1 = analogRead(A1);
  
  if (value1 > 600) {
    digitalWrite(REDLED, HIGH);
    digitalWrite(MOSFET, HIGH);
  } else {
    digitalWrite(REDLED, LOW);
    digitalWrite(MOSFET, LOW);
  }
  
  display.setFont(u8x8_font_profont29_2x3_r);
  display.setCursor(0, 0);
  
  if (!Serial.available()) return;
  const auto receivedData = Serial.read();
  
  char buf[16];
  sprintf(buf, "%03d", receivedData);
  
  if(receivedData <= 100) {
    display.print(buf);
    digitalWrite(MOSFET, LOW);
  } else if (receivedData == 255) {
    digitalWrite(MOSFET, HIGH);
  } else {
    digitalWrite(MOSFET, LOW);
  }
}
