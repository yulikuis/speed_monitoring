#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi GPS
TinyGPSPlus gps;
SoftwareSerial ss(4, 3); // RX, TX

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);
  ss.begin(9600);

  // Memulai LCD
  lcd.begin();
  lcd.backlight();
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Membaca data dari GPS
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }

  // Jika data valid, tampilkan kecepatan pada LCD
  if (gps.location.isValid() && gps.speed.isValid()) {
    float speed = gps.speed.kmph(); // Kecepatan dalam km/h

    lcd.setCursor(0, 0);
    lcd.print("Speed: ");
    lcd.print(speed);
    lcd.print(" km/h");

    Serial.print("Speed: ");
    Serial.print(speed);
    Serial.println(" km/h");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Waiting for GPS");
    lcd.setCursor(0, 1);
    lcd.print("signal...");

    Serial.println("Waiting for GPS signal...");
  }

  delay(1000); // Delay 1 detik
}