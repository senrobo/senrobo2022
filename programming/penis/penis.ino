
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempValue = 0;
  for (int i = 0; i < 15; i++)  {
    for (int j=0; j<16; j++) {
      tempValue += digitalRead(2) ^ 1; //bitwise function: +1 to digitalread value everytime so it will be 1,2,3,4,5...
      delayMicroseconds(1); //may not be neccessary, can just delete if the data is ok
    }
    //IRCounter++;
  }
  Serial.println(tempValue);
}
