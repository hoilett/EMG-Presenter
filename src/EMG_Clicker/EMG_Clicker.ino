//#include "Mouse.h"
#include "Keyboard.h"

uint8_t emg = 3;

void setup()
{
  while(!Serial);
  Serial.begin(115200);

  pinMode(emg, INPUT);

  Keyboard.begin();
}

void loop()
{
  if(digitalRead(emg))
  {
    uint8_t count = 1;
    delay(300);
    unsigned long timer = millis();

    while(millis()-timer < 600)
    {
      if(digitalRead(emg)&&count<3)
      {
        count += 1;
        Keyboard.press(KEY_LEFT_ARROW);
        Keyboard.releaseAll();
        Serial.println("left");
        Serial.print(count);      delay(300);
      }
    }
    if(count < 2)
    {
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      Serial.println("right");Serial.print(count);
    }
    //count = 0;
  }
}



  
//  if(digitalRead(emg))
//  {
//    uint8_t count = 1;
//    delay(250);
//    unsigned long timer = millis();
//
//    while(millis()-timer < 250)
//    {
//      if(digitalRead(emg))
//      {
//        //Mouse.press(MOUSE_LEFT);
//  //      Keyboard.press('n');
//  //      Keyboard.release('n');
//        Serial.println("left");
//      }
//      else
//      {
//        //Mouse.press(MOUSE_RIGHT);
//  //      Keyboard.press('m');
//  //      Keyboard.release('n');
//        Serial.println("right");
//      }
//    }
//  }
//  //delay(10);
//}


//void rightClick()
//{
//  Mouse.press(MOUSE_RIGHT);
//}
//
//
//void leftClick()
//{
//  Mouse.press(MOUSE_LEFT);
//}
