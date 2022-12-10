#include "HX711.h"

// define analog pins
#define roll_pot A1
#define pitch_pot A0

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

// write data to serial port
void sendData(int32_t val){
  uint8_t v = (val >> 24) & 0xFF;
  Serial.write(v);
  v = (val >> 16) & 0xFF;
  Serial.write(v);
  v = (val >> 8) & 0xFF;
  Serial.write(v);
  v = (val >> 0) & 0xFF;
  Serial.write(v); 
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); // intialize the scale
  scale.set_scale(-53);  // calibration factor
  scale.tare();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input from the analog pins
  int analogValue_roll = analogRead(roll_pot);
  int analogValue_pitch = analogRead(pitch_pot);

  // Rescale to potentiometer to angles:
  int voltage_roll = map(analogValue_roll, 0, 1023, -140, 130);
  int voltage_pitch = map(analogValue_pitch, 0, 1023, -131, 139);

  // read the weight on the scal in grams
  int weight = scale.get_units(10);

/*
used for debuggin

//  // print out the value you read:
//  Serial.print("Analog: ");
//  Serial.print(analogValue);
//  Serial.print("Voltage_roll: ");
//  Serial.println(voltage_roll);
//  Serial.print("Voltage_pitch: ");
//  Serial.println(voltage_pitch);
//  Serial.print("Weight: ");
//  Serial.println(weight);
//  delay(2000);
*/


  Serial.write('!'); // start bit
  Serial.write('$'); // start bit
  sendData(voltage_roll); // send data
  sendData(voltage_pitch); // send data
  sendData(weight); // send data
  
  delay(25);
}
