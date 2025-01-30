#define SensorGas A0 //pin sensor gas


void setup() {
  pinMode(SensorGas, INPUT);
  Serial.begin(9600);

}

void loop() {
  int value = analogRead(SensorGas); //read value from sensor gas and store it in value

  Serial.print("value of alcohole : ");
  Serial.println(value);
  delay(500);

}
