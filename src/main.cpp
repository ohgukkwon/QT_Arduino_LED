#include <Arduino.h>
#include <time.h>

#define red_led 9
#define green_led 10
#define blue_led 11
#define LED_biult 13

#define do_LED_OUT1 5
#define do_LED_OUT2 6
#define do_LED_OUT3 7

#define di_1 16  //
#define di_2 17
#define di_3 18
#define di_4 19


//declare variables for write_leds function of Serial communication
char led_specifier;
int led_brightness;
void led_rgb(char led, int brightness);

//LED_GUI_Button
char buffer[10];
bool isEqual(const char* cmd);

void led_builtin();

//LED_out
void do_led_out1();
void do_led_out2();

char di_2_state;

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(LED_biult, OUTPUT);

  pinMode(do_LED_OUT1, OUTPUT);

  pinMode(di_1, INPUT);
  pinMode(di_2, INPUT);
  pinMode(di_3, INPUT);

  analogWrite(red_led, 10);   // set the brightness of the red LED 0-255
  analogWrite(green_led, 10);  // set the brightness of the red LED 0-255
  analogWrite(blue_led, 10);  // set the brightness of the red LED 0-255
  Serial.begin(9600);
  Serial.flush();
}

void loop()
{
  while (true) {

    do_led_out1();
    do_led_out2();

    led_builtin();

    
    led_specifier = Serial.read();
    led_brightness = Serial.parseInt();
    // write_leds(led_specifier, led_brightness);

    if (Serial.available() ){
      led_specifier = Serial.read();
      led_brightness = Serial.parseInt();
      led_rgb(led_specifier, led_brightness);
      Serial.println("OK");
    }
    delay(100);
  }
}

void do_led_out1()
{
  if (digitalRead(di_1) == HIGH){
    digitalWrite(do_LED_OUT1, HIGH);
    Serial.println("Input1 is HIGH");    
  }
  else{
    digitalWrite(do_LED_OUT1, LOW);
    Serial.println("Input1 is Low");
  }
  return;
}

void do_led_out2()
{
  di_2_state = digitalRead(di_2);
  if (di_2_state == HIGH){
    digitalWrite(do_LED_OUT2, HIGH);
    // Serial.write("Input02 is HIGH");
    // Serial.println("Input02 is HIGH");
  }
  else{
    digitalWrite(do_LED_OUT2, HIGH);
    // Serial.write("Input02 is LOW");
    // Serial.println("Input02 is LOW");
  }
  return;
}

void led_rgb(char led, int brightness)
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
  delay(1);
}



void led_builtin()
{
    int length = Serial.readBytesUntil('\n', buffer, sizeof(buffer));
    buffer[length] = '\0';
    if (isEqual("on")) {
      digitalWrite(LED_biult, HIGH);
      } 
    else if (isEqual("off")) {
      digitalWrite(LED_biult, LOW);
      }
   
}

bool isEqual(const char* cmd)
{
    return strcmp(buffer, cmd) == 0;
}
