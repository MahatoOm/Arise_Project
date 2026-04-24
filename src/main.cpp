// #include <Arduino.h>

// // MPU6050
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>
// #include <Wire.h>
// Adafruit_MPU6050 mpu;

// // for LED
// #define PIN_RED    23 // GPIO23
// #define PIN_GREEN  22 // GPIO22
// #define PIN_BLUE   21 // GPIO21

// // Ultrasonic Sensor 
// int trig = 26; //GPIO 26
// int echo = 27; //GPIO 27

// // Camera pin





// void setColor(int R, int G, int B) {
//   analogWrite(PIN_RED,   R);
//   analogWrite(PIN_GREEN, G);
//   analogWrite(PIN_BLUE,  B);
// }

// void led() {
//   // color code #00C9CC (R = 0,   G = 201, B = 204)
//   setColor(0, 201, 204);
//   delay(1000); // keep the color 1 second
//   // color code #F7788A (R = 247, G = 120, B = 138)
//   setColor(247, 120, 138);
//   delay(1000); // keep the color 1 second
//   // color code #34A853 (R = 52,  G = 168, B = 83)
//   setColor(52, 168, 83);
//   delay(1000); // keep the color 1 second
// }



// long readUltraSonicSensor(int trig, int echo){

//   pinMode(trig, OUTPUT);  
//   // Turning off if the trigger function is already in use
//   // reset the trigger function 
//   digitalWrite(trig, LOW);
//   delayMicroseconds(2);
  
//   // Send oout a sound pulse
//   digitalWrite(trig, HIGH);
//   delayMicroseconds(10);
  
//   digitalWrite(trig, LOW);  
//   pinMode(echo, INPUT);
//   long duration =  pulseIn(echo, HIGH); 
//   long cm =   duration * 0.01723;
//   return cm;
// }

// #include <TinyGPSPlus.h>
// #include <HardwareSerial.h>

// TinyGPSPlus gps;
// HardwareSerial GPSSerial(2); // Use UART1




// void readGps() {
//   Serial.println("Gps not ready");
//      // Feed GPS data into TinyGPS
//     while (GPSSerial.available()) {
//         gps.encode(GPSSerial.read());
//     }

//     // Print every 2 seconds
//     if (millis() % 2000 < 10) {
//         if (gps.location.isValid()) {
//             Serial.print("Lat: ");
//             Serial.print(gps.location.lat(), 6);
//             Serial.print("  Lng: ");
//             Serial.println(gps.location.lng(), 6);
//         } else {
//             Serial.println("Waiting for GPS fix...");
//         }
//     }

// }

// void readMPU(){
  

//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   Serial.print("Acceleration --> ");

//   // Serial.print("x: "); Serial.print(a.acceleration.x);
//   // Serial.print("y: "); Serial.print(a.acceleration.y);
//   // Serial.print("z: "); Serial.print(a.acceleration.z);

//   // Serial.println("\n\n");Serial.println("Gyro -->");
//   // Serial.print("x: "); Serial.print(g.gyro.x);
//   // Serial.print("y: "); Serial.print(g.gyro.y);
//   // Serial.print("z: "); Serial.print(g.gyro.z);
//   delay(500);
// }

// bool detectAccident() {
//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   // Calculate total acceleration magnitude
//   float totalAcc = sqrt(
//     a.acceleration.x * a.acceleration.x +
//     a.acceleration.y * a.acceleration.y +
//     a.acceleration.z * a.acceleration.z
//   );

//   Serial.print("Total Acceleration: ");
//   Serial.println(totalAcc);

//   // Threshold (tune this)
//   float threshold = 15.0;  // m/s^2 (≈ 2.5g impact)

//   if (totalAcc > threshold) {
//     Serial.println("🚨 ACCIDENT DETECTED!");
//     return true;
//   }

//   return false;
// }

// // Real TIme Colock
// #include <RTClib.h>
// RTC_DS1307 rtc;

// char daysOfWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};



// void realTimeClock(){
//   DateTime now = rtc.now();

