
//датчик и порт

#define del 100

float celsius = 0;
float fahrenheit = 0;

void setup()
{
  Serial.begin(9600);
}

void findTemps()
{
  float voltage = 0;
  float sensor = 0;
  
  sensor = analogRead(0);
  voltage = (sensor*5000)/1024;
  voltage = voltage - 500;
  celsius = voltage / 10;
  fahrenheit = celsius * 1.8 + 32;
    
}

void displayTemps()
{
  Serial.print("Temperature is ");
  Serial.print(celsius, 4);
  Serial.print(" deg. C / ");
  Serial.print(fahrenheit, 4);
  Serial.println(" deg. F");
}

void loop()
{
  findTemps();
  displayTemps();
  delay(del);
}
