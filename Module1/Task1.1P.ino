// C++ code
//
/*
  This program blinks the LED in pin 12 when there is a 
  motion detected by the RIP motion sensor.
*/

int motionPin = 2;
int LedlPin = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  pinMode(LedlPin, OUTPUT);
}

void loop()
{
  int motionResult = digitalRead(motionPin);
  Serial.print("The output value of motion sensor is ");
  Serial.println(motionResult);
  
  if(motionResult == HIGH)
  {
	  // turn the LED on
	  digitalWrite(LedlPin, HIGH);
      Serial.print("The input value of LED sensor is ");
  	  Serial.println(HIGH);
  }
  else
  {
      // turn the LED off
      digitalWrite(LedlPin, LOW);
      Serial.print("The input value of LED sensor is ");
  	  Serial.println(LOW);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}
