#include <SPI.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

int led1 = 6;
int led2 = 5;
int buzzer = 4;

String RightCard = "F3 57 DB E1";
String tagID = "";

void setup() {
  lcd.init();
  lcd.backlight();
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Access Control");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    return;

  tagID = "";
  for (uint8_t i = 0; i < 4; i++) {
    tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
    if (i < 3) tagID.concat(" ");
  }
  tagID.toUpperCase();
  Serial.println(tagID);

  lcd.clear();
  if (tagID.equals(RightCard)) {
    lcd.setCursor(0, 0);
    lcd.print("Access Granted!");
    lcd.setCursor(0, 1);
    lcd.print("ID: F3 57 DB E1");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(buzzer, LOW);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Access Denied!");
    lcd.setCursor(0, 1);
    lcd.print("ID: 2D 64 2B02");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  delay(2000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(buzzer, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Access Control");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}