//   Serial.print("Current time: ");
//   Serial.print(now.year(), DEC);
//   Serial.print('/');
//   Serial.print(now.month(), DEC);
//   Serial.print('/');
//   Serial.print(now.day(), DEC);
//   Serial.print(" (");
//   Serial.print(daysOfWeek[now.dayOfTheWeek()]);
//   Serial.print(") ");
//   Serial.print(now.hour(), DEC);
//   Serial.print(':');
//   Serial.print(now.minute(), DEC);
//   Serial.print(':');
//   Serial.print(now.second(), DEC);
//   Serial.println();
//   Serial.println();
//   delay(3000);

// }







// // Buzzer
// const int buzzerPin = 18;   // GPIO 

// void buzzer(){
//        // for buzzer
//     // buzzer ON
//   digitalWrite(buzzerPin, LOW);    // active LOW module
//   delay(1000);

//   // buzzer OFF
//   digitalWrite(buzzerPin, HIGH);
//   delay(1000);
// }


// // Push button
// #define BUTTON_PIN   4
// #define TRIGGER_PIN  5


// // Optional UART logging from ESP32-CAM
// #define CAM_RX 16   // ESP32 RX2  <- CAM TX (U0T)
// #define CAM_TX 17   // ESP32 TX2  -> CAM RX (U0R)

// bool lastButtonState = HIGH;
// unsigned long lastDebounceTime = 0;
// const unsigned long debounceDelay = 50;
// const unsigned long triggerPulseMs = 300;




// void setup() {
//     Serial.begin(115200);
//     // UART: TX only to ESP32-CAM
//   // Serial2.begin(115200, SERIAL_8N1, -1, CAM_TX);


//   // -----------------------------------------------------------------------
//     // For LED
// //   pinMode(PIN_RED,   OUTPUT);
// //   pinMode(PIN_GREEN, OUTPUT);
// //   pinMode(PIN_BLUE,  OUTPUT);
//   // -----------------------------------------------------------------------


//  // Real TIme Clock
  
//   // if (! rtc.begin(35)) {
//   //   Serial.println("Couldn't find RTC");
//   //   Serial.flush();
//   //   abort();
//   // }
//   // -----------------------------------------------------------------------
//   // MPU6050 Accelerometer 
//   Serial.println("Adafruit MPU6050 test!");
//   if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//       delay(10);
//     }
//   }
//    Serial.println("MPU6050 Found!");
//   //  -----------------------------------------------------------------------  
// //   rtc.begin();
// //   rtc.writeSqwPinMode(DS1307_SquareWave1HZ);
//   // -----------------------------------------------------------------------

// //   pinMode(buzzerPin, OUTPUT);
// //   digitalWrite(buzzerPin, HIGH);   // try HIGH first to keep it off

//   // -----------------------------------------------------------------------
// // Optional: central log receiver from ESP32-CAM
// //   Serial2.begin(115200, SERIAL_8N1, CAM_RX, CAM_TX);

//   // -----------------------------------------------------------------------
//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   pinMode(TRIGGER_PIN, OUTPUT);
//   digitalWrite(TRIGGER_PIN, LOW);

//   // Serial.println("ESP32 controller ready");
//   // Serial.println("Press button to simulate accident");


// };




// void loop(){
//     // for led
//     // led();
//   // -----------------------------------------------------------------------
//     // for ultrasonic sensor
//     // long distance = readUltraSonicSensor(trig, echo);
//     // Serial.print("Distance: ");
//     // Serial.print(distance);
//     // Serial.println(" cm");

//     // delay(200);  
//   // -----------------------------------------------------------------------
   
//   //  MPU6050 Sensor Accelerometer
//   readMPU();

//   if (detectAccident()) {
//     // Trigger your system
//     Serial.println("Triggering camera / buzzer / alert");
//     Serial.println("Sending ACCIDENT to ESP32-CAM");
//     // Serial2.println("ACCIDENT");


//     // Example:
//     // digitalWrite(BUZZER_PIN, HIGH);
//     digitalWrite(TRIGGER_PIN, HIGH);
//     delay(2000);
//     // digitalWrite(TRIGGER_PIN, HIGH);

