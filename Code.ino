#include <SPI.h>
#include <MFRC522.h>
#include <Modulino.h>

#define RST_PIN         9
#define SS_PIN          10
#define SENSOR_PIN      4          // Door switch HIGH=Door open, LOW=Door closed
#define BUZZER_PIN      3          // Buzzer

MFRC522 mfrc522(SS_PIN, RST_PIN);  
ModulinoButtons buttons;           

//RFID 
bool rfid_tag_present_prev = false;
bool rfid_tag_present = false;
int _rfid_error_counter = 0;
bool _tag_found = false;

// Door sensor
int door_state = HIGH;

// Alarm 
unsigned long suppression_start_time = 0;
const unsigned long suppression_duration = 120000; // 2 min
bool suppression_enabled = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  Modulino.begin();
  buttons.begin();
}

void loop() {
  updateRFIDStatus();
  updateDoorStatus();
  checkButtonPress();
  updateAlarm();

  delay(50);
}



void updateRFIDStatus() {
  rfid_tag_present_prev = rfid_tag_present;
  _rfid_error_counter++;

  if (_rfid_error_counter > 2) {
    _tag_found = false;
  }

  byte bufferATQA[2];
  byte bufferSize = sizeof(bufferATQA);

  mfrc522.PCD_WriteRegister(mfrc522.TxModeReg, 0x00);
  mfrc522.PCD_WriteRegister(mfrc522.RxModeReg, 0x00);
  mfrc522.PCD_WriteRegister(mfrc522.ModWidthReg, 0x26);

  MFRC522::StatusCode result = mfrc522.PICC_RequestA(bufferATQA, &bufferSize);

  if (result == mfrc522.STATUS_OK) {
    if (!mfrc522.PICC_ReadCardSerial()) return;
    _rfid_error_counter = 0;
    _tag_found = true;
  }

  rfid_tag_present = _tag_found;

  
  if (rfid_tag_present && !rfid_tag_present_prev) {
    Serial.println("Tag found");
  }
  if (!rfid_tag_present && rfid_tag_present_prev) {
    Serial.println("Tag gone");
  }
}

void updateDoorStatus() {
  
  door_state = !digitalRead(SENSOR_PIN);  // HIGH = open, LOW = closed
}

void checkButtonPress() {
  buttons.update();

  if (buttons.isPressed(0) || buttons.isPressed(1) || buttons.isPressed(2)) {
    suppression_enabled = true;
    suppression_start_time = millis();
    Serial.println("Alarm suppression on");
  }
}

void Alarm() {
  unsigned long current_time = millis();

  
  if (suppression_enabled && (current_time - suppression_start_time >= suppression_duration)) {
    suppression_enabled = false;
  }

  bool alarm_on = rfid_tag_present && door_state == HIGH;

  if (alarm_on) {
    if (!suppression_enabled) {
      tone(BUZZER_PIN, 400);  
    } else {
      noTone(BUZZER_PIN);     
    }
  } else {
    noTone(BUZZER_PIN);       
  }
}

// BUZZER code https://wiki.seeedstudio.com/Grove-Buzzer/
// DOOR SWITCH code https://www.instructables.com/How-to-Use-a-Magnetic-Door-Switch-Sensor-With-Ardu/
// RFID code https://highvoltages.co/tutorial/arduino-tutorial/arduino-mfrc522-tutorial-is-rfid-tag-present-or-removed/
// Modulino buttons code https://projecthub.arduino.cc/metehocax/arduino-plug-and-make-kit-all-modulino-demo-99ad53
// suppression timer code https://www.instructables.com/Coding-Timers-and-Delays-in-Arduino/
