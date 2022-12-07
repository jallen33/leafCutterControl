

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
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int analogValue_pot1 = 100; // analogRead(A0);
  int analogValue_pot2 = 344; // analogRead(A1);
  // Rescale to potentiometer's voltage (from 0V to 5mV):
  int voltage_pot1 = map(analogValue_pot1, 0, 1023, 0, 5000);
  int voltage_pot2 = map(analogValue_pot2, 0, 1023, 0, 5000);

//  // print out the value you read:
//  Serial.print("Analog: ");
//  Serial.print(analogValue);
//  Serial.print("Voltage: ");
//  Serial.println(voltage);
  Serial.write('!');
  Serial.write('$');
  sendData(voltage_pot1);
  sendData(voltage_pot2);
  
  delay(100);
}