//     // digitalWrite(BUZZER_PIN, LOW);
//   }

//   delay(200);
//   // -----------------------------------------------------------------------
//   // Real Time clock
//   // realTimeClock();
//     // for buzzer
//     // buzzer ON
//     // buzzer();
//   // -----------------------------------------------------------------------
//     // for push button/
//   //  bool currentButtonState = digitalRead(BUTTON_PIN);

//   // // detect falling edge (button press)
//   // if (lastButtonState == HIGH && currentButtonState == LOW) {
//   //   unsigned long now = millis();
//   //   if (now - lastDebounceTime > debounceDelay) {
//   //     Serial.println("[ESP32] ACCIDENT TRIGGERED");

//   //     digitalWrite(TRIGGER_PIN, HIGH);
//   //     delay(triggerPulseMs);
//   //     digitalWrite(TRIGGER_PIN, LOW);

//   //     lastDebounceTime = now;
//   //   }
//   // }

//   // lastButtonState = currentButtonState;

//   // -----------------------------------------------------------------------

//   // Optional: read logs from ESP32-CAM and show everything here
// //   while (Serial2.available()) {
// //     String msg = Serial2.readStringUntil('\n');
// //     msg.trim();
// //     if (msg.length() > 0) {
// //       Serial.print("[CAM] ");
// //       Serial.println(msg);
// //     }
// //   }

//   delay(10);


//   // -----------------------------------------------------------------------

// }


















// THis code connects esp32 with esp32cam using push button
/**
 * ESP32CAM  FTDI
 * UOT.  RX
 * UOR.   TX
 * GND.  GND 
 * VCC. 5V
 * 
 * ESP32CAM   PUSHBUTTON
 *  GPIO13 -- GND
 * GND -- OTHER TERMINAL
 */



// TO Upload code to esp32cam using ftdi adapter 
#include <Arduino.h>
#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"

// ============================
// AI Thinker ESP32-CAM pins
// ============================
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

// ============================
// Trigger input from ESP32
// ============================
#define BUTTON_PIN   4
#define TRIGGER_PIN 13
#define FLASH_LED_PIN 4

// ============================
// Capture settings
// ============================
const int FRAME_INTERVAL_MS = 500;   // 2 fps
const int PRE_FRAMES = 10;           // ~5 seconds before trigger
const int POST_RECORD_MS = 10000;    // 10 seconds after trigger

struct FrameData {
  uint8_t* data;
  size_t len;
  bool valid;
};

FrameData rollingBuffer[PRE_FRAMES];
int rollingIndex = 0;

bool crashRecording = false;
bool lastTriggerState = HIGH;
int eventCounter = 0;
unsigned long lastFrameCaptureTime = 0;

// function declarations
void initCamera();
bool initSDCard();
void initRollingBuffer();
void clearFrame(FrameData &frame);
void captureRollingFrame();
String createEventFolder();
void savePreFrames(const String &folderName);
void savePostFrames(const String &folderName);
bool saveBufferToFile(const String &path, const uint8_t* data, size_t len);
void handleCrashEvent();

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("ESP32-CAM crash recorder starting");

  pinMode(TRIGGER_PIN, INPUT);
pinMode(FLASH_LED_PIN, OUTPUT);
digitalWrite(FLASH_LED_PIN, LOW);

  initCamera();

  if (!initSDCard()) {
    Serial.println("SD card init failed");
    while (true) {
      delay(1000);
    }
  }

  initRollingBuffer();

  Serial.println("ESP32-CAM ready");
}

void loop() {
  // keep capturing rolling pre-event frames
  if (!crashRecording) {
    unsigned long now = millis();
    if (now - lastFrameCaptureTime >= FRAME_INTERVAL_MS) {
      captureRollingFrame();
      lastFrameCaptureTime = now;
    }
  }

  // rising edge detect on trigger pin
  bool triggerState = digitalRead(TRIGGER_PIN);

  if (lastTriggerState == HIGH && triggerState == LOW) {
    Serial.println("Crash trigger received");
    handleCrashEvent();
  }

  lastTriggerState = triggerState;
  delay(5);
}

void initCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;

  if (psramFound()) {
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 12;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_QQVGA;
    config.jpeg_quality = 15;
    config.fb_count = 1;
  }

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed: 0x%x\n", err);
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Camera initialized");
}

bool initSDCard() {
  if (!SD_MMC.begin()) {
    Serial.println("SD_MMC mount failed");
    return false;
  }

  if (SD_MMC.cardType() == CARD_NONE) {
    Serial.println("No SD card detected");
    return false;
  }

  uint64_t cardSizeMB = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("SD card size: %llu MB\n", cardSizeMB);
  return true;
}

void initRollingBuffer() {
  for (int i = 0; i < PRE_FRAMES; i++) {
    rollingBuffer[i].data = nullptr;
    rollingBuffer[i].len = 0;
    rollingBuffer[i].valid = false;
  }
}

void clearFrame(FrameData &frame) {
  if (frame.data != nullptr) {
    free(frame.data);
    frame.data = nullptr;
  }
  frame.len = 0;
  frame.valid = false;
}

void captureRollingFrame() {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Rolling capture failed");
    return;
  }

  clearFrame(rollingBuffer[rollingIndex]);

  rollingBuffer[rollingIndex].data = (uint8_t*)malloc(fb->len);
  if (rollingBuffer[rollingIndex].data == nullptr) {
    Serial.println("Rolling buffer malloc failed");
    esp_camera_fb_return(fb);
    return;
  }

  memcpy(rollingBuffer[rollingIndex].data, fb->buf, fb->len);
  rollingBuffer[rollingIndex].len = fb->len;
  rollingBuffer[rollingIndex].valid = true;

  esp_camera_fb_return(fb);

  rollingIndex = (rollingIndex + 1) % PRE_FRAMES;
}

String createEventFolder() {
  String folderName = "/event_" + String(eventCounter++);
  if (!SD_MMC.exists(folderName)) {
    if (!SD_MMC.mkdir(folderName)) {
      Serial.println("Failed to create event folder");
    }
  }
  return folderName;
}

bool saveBufferToFile(const String &path, const uint8_t* data, size_t len) {
  File file = SD_MMC.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file: " + path);
    return false;
  }

  size_t written = file.write(data, len);
  file.close();

  return written == len;
}

void savePreFrames(const String &folderName) {
  int saveIndex = 0;

  // save in chronological order
  for (int i = 0; i < PRE_FRAMES; i++) {
    int idx = (rollingIndex + i) % PRE_FRAMES;

    if (rollingBuffer[idx].valid && rollingBuffer[idx].data != nullptr) {
      String path = folderName + "/pre_" + String(saveIndex) + ".jpg";
      if (saveBufferToFile(path, rollingBuffer[idx].data, rollingBuffer[idx].len)) {
        Serial.println("Saved " + path);
      } else {
        Serial.println("Failed " + path);
      }
      saveIndex++;
    }
  }
}

void savePostFrames(const String &folderName) {
  unsigned long startTime = millis();
  int postIndex = 0;

  while (millis() - startTime < POST_RECORD_MS) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Post capture failed");
      delay(FRAME_INTERVAL_MS);
      continue;
    }

    String path = folderName + "/post_" + String(postIndex) + ".jpg";

    File file = SD_MMC.open(path, FILE_WRITE);
    if (!file) {
      Serial.println("Failed to open " + path);
    } else {
      size_t written = file.write(fb->buf, fb->len);
      file.close();

      if (written == fb->len) {
        Serial.println("Saved " + path);
      } else {
        Serial.println("Incomplete write " + path);
      }
    }

    esp_camera_fb_return(fb);
    postIndex++;

    delay(FRAME_INTERVAL_MS);
  }
}

void handleCrashEvent() {
  crashRecording = true;

  Serial.println("Saving crash event");
  digitalWrite(FLASH_LED_PIN, HIGH);

  String folderName = createEventFolder();
  Serial.println("Event folder: " + folderName);

  savePreFrames(folderName);
  savePostFrames(folderName);

  Serial.println("Crash event saved");
  digitalWrite(FLASH_LED_PIN, LOW);

  crashRecording = false;
}




























