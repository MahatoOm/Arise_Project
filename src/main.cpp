// #include <Arduino.h>

// // for LED
// #define PIN_RED    23 // GPIO23
// #define PIN_GREEN  22 // GPIO22
// #define PIN_BLUE   21 // GPIO21

// // Ultrasonic Sensor 
// int trig = 26; //GPIO 26
// int echo = 27; //GPIO 27




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
// #define BUTTON_PIN 4       // change if needed
// bool lastState = HIGH;
// bool toggleState = false;



// void setup() {
//     Serial.begin(115200);
//     // For LED
// //   pinMode(PIN_RED,   OUTPUT);
// //   pinMode(PIN_GREEN, OUTPUT);
// //   pinMode(PIN_BLUE,  OUTPUT);



//  // Real TIme Clock
  
//   // if (! rtc.begin(35)) {
//   //   Serial.println("Couldn't find RTC");
//   //   Serial.flush();
//   //   abort();
//   // }
   
// //   rtc.begin();
// //   rtc.writeSqwPinMode(DS1307_SquareWave1HZ);


// //   pinMode(buzzerPin, OUTPUT);
// //   digitalWrite(buzzerPin, HIGH);   // try HIGH first to keep it off


// pinMode(BUTTON_PIN, INPUT_PULLUP);  // important
  
//   Serial.println("Toggle Button Test");



// }




// void loop(){
//     // for led
//     // led();

//     // for ultrasonic sensor
//     // long distance = readUltraSonicSensor(trig, echo);
//     // Serial.print("Distance: ");
//     // Serial.print(distance);
//     // Serial.println(" cm");

//     // delay(200);  

   
//     // for buzzer
//     // buzzer ON
//     // buzzer();

//     // for oush button/
//    bool currentState = digitalRead(BUTTON_PIN);

//   // Detect button press (falling edge)
//   if (lastState == HIGH && currentState == LOW) {
//     toggleState = !toggleState;  // flip state

//     if (toggleState) {
//       Serial.println("Switch ON");
//     } else {
//       Serial.println("Switch OFF");
//     }
//   }

//   lastState = currentState;
//   delay(50);  // debounce
//   // small delay to avoid spam



//   // Real Time clock
//   // realTimeClock();
// }


























// TO Upload code to esp32cam using ftdi adapter 

#include <Arduino.h>
#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"

// AI Thinker ESP32-CAM pins
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

// Capture settings
const int TOTAL_FRAMES = 100;        // how many frames to save
const int FRAME_DELAY_MS = 200;      // 200 ms = about 5 fps
int frameIndex = 0;
bool finished = false;

void initCamera();
bool initSDCard();
bool ensureFramesFolder();
bool saveFrame(int index);
String framePath(int index);

void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.println("\nStarting continuous capture test...");

  initCamera();

  if (!initSDCard()) {
    Serial.println("SD card init failed");
    return;
  }

  if (!ensureFramesFolder()) {
    Serial.println("Could not create /frames folder");
    return;
  }

  Serial.println("Setup complete. Starting capture...");
}

void loop() {
  if (finished) {
    delay(1000);
    return;
  }

  if (frameIndex < TOTAL_FRAMES) {
    bool ok = saveFrame(frameIndex);

    if (ok) {
      Serial.printf("Saved frame %d\n", frameIndex);
    } else {
      Serial.printf("Failed frame %d\n", frameIndex);
    }

    frameIndex++;
    delay(FRAME_DELAY_MS);
  } else {
    Serial.println("Capture finished.");
    finished = true;
  }
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
    config.frame_size = FRAMESIZE_QVGA;  // lighter and more stable for continuous saving
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

  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return false;
  }

  uint64_t cardSizeMB = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("SD card size: %llu MB\n", cardSizeMB);

  return true;
}

bool ensureFramesFolder() {
  if (SD_MMC.exists("/frames")) {
    return true;
  }
  return SD_MMC.mkdir("/frames");
}

String framePath(int index) {
  char path[32];
  snprintf(path, sizeof(path), "/frames/frame_%05d.jpg", index);
  return String(path);
}

bool saveFrame(int index) {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return false;
  }

  String path = framePath(index);
  File file = SD_MMC.open(path, FILE_WRITE);
  if (!file) {
    Serial.printf("Failed to open %s\n", path.c_str());
    esp_camera_fb_return(fb);
    return false;
  }

  size_t written = file.write(fb->buf, fb->len);
  file.close();
  esp_camera_fb_return(fb);

  if (written != fb->len) {
    Serial.printf("Incomplete write: %u / %u\n", (unsigned)written, (unsigned)fb->len);
    return false;
  }

  return true;
}