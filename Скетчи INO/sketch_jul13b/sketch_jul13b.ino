

//Вторая версия измерителя напряжения батарейки

#define bestLED  2
#define goodLED  4
#define bLED     6
#define badLED   8
#define worstLED 10

int analogValue = 0;
float voltage = 0;
int ledDelay = 2000;

void setup()
{
  pinMode (bestLED, OUTPUT);
  pinMode (goodLED, OUTPUT);
  pinMode (bLED, OUTPUT);
  pinMode (badLED, OUTPUT);
  pinMode (worstLED, OUTPUT);
}

void loop()
{
  analogValue = analogRead(0);
  voltage = 0.0048*analogValue;
  
  
  if (voltage >=1.6)
  {
    digitalWrite(bestLED, HIGH);
    delay(ledDelay);
    digitalWrite(bestLED, LOW);
  }
  
  
  else if (voltage < 1.6 && voltage >1.4)
  {
    digitalWrite(goodLED, HIGH);
    delay(ledDelay);
    digitalWrite(goodLED, LOW);
  }
  
  
  else if (voltage <=1.4 && voltage >1.2)
  {
    digitalWrite(bLED, HIGH);
    delay(ledDelay);
    digitalWrite(bLED, LOW);
  }
  
  else if (voltage <=1.2&& voltage >1.0)
  {
    digitalWrite(badLED, HIGH);
    delay(ledDelay);
    digitalWrite(badLED, LOW);
  }
  
  else if (voltage <=1.0)
  {
    digitalWrite(worstLED, HIGH);
    delay(ledDelay);
    digitalWrite(worstLED, LOW);
  } 
}
