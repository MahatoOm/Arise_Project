#include <Arduino.h>

// for LED
#define PIN_RED    23 // GPIO23
#define PIN_GREEN  22 // GPIO22
#define PIN_BLUE   21 // GPIO21

// Ultrasonic Sensor 
int trig = 26; //GPIO 26
int echo = 27; //GPIO 27


void setup() {
    Serial.begin(115200);
    // For LED
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}

void led() {
  // color code #00C9CC (R = 0,   G = 201, B = 204)
  setColor(0, 201, 204);
  delay(1000); // keep the color 1 second
  // color code #F7788A (R = 247, G = 120, B = 138)
  setColor(247, 120, 138);
  delay(1000); // keep the color 1 second
  // color code #34A853 (R = 52,  G = 168, B = 83)
  setColor(52, 168, 83);
  delay(1000); // keep the color 1 second
}



long readUltraSonicSensor(int trig, int echo){

  pinMode(trig, OUTPUT);  
  // Turning off if the trigger function is already in use
  // reset the trigger function 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Send oout a sound pulse
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trig, LOW);  
  pinMode(echo, INPUT);
  long duration =  pulseIn(echo, HIGH); 
  long cm =   duration * 0.01723;
  return cm;
}

void loop(){
    // for led
    led();

    // for ultrasonic sensor
    long distance = readUltraSonicSensor(trig, echo);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(200);


}


























// #include "esp_camera.h"
// #include "FS.h"
// #include "SD_MMC.h"

// #define CAMERA_MODEL_AI_THINKER
// #include "camera_pins.h"

// #include "arduino.h"
// File videoFile;
// bool recording = false;
// int frameCount = 0;


// void record_esp32cam(){
//   if (!recording) return;

//   camera_fb_t* fb = esp_camera_fb_get();
//   if (!fb) {
//     Serial.println("Frame capture failed");
//     return;
//   }

//   // Write frame to SD
//   videoFile.write(fb->buf, fb->len);
//   frameCount++;

//   // Print progress every 30 frames
//   if (frameCount % 30 == 0) {
//     Serial.printf("Frames recorded: %d\n", frameCount);
//   }

//   esp_camera_fb_return(fb);

//   // Stop after 300 frames (~30 seconds at 10fps)
//   if (frameCount >= 300) {
//     videoFile.close();
//     recording = false;

//     // Print final file size
//     File checkFile = SD_MMC.open("/video.mjpeg");
//     if (checkFile) {
//       Serial.printf("Done! File size: %.2f MB\n", checkFile.size() / 1048576.0);
//       checkFile.close();
//     }
//     Serial.println("Recording stopped! Remove SD card to view video.");
//   }
// }

// int red_pin = 35;
// int green_pin = 32;
// int blue_pin = 33;
// void led(){

//   digitalWrite(red_pin, 0);
//   digitalWrite(green_pin,200);
//   digitalWrite(blue_pin,250);
//   delay(1000);
// // color code #F7788A (R = 247, G = 120, B = 138)
//   digitalWrite(red_pin, 247);
//   digitalWrite(green_pin,120);
//   digitalWrite(blue_pin,138);

//   delay(1000);

// }

// void setup() {
//   Serial.begin(115200);
//   delay(1000); // ← let serial stabilize

//   Serial.println("Booting...");
//   // ===========================
//   // LED init
//   // ===========================

//   pinMode(red_pin, OUTPUT);
//   pinMode(green_pin, OUTPUT);
//   pinMode(blue_pin, OUTPUT);


//   /*

//   // ===========================
//   // Camera init
//   // ===========================
  
//   camera_config_t config;
//   config.ledc_channel = LEDC_CHANNEL_0;
//   config.ledc_timer   = LEDC_TIMER_0;
//   config.pin_d0       = Y2_GPIO_NUM;
//   config.pin_d1       = Y3_GPIO_NUM;
//   config.pin_d2       = Y4_GPIO_NUM;
//   config.pin_d3       = Y5_GPIO_NUM;
//   config.pin_d4       = Y6_GPIO_NUM;
//   config.pin_d5       = Y7_GPIO_NUM;
//   config.pin_d6       = Y8_GPIO_NUM;
//   config.pin_d7       = Y9_GPIO_NUM;
//   config.pin_xclk     = XCLK_GPIO_NUM;
//   config.pin_pclk     = PCLK_GPIO_NUM;
//   config.pin_vsync    = VSYNC_GPIO_NUM;
//   config.pin_href     = HREF_GPIO_NUM;
//   config.pin_sccb_sda = SIOD_GPIO_NUM;
//   config.pin_sccb_scl = SIOC_GPIO_NUM;
//   config.pin_pwdn     = PWDN_GPIO_NUM;
//   config.pin_reset    = RESET_GPIO_NUM;
//   config.xclk_freq_hz = 20000000;
//   config.frame_size   = FRAMESIZE_VGA;
//   config.pixel_format = PIXFORMAT_JPEG;
//   config.grab_mode    = CAMERA_GRAB_LATEST;
//   config.fb_location  = CAMERA_FB_IN_PSRAM;
//   config.jpeg_quality = 10;
//   config.fb_count     = 2;
  
//   esp_err_t err = esp_camera_init(&config);
//   if (err != ESP_OK) {
//     Serial.printf("Camera init failed: 0x%x\n", err);
//     return;
//   }
//   Serial.println("Camera init OK!");
  
//   // ===========================
//   // SD Card init
//   // ===========================
//   delay(500); // ← let SD card stabilize
  
//   // Try 1-bit mode (most compatible with ESP32-CAM)
//   if (!SD_MMC.begin("/sdcard", true, true)) {
//     Serial.println("1-bit mode failed, trying normal mode...");
    
//     if (!SD_MMC.begin()) {
//       Serial.println("SD Card mount failed! Check:");
//       Serial.println("  - Card is FAT32 formatted");
//       Serial.println("  - Card is 32GB or smaller");
//       Serial.println("  - Card is fully inserted");
//       return;
//     }
//   }
  
//   // Check card is actually there
//   uint8_t cardType = SD_MMC.cardType();
//   if (cardType == CARD_NONE) {
//     Serial.println("No SD card detected!");
//     return;
//   }
  
//   // Print card info
//   String type = "UNKNOWN";
//   if      (cardType == CARD_MMC)  type = "MMC";
//   else if (cardType == CARD_SD)   type = "SD";
//   else if (cardType == CARD_SDHC) type = "SDHC";
  
//   Serial.println("Card type: " + type);
//   Serial.printf("Card size: %llu MB\n", SD_MMC.cardSize() / (1024 * 1024));
  
//   // List existing files
//   File root = SD_MMC.open("/");
//   File file = root.openNextFile();
//   Serial.println("=== Existing files on SD ===");
//   while (file) {
//     Serial.printf("  %s — %.2f MB\n", file.name(), file.size() / 1048576.0);
//     file = root.openNextFile();
//   }
//   Serial.println("============================");
  
//   // ===========================
//   // Open video file
//   // ===========================
//   videoFile = SD_MMC.open("/video.mjpeg", FILE_WRITE);
//   if (!videoFile) {
//     Serial.println("Failed to create video file!");
//     return;
//   }
  
//   recording = true;
//   Serial.println("Recording started!");
//   */
  
  
// }


// void loop() {
//   // To record the video
//   // record_esp32cam();

//   // for led
//   led();

// }