// // // // TO Upload code to esp32cam using ftdi adapter 
// // 10 photos shaved

// #include <Arduino.h>
// #include "esp_camera.h"
// #include "FS.h"
// #include "SD_MMC.h"

// // // Trigger input from ESP32
// #define TRIGGER_PIN 12
// #define BUTTON_PIN 12
// #define FLASH_LED_PIN 4

// const int a = 0;

// bool lastButtonState = HIGH;
// unsigned long lastDebounceTime = 0;
// const unsigned long debounceDelay = 50;
// const unsigned long triggerPulseMs = 300;
// bool lastTriggerState = LOW;

// // AI Thinker ESP32-CAM pins
// #define PWDN_GPIO_NUM     32
// #define RESET_GPIO_NUM    -1
// #define XCLK_GPIO_NUM      0
// #define SIOD_GPIO_NUM     26
// #define SIOC_GPIO_NUM     27
// #define Y9_GPIO_NUM       35
// #define Y8_GPIO_NUM       34
// #define Y7_GPIO_NUM       39
// #define Y6_GPIO_NUM       36
// #define Y5_GPIO_NUM       21
// #define Y4_GPIO_NUM       19
// #define Y3_GPIO_NUM       18
// #define Y2_GPIO_NUM        5
// #define VSYNC_GPIO_NUM    25
// #define HREF_GPIO_NUM     23
// #define PCLK_GPIO_NUM     22

// void initCamera() {
//   camera_config_t config;
//   config.ledc_channel = LEDC_CHANNEL_0;
//   config.ledc_timer = LEDC_TIMER_0;
//   config.pin_d0 = Y2_GPIO_NUM;
//   config.pin_d1 = Y3_GPIO_NUM;
//   config.pin_d2 = Y4_GPIO_NUM;
//   config.pin_d3 = Y5_GPIO_NUM;
//   config.pin_d4 = Y6_GPIO_NUM;
//   config.pin_d5 = Y7_GPIO_NUM;
//   config.pin_d6 = Y8_GPIO_NUM;
//   config.pin_d7 = Y9_GPIO_NUM;
//   config.pin_xclk = XCLK_GPIO_NUM;
//   config.pin_pclk = PCLK_GPIO_NUM;
//   config.pin_vsync = VSYNC_GPIO_NUM;
//   config.pin_href = HREF_GPIO_NUM;
//   config.pin_sccb_sda = SIOD_GPIO_NUM;
//   config.pin_sccb_scl = SIOC_GPIO_NUM;
//   config.pin_pwdn = PWDN_GPIO_NUM;
//   config.pin_reset = RESET_GPIO_NUM;
//   config.xclk_freq_hz = 20000000;
//   config.pixel_format = PIXFORMAT_JPEG;

//   if (psramFound()) {
//     config.frame_size = FRAMESIZE_VGA;
//     config.jpeg_quality = 12;
//     config.fb_count = 2;
//   } else {
//     config.frame_size = FRAMESIZE_QVGA;
//     config.jpeg_quality = 15;
//     config.fb_count = 1;
//   }

//   esp_err_t err = esp_camera_init(&config);
//   if (err != ESP_OK) {
//     Serial.printf("Camera init failed: 0x%x\n", err);
//     while (true) {
//       delay(1000);
//     }
//   }
// }

// void handlephotos(){
//   Serial.println("Capturing 10 photos... from handle ");

//   for (int i = 0; i < 10; i++) {
//     camera_fb_t *fb = esp_camera_fb_get();

//     if (!fb) {
//       Serial.println("Camera capture failed");
//       continue;
//     }

//     String path = "/photo_" + String(i) + ".jpg";
//     File file = SD_MMC.open(path, FILE_WRITE);

//     if (!file) {
//       Serial.println("Failed to open file");
//     } else {
//       file.write(fb->buf, fb->len);
//       file.close();
//       Serial.println("Saved: " + path);
//     }

//     esp_camera_fb_return(fb);

//     delay(1000); // 1 second gap between photos
//   }

//   Serial.println("Done capturing. from handle");
// }

