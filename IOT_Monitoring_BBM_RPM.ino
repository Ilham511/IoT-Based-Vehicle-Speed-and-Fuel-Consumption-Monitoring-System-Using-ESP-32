/*********** BLYNK CONFIG ***********/
#define BLYNK_TEMPLATE_ID           "MASUKKAN_TEMPLATE_ID_ANDA"
#define BLYNK_TEMPLATE_NAME         "Monitoring BBM RPM"
#define BLYNK_AUTH_TOKEN            "MASUKKAN_AUTH_TOKEN_ANDA"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*********** WIFI CONFIG ***********/
char ssid[] = "NAMA_WIFI_ANDA";
char pass[] = "PASSWORD_WIFI_ANDA";

/*********** LCD ***********/
LiquidCrystal_I2C lcd(0x27, 16, 2);

/*********** SENSOR RPM ***********/
volatile int pulseCount = 0;
float speed = 0;
unsigned long prevMillis = 0;
const int interval = 1000;

/*********** FUEL ***********/
int fuelPercent = 0;

/*********** INTERRUPT ***********/
void countPulse() {
  pulseCount++;
}

/*********** SETUP ***********/
void setup() {
  Serial.begin(115200);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  // Pin 2 pada ESP32 (Gunakan GPIO yang sesuai)
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), countPulse, RISING);

  lcd.setCursor(0,0);
  lcd.print("CONNECTING WIFI");
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.print("SYSTEM READY");
  delay(1500);
  lcd.clear();
}

/*********** LOOP ***********/
void loop() {
  Blynk.run();

  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;

    // HITUNG SPEED
    speed = pulseCount * 1.5 * 3.6;
    pulseCount = 0;

    // BACA FUEL (Gunakan pin ADC ESP32, misal GPIO 34)
    int fuelRaw = analogRead(34); 
    fuelPercent = map(fuelRaw, 0, 4095, 0, 100); // ADC ESP32 12-bit (0-4095)

    // LCD DISPLAY
    lcd.setCursor(0,0);
    lcd.print("Spd:");
    lcd.print((int)speed);
    lcd.print(" km/h   ");

    lcd.setCursor(0,1);
    lcd.print("Fuel:");
    lcd.print(fuelPercent);
    lcd.print("%     ");

    // KIRIM KE BLYNK
    Blynk.virtualWrite(V0, speed);
    Blynk.virtualWrite(V1, fuelPercent);
  }
}