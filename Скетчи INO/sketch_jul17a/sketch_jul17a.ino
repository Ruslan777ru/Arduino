
#define LED 13

int blinks = 0;


void setup()
{
  pinMode(LED, OUTPUT);
}

int checkTemp()
{
  float voltage = 0;
  float celsius = 0;
  float hotTemp = 26;
  float coldTemp = 20;
  float sensor = 0;
  
  int result;
  
  
 //считывание значений с датчика
  sensor = analogRead(0);
  voltage = (sensor*5000)/1023; 
  voltage = voltage - 500;
  celsius = voltage/10;
  
  if(celsius <= coldTemp)
  {
    result = 2;
  }
  else if(celsius > coldTemp && celsius < hotTemp)
  {
    result = 4;
  }
  else
  {
    result = 6;
  }
}


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


void loop()
{
  blinks = checkTemp();
  blinkLED(blinks,200);
  delay(2000);  
}
