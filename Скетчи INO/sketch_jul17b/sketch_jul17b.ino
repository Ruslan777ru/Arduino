

#define redLED   2
#define greenLED 4
#define blueLED  6
#define delel    200

int blinks = 0;


void setup()
{
  Serial.begin(9600);
  //pinMode(LED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  
}

int checkTemp()
{
  float voltage = 0;
  float celsius = 0;
  float hotTemp = 26;
  float coldTemp = 20;
  float sensor = 0;
  float fahrenheit = 0;
  
  //int result;
  
  
 //считывание значений с датчика
  sensor = analogRead(0);
  voltage = (sensor*5000)/1023; 
  voltage = voltage - 500;
  celsius = voltage/10;
  fahrenheit = (1.8*celsius)+32;

  
  if(celsius <= coldTemp)
  {
    //result = 2; //без светодиодов (лампочка горит на Ардуино
    digitalWrite(redLED, HIGH);  //модификация со светодиодами
    delay(delel);
    digitalWrite(redLED, LOW);
    delay(delel);
  }
  else if(celsius > coldTemp && celsius < hotTemp)
  {
    //result = 4;
    digitalWrite(greenLED, HIGH); //модификация со светодиодами
    delay(delel);
    digitalWrite(greenLED, LOW);
    delay(delel);
  }
  else
  {
    //result = 6;
    digitalWrite(redLED, HIGH); //модификация со светодиодами
    delay(delel);
    digitalWrite(redLED, LOW);
    delay(delel);
  }
}

/*
void blinkLED(int cycles, int del)
{
  for (int a = 0; a < cycles; a++)
  {
    digitalWrite(LED, HIGH);
    delay(del);
    digitalWrite(LED, LOW);
    delay(del);
  }
}
*/

void displayTemps()
{
  checkTemp();
  Serial.print("Temprerature is");
  Serial.print(celsius, 2);
  Serial.print(" deg. C / ");
  Serial.print(fahrenheit, 2);
  Serial.println (" deg. F ");
}

void loop()
{
  //blinks = checkTemp();
  //blinkLED(blinks,200);
  displayTemps();
  checkTemp();
  delay(2000);  
  
}
