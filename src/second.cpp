// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>
// #include <Wire.h>
// Adafruit_MPU6050 mpu;

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

// void readMPU(){
  

//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   Serial.print("Acceleration --> ");

//   Serial.print("x: "); Serial.print(a.acceleration.x);
//   Serial.print("y: "); Serial.print(a.acceleration.y);
//   Serial.print("z: "); Serial.print(a.acceleration.z);

//   Serial.println("\n\n");Serial.println("Gyro -->");
//   Serial.print("x: "); Serial.print(g.gyro.x);
//   Serial.print("y: "); Serial.print(g.gyro.y);
//   Serial.print("z: "); Serial.print(g.gyro.z);
//   delay(500);
// }


// void setup() {
//   // rtc begin 
//   // put your setup code here, to run once:
//   Serial.begin(115200);

//    Serial.println("Adafruit MPU6050 test!");
//   if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//       delay(10);
//     }
//   }
//    Serial.println("MPU6050 Found!");
// }

// void loop() {
 
//   //  MPU6050 Sensor Accelerometer
//   readMPU();
//   delay(300);
//   // realTimeClock();

// }
