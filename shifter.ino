#include "Joystick.h"

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   8, 0,                 // Button Count, Hat Switch Count
                   false, false, false,   // no X and Y, but no Z Axis
                   false, false, false,  // No Rx, Ry, or Rz
                   false, false,         // No rudder or throttle
                   false, false, false); // No accelerator, brake, or steerings

class Button {
  private:
    byte pin;
    byte btn;
    bool lastRead;
  public:
    Button(byte pin, byte btn) {
      this->pin = pin;
      this->btn = btn;
      this->lastRead = 0;
      pinMode(pin, INPUT);
      digitalWrite(pin, HIGH);

    }

    void check() {
      bool rd = !digitalRead(pin);
      /*Serial.print("button pressed ");
        Serial.println(this->row[col]);
        Serial.println(col);
        Serial.println(rd);
        Serial.println(this->lastRead[col]);*/
      if (this->lastRead != rd) {

        Joystick.setButton(btn, rd);
      }
      this->lastRead = rd;
    }
};

Button btn[8] = {
  Button(A0, 7),
  Button(13, 5),
  Button(12, 3),
  Button(10, 1),
  Button(8, 6),
  Button(6, 4),
  Button(4, 2),
  Button(2, 0)
};

void setup()
{
  // put your setup code here, to run once:
  Joystick.begin();
}
int a = 0;
void loop()
{
  //a++;
  // put your main code here, to run repeatedly:
  //Serial.println(a);
  for (int i = 0; i < 8; i++)
  {
    btn[i].check();
  }
}