// void setup() {
//   Serial.begin(115200);
//   Serial2.begin(115200);
//   delay(1000);

//   Serial.println("Starting...");

  

//   initCamera();

//   if (!SD_MMC.begin()) {
//     Serial.println("SD_MMC mount failed");
//     return;
//   }

//   if (SD_MMC.cardType() == CARD_NONE) {
//     Serial.println("No SD card detected");
//     return;
//   }

//   // Serial.println("Capturing 10 photos...");

//   // for (int i = 0; i < 10; i++) {
//   //   camera_fb_t *fb = esp_camera_fb_get();

//   //   if (!fb) {
//   //     Serial.println("Camera capture failed");
//   //     continue;
//   //   }

//   //   String path = "/photo_" + String(i) + ".jpg";
//   //   File file = SD_MMC.open(path, FILE_WRITE);

//   //   if (!file) {
//   //     Serial.println("Failed to open file");
//   //   } else {
//   //     file.write(fb->buf, fb->len);
//   //     file.close();
//   //     Serial.println("Saved: " + path);
//   //   }

//   //   esp_camera_fb_return(fb);

//     // delay(1000); // 1 second gap between photos
//   // }

//   pinMode(BUTTON_PIN, INPUT_PULLUP);
//   pinMode(TRIGGER_PIN, INPUT_PULLDOWN);
// pinMode(FLASH_LED_PIN, OUTPUT);
// digitalWrite(FLASH_LED_PIN, LOW);
//   Serial.println("Done capturing.");

// }

// void loop() {
//       // for push button/
//    bool currentButtonState = digitalRead(BUTTON_PIN);
//   Serial.println("currentButtonState");
//   Serial.println(currentButtonState);
//   Serial.println("lastButtonState");
//   Serial.println(lastButtonState);
//   // detect falling edge (button press)
//   if (lastButtonState == HIGH && currentButtonState == LOW) {
//     unsigned long now = millis();
//     if (now - lastDebounceTime > debounceDelay) {
//       Serial.println("[ESP32] ACCIDENT TRIGGERED");

//       digitalWrite(TRIGGER_PIN, HIGH);
//       handlephotos();
//       digitalWrite(TRIGGER_PIN, LOW);

//       lastDebounceTime = now;
//     }
//   }

//   lastButtonState = currentButtonState;



//   // CAPTURING IMAGES THROUGH PIN HIGH DIRECTLY THROUGH ESP32 AND ACCELERAMETOR BU MAKING HIGH A PIN
//   // bool sign = digitalRead(TRIGGER_PIN);
//   // Serial.println(sign);
//   // if (sign == HIGH){


//   //   handlephotos();
//   // }


//   // Serial.println(digitalRead(TRIGGER_PIN) );
//   // bool triggerState = digitalRead(TRIGGER_PIN);
//   // if (lastTriggerState == LOW && triggerState== HIGH) {
//   // Serial.println("ACCIDENT TRIGGER RECEIVED");
//   // handlephotos();
//   // lastTriggerState = triggerState;
//   // }

// // if (Serial2.available()) {
// //     String msg = Serial2.readStringUntil('\n');

// //     if (msg == "ACCIDENT") {
// //       Serial.println("ACCIDENT TRIGGER RECEIVED");
// //       handlephotos();
// //     }
// //   }

//   delay(5);
// }

















// // Trying to run from serial output data


// // #include <Arduino.h>
// // #include "esp_camera.h"
// // #include "FS.h"
// // #include "SD_MMC.h"

// // bool sdReady = false;

// // // AI Thinker ESP32-CAM pins
// // #define PWDN_GPIO_NUM     32
// // #define RESET_GPIO_NUM    -1
// // #define XCLK_GPIO_NUM      0
// // #define SIOD_GPIO_NUM     26
// // #define SIOC_GPIO_NUM     27
// // #define Y9_GPIO_NUM       35
// // #define Y8_GPIO_NUM       34
// // #define Y7_GPIO_NUM       39
// // #define Y6_GPIO_NUM       36
// // #define Y5_GPIO_NUM       21
// // #define Y4_GPIO_NUM       19
// // #define Y3_GPIO_NUM       18
// // #define Y2_GPIO_NUM        5
// // #define VSYNC_GPIO_NUM    25
// // #define HREF_GPIO_NUM     23
// // #define PCLK_GPIO_NUM     22

