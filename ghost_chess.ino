/**
 * \par Copyright (C), 2012-2016, MakeBlock
 * @file    SerialControlstepper_x.ino
 * @author  MakeBlock
 * @version V1.0.0
 * @date    2015/11/19
 * @brief   Description: this file is sample code for Stepper Driver device.
 *
 * Function List:
 *
 *    1. void MeStepper::moveTo(long absolute);
 *    2. void MeStepper::move(long relative);
 *    3. boolean MeStepper::run();
 *    4. void MeStepper::setMaxSpeed(float speed);
 *    5. void MeStepper::setAcceleration(float acceleration);
 *
 * \par History:
 * <pre>
 * <Author>     <Time>        <Version>      <Descr>
 * Mark Yan     2015/09/07    1.0.0          rebuild the old lib.
 * forfish      2015/11/19    1.0.0          add some descriptions.
 * </pre>
 */

#include "MeOrion.h"
#include <SoftwareSerial.h>

MeStepper stepper_x(PORT_1);
MeStepper stepper_y(PORT_2);

MeLimitSwitch limit_x_min(PORT_3, SLOT_1);
MeLimitSwitch limit_x_max(PORT_3, SLOT_2);
MeLimitSwitch limit_y_min(PORT_4, SLOT_1);
MeLimitSwitch limit_y_max(PORT_4, SLOT_2);



void setup()
{
  Serial.begin(9600);
  // Change these to suit your stepper if you want
  stepper_x.setMaxSpeed(1000);
  stepper_x.setAcceleration(20000);
  stepper_y.setMaxSpeed(1000);
  stepper_y.setAcceleration(20000);
}

void loop()
{
  if(Serial.available())
  {
    char a = Serial.read();
    switch(a)
    {
      case '0':
      stepper_x.moveTo(0);
      break;
      case '1':
      stepper_x.moveTo(200);
      break;
      case '2':
      stepper_x.move(50);
      break;
      case '3':
      stepper_x.move(-50);
      break;
      case '4':
      stepper_y.move(50);
      break;
      case '5':
      stepper_y.move(-50);
      break;
    }
  }
  stepper_x.run();
  stepper_y.run();
  if (limit_x_min.touched()) {
    Serial.println("xmin");
  }
  if (limit_x_max.touched()) {
    Serial.println("xmax");
  }
  if (limit_y_min.touched()) {
    Serial.println("ymin");
  }
  if (limit_y_max.touched()) {
    Serial.println("ymax");
  }

}
