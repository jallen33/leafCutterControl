#include <Servo.h>

String InBytes;
Servo gripper_servo;
Servo cutter_servo;
Servo ESC;

int gripper_pos = 0; 
int cutter_pos = 0;
int blade_speed = 1000;
int servo_pos = 0;

void setup()
{

  gripper_servo.attach(9); 
  cutter_servo.attach(10);

  Serial.begin(57600);

  ESC.attach(11);
  ESC.writeMicroseconds(blade_speed);
  delay(1000);
}

void turnOnSaw()
{
  ESC.writeMicroseconds(blade_speed);
  delay(100);
  blade_speed = 1200;
  ESC.writeMicroseconds(blade_speed);
  delay(250);

  for (int i = 0; i <= 24; i++)
  {
    blade_speed += 25;
    ESC.writeMicroseconds(blade_speed);
    delay(100);
  }

}

void turnOffSaw()
{
  blade_speed = 1000;
  ESC.writeMicroseconds(blade_speed);
  delay(500);
}

void openGripperServo()
{
  for (gripper_pos >= 148; gripper_pos >= 100; gripper_pos -= 1)
  {
    gripper_servo.write(gripper_pos);
    delay(10);
  }
}

void closeGripperServo()
{
  for (gripper_pos <= 100; gripper_pos <= 148; gripper_pos += 1)
  {
    gripper_servo.write(gripper_pos);
    delay(10); 
  }
}

void incrementalGripperClose()
{
  if (gripper_pos <= 158 && gripper_pos >= 95)
  {
    for (int i = 0; i <= 5; i += 1)
    {
      gripper_pos += 1;
      gripper_servo.write(gripper_pos);
      delay(25);
    }
  }
  else
  {
    Serial.write("Out of Bounds");
  }
}

void incrementalGripperOpen()
{
  if (gripper_pos <= 168 && gripper_pos >= 100)
  {
    for (int i = 0; i <= 5; i += 1)
    {
      gripper_pos -= 1;
      gripper_servo.write(gripper_pos);
      delay(25);
    }
  }
  else
  {
    Serial.write("Out of Bounds");
  }
}

void openCutterServo()
{
  for (cutter_pos <= 80; cutter_pos <= 265; cutter_pos += 1)
  {
    cutter_servo.write(cutter_pos);
    delay(10);
  }
}

void closeCutterServo()
{
  for (cutter_pos >= 265; cutter_pos >= 80; cutter_pos -= 1)
  {
    cutter_servo.write(cutter_pos);
    delay(10);
  }
}

void incrementalCutterClose()
{
  if (cutter_pos <= 270 && cutter_pos >= 45)
  {
    for (int i = 0; i <= 5; i += 1)
    {
      cutter_pos -= 1;
      cutter_servo.write(cutter_pos);
      delay(25);
    }
  }
  else
  {
    Serial.write("Out of Bounds");
  }
}

void incrementalCutterOpen()
{
  if (cutter_pos <= 260 && cutter_pos >= 35)
  {
    for (int i = 0; i <= 5; i += 1)
    {
      cutter_pos += 1;
      cutter_servo.write(cutter_pos);
      delay(25);
    }
  }
  else
  {
    Serial.write("Out of Bounds");
  }
}

void loop()
{
  while (Serial.available() > 0)
  {

    InBytes = Serial.readStringUntil('\n');

    if (InBytes == "g")
    {
      closeGripperServo();
      Serial.write("--> Close Gripper\n");
    }

    else if (InBytes == "h")
    {
      openGripperServo();
      Serial.write("--> Open Gripper\n");
    }

    else if (InBytes == "j")
    {
      incrementalGripperClose();
      Serial.write("--> Close Gripper Slow\n");
    }

    else if (InBytes == "k")
    {
      incrementalGripperOpen();
      Serial.write("--> Open Gripper Slow\n");
    }

    else if (InBytes == "u")
    {
      closeCutterServo();
      Serial.write("--> Close Cutter\n");
    }

    else if (InBytes == "i")
    {
      openCutterServo();
      Serial.write("--> Open Cutter\n");
    }

    else if (InBytes == "c")
    {
      turnOnSaw();
      Serial.write("--> Start Cutter\n");
    }

    else if (InBytes == "s")
    {
      turnOffSaw();
      Serial.write("--> Stop Cutter\n");
    }

    else if (InBytes == "o")
    {
      incrementalCutterClose();
      Serial.write("--> Close Cutter Slow\n");
    }

    else if (InBytes == "p")
    {
      incrementalCutterOpen();
      Serial.write("--> Open Cutter Slow\n");
    }

    else
    {
      Serial.write("--> invalid input\n");
    }
  }
}
