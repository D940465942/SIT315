// C++ code
//
/*
  This program blinks the LED in pin 12 when there is a 
  motion detected by the RIP motion sensor.
*/

int motionPin = 2;
int ultrasonicPin = 3;
int LedlPin = 12;

int motionResult = LOW;
int ultrasonicResult = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  pinMode(ultrasonicPin, INPUT);
  pinMode(LedlPin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(motionPin), controlLED, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ultrasonicPin), controlLED, RISING);  
}

void loop()
{
  motionResult = digitalRead(motionPin);
  Serial.print("The output value of motion sensor is ");
  Serial.println(motionResult);
  
  ultrasonicResult = digitalRead(ultrasonicPin);
  Serial.print("The output value of ultrasonicPin sensor is ");
  Serial.println(ultrasonicResult);
  
  delay(1000); // Wait for 1000 millisecond(s)
}

void controlLED()
{  
  if(motionResult == HIGH || ultrasonicResult == HIGH)
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
}