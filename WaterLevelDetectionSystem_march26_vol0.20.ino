#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int led1 = 8;  // red led
int led2 = 9; // yellow led
int led3 = 10; // green led
int buzzer = 11;
int waterSensor = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(waterSensor, INPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {

  int waterLevel = analogRead(waterSensor);
  Serial.print("Water level: ");
  Serial.println(waterLevel);

  // High level
  if(waterLevel >= 400) {
    lcd.setCursor(0, 0);
    lcd.print("Water level:");
    lcd.setCursor(0, 1);
    lcd.print("HIGH!");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // Medium level
  else if(waterLevel >= 300) {
    lcd.setCursor(0, 0);
    lcd.print("Water level:");
    lcd.setCursor(0, 1);
    lcd.print("MEDIUM");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
  }

  // Low level
  else if (waterLevel >= 200) {
    lcd.setCursor(0, 0);
    lcd.print("Water level:");
    lcd.setCursor(0, 1);
    lcd.print("LOW");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
  }

  // no water
  else {
    lcd.clear();
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer, LOW);
  }

}
