#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

DHT11 dht11(7);
int led1 = 6; // green
int led2 = 5; // red
LiquidCrystal_I2C lcd(0x27, 16, 2);

int temperature = 0;
int humidity = 0;

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
}

void loop() {

  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(temperature);
  lcd.print("°C");

  // Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // very hot and extream heat
  if((humidity > 60) && (temperature > 35)){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  // very cold and extream cold
  else if ((humidity < 30) && (temperature < 10)){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }

  // normal condition
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }

}
