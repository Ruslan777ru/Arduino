
//Простой тестер температурного датчика TMP36

#define HOT     6
#define NORMAL  4 
#define COLD    2

float voltage = 0;
float celsius = 0;
float hotTemp = 26;
float coldTemp = 20;
float sensor = 0;


void setup()
{
  pinMode(HOT, OUTPUT);
  pinMode(NORMAL, OUTPUT);
  pinMode (COLD, OUTPUT);
}

void loop()
{
  sensor = analogRead(0);
  voltage = (sensor*5000)/1024;
  voltage = voltage - 500;
  celsius = voltage / 10;
  
  
  if (celsius < coldTemp)
  {
    digitalWrite(COLD, HIGH);
    delay(1000);
    digitalWrite(COLD, LOW);
  }
  
  
  else if (celsius > coldTemp && celsius <= hotTemp)
  {
    digitalWrite(NORMAL, HIGH);
    delay(1000);
    digitalWrite(NORMAL, LOW);
  }
  else
  {
    digitalWrite(HOT, HIGH);
    delay(1000);
    digitalWrite(HOT, LOW);
  }
  
}
