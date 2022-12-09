#include "HX711.h"
#define roll_pot A1
#define pitch_pot A0

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 scale;

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
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(-53);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int analogValue_roll = analogRead(roll_pot);
  int analogValue_pitch = analogRead(pitch_pot);
  // Rescale to potentiometer's voltage (from 0V to 5mV):
  int voltage_roll = map(analogValue_roll, 0, 1023, -140, 130);
  int voltage_pitch = map(analogValue_pitch, 0, 1023, -131, 139);
  int weight = scale.get_units(10);

//  // print out the value you read:
//  Serial.print("Analog: ");
//  Serial.print(analogValue);
//  Serial.print("Voltage_roll: ");
//  Serial.println(voltage_roll);
//  Serial.print("Voltage_pitch: ");
//  Serial.println(voltage_pitch);
//  Serial.print("Weight: ");
//  Serial.println(weight);


  Serial.write('!');
  Serial.write('$');
  sendData(voltage_roll);
  sendData(voltage_pitch);
  sendData(weight);
  
  delay(25);
//  delay(2000);
}
