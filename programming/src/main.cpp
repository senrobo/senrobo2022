#include <Arduino.h>
#include <i2c_t3.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055_t3.h>
#include <utility/imumaths.h>
#include <math.h>

void setup(){
    // PWM 22
    // DIR 21
    pinMode(21,OUTPUT);
    pinMode(22,OUTPUT);
}

void loop(){
    analogWrite(21,255);
    digitalWrite(22,HIGH);
    delay(1000);
}