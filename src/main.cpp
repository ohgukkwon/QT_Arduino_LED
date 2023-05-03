#define red_led 9
#define green_led 10
#define blue_led 11
#include <Arduino.h>

void write_leds(char led, int brightness);

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  analogWrite(red_led, 0);   // set the brightness of the red LED 0-255
  analogWrite(green_led, 0);  // set the brightness of the red LED 0-255
  analogWrite(blue_led, 0);  // set the brightness of the red LED 0-255
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
    char led_specifier = Serial.read();
    int led_brightness = Serial.parseInt();
    write_leds(led_specifier, led_brightness);
  }
}

void write_leds(char led, int brightness)
{
  if (led == 'r'){
    analogWrite(red_led, brightness);  // 0 is Off, 255 is full brightness 
    return;
  }
  if (led == 'g'){
    analogWrite(green_led, brightness);  // 0 is Off, 255 is full brightness 
    return;
  }
  if (led == 'b'){
    analogWrite(blue_led, brightness); // 0 is Off, 255 is full brightness
    return;
  }
  
  return;
}