// // void initCamera() {
// //   camera_config_t config;
// //   config.ledc_channel = LEDC_CHANNEL_0;
// //   config.ledc_timer = LEDC_TIMER_0;
// //   config.pin_d0 = Y2_GPIO_NUM;
// //   config.pin_d1 = Y3_GPIO_NUM;
// //   config.pin_d2 = Y4_GPIO_NUM;
// //   config.pin_d3 = Y5_GPIO_NUM;
// //   config.pin_d4 = Y6_GPIO_NUM;
// //   config.pin_d5 = Y7_GPIO_NUM;
// //   config.pin_d6 = Y8_GPIO_NUM;
// //   config.pin_d7 = Y9_GPIO_NUM;
// //   config.pin_xclk = XCLK_GPIO_NUM;
// //   config.pin_pclk = PCLK_GPIO_NUM;
// //   config.pin_vsync = VSYNC_GPIO_NUM;
// //   config.pin_href = HREF_GPIO_NUM;
// //   config.pin_sccb_sda = SIOD_GPIO_NUM;
// //   config.pin_sccb_scl = SIOC_GPIO_NUM;
// //   config.pin_pwdn = PWDN_GPIO_NUM;
// //   config.pin_reset = RESET_GPIO_NUM;
// //   config.xclk_freq_hz = 20000000;
// //   config.pixel_format = PIXFORMAT_JPEG;

// //   if (psramFound()) {
// //     config.frame_size = FRAMESIZE_VGA;
// //     config.jpeg_quality = 12;
// //     config.fb_count = 2;
// //   } else {
// //     config.frame_size = FRAMESIZE_QVGA;
// //     config.jpeg_quality = 15;
// //     config.fb_count = 1;
// //   }

// //   esp_err_t err = esp_camera_init(&config);
// //   if (err != ESP_OK) {
// //     Serial.printf("Camera init failed: 0x%x\n", err);
// //     while (true) {
// //       delay(1000);
// //     }
// //   }
// // }

// // void handlephotos() {
// //   if (!sdReady) {
// //     Serial.println("SD not ready, skipping capture");
// //     return;
// //   }

// //   Serial.println("Capturing 10 photos...");

// //   for (int i = 0; i < 10; i++) {
// //     camera_fb_t *fb = esp_camera_fb_get();

// //     if (!fb) {
// //       Serial.println("Camera capture failed");
// //       continue;
// //     }

// //     String path = "/photo_" + String(i) + ".jpg";
// //     File file = SD_MMC.open(path, FILE_WRITE);

// //     if (!file) {
// //       Serial.println("Failed to open file");
// //     } else {
// //       file.write(fb->buf, fb->len);
// //       file.close();
// //       Serial.println("Saved: " + path);
// //     }

// //     esp_camera_fb_return(fb);
// //     delay(300);
// //   }

// //   Serial.println("Done capturing.");
// // }

// // void setup() {
// //   Serial.begin(115200);
// //   delay(1000);

// //   Serial.println("Starting...");
// //   Serial.println("Before camera init");
// //   initCamera();
// //   Serial.println("After camera init");

// //   Serial.println("Before SD_MMC.begin");
// //   if (SD_MMC.begin()) {
// //     if (SD_MMC.cardType() != CARD_NONE) {
// //       sdReady = true;
// //       Serial.println("SD mounted OK");
// //     } else {
// //       Serial.println("No SD card detected");
// //     }
// //   } else {
// //     Serial.println("SD_MMC mount failed");
// //   }

// //   Serial.println("Setup complete");
// // }

// // void loop() {
// //   if (Serial.available()) {
// //     String msg = Serial.readStringUntil('\n');
// //     msg.trim();

// //     if (msg == "ACCIDENT") {
// //       Serial.println("ACCIDENT TRIGGER RECEIVED");
// //       handlephotos();
// //     }
// //   }

// //   delay(5);
// // }