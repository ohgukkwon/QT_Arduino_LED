#include "led_in_out.cpp"
#include "max6675.h"


#define red_led 9
#define green_led 10
#define blue_led 11
#define LED_biult 13

#define do_LED_OUT0 7
#define do_LED_OUT1 8
#define do_LED_OUT2 9

#define di_0 16  //
#define di_1 17
#define di_2 18
#define di_3 19

#define AI_01 14
#define AI_02 15



//declare variables for write_leds function of Serial communication

//LED_GUI_Button
// char buffer[10];
// bool isEqual(const char* cmd);

// void led_builtin();
int Led[4]= {0,0,0,0};
int *pLed = Led;

void led_in00()
{
  if (digitalRead(di_0) == HIGH){
    digitalWrite(do_LED_OUT0, HIGH);
    pLed[0] = 1;
    // Serial.println("Input1 is HIGH");    
  }
  else{
    digitalWrite(do_LED_OUT0, LOW);
    pLed[0] = 0;
    //Serial.println("Input1 is Low");
  }
  return;
}

void led_in01()
{
    pinMode(di_1, INPUT);
  pinMode(do_LED_OUT1, OUTPUT);
  if (digitalRead(di_1) == HIGH){
    digitalWrite(do_LED_OUT1, HIGH);
    pLed[1] = 1;
    // Serial.println("Input1 is HIGH");    
  }
  else{
    digitalWrite(do_LED_OUT1, LOW);
    pLed[1] = 0;
    //Serial.println("Input1 is Low");
  }
  return;
}

void led_in02()
{
  pinMode(di_2, INPUT);
  pinMode(do_LED_OUT2, OUTPUT);
  if (digitalRead(di_2) == HIGH){
    digitalWrite(do_LED_OUT2, HIGH);
    pLed[2] = 1;
    // Serial.println("Input1 is HIGH");    
  }
  else{
    digitalWrite(do_LED_OUT2, LOW);
    pLed[2] = 0;
    //Serial.println("Input1 is Low");
  }
  return;
}

void sendLed()
{
  Serial.print("LedDataSet: ");
  int length = sizeof(Led)/sizeof(Led[0]);
  for (int i = 0; i < length; i++)
  {
    Serial.print(Led[i]);
    Serial.print(" ");
  }
}

// void sendData();


// int thermoDO = 4;
// int thermoCS = 5;
// int thermoCLK = 6;

// MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

// // execute tempSensor.cpp
// void temperature1()
