#define hotLED  2
#define coolLED 6
#define coldLED 4
#define delel   200

using namespace std;

void setup()
{
  Serial.begin(9600);
  pinMode(hotLED,OUTPUT);
  pinMode(coolLED, OUTPUT);
  pinMode(coldLED, OUTPUT);
}

class Termo 
{
  public: 
    
  float voltage = 0;
  float celsius = 0;
  float hotTemp = 26;
  float coldTemp = 20;
  float sensor = 0;
  float fahrenheit = 0;

  /*
  Termo(float voltage, float celsius, float hotTemp, float coldTemp, float sensor, float fahrenheit) 
        {
          this->voltage = voltage;
          this->celsius = celsius;
          this->hotTemp = hotTemp;                                          Вдруг кто-то захочет поэкспериментировать, поэтому вот
          this->coldTemp = coldTemp;
          this->sensor = sensor;
          this->fahrenheit = fahrenheit;
        }
   */
};



class checkTemp : public Termo
{
  public:

  //checkTemp(float voltage, float celsius, float hotTemp, float coldTemp, float sensor, float fahrenheit): Termo(voltage, celsius, hotTemp, coldTemp, sensor, fahrenheit){}
  
  
    void check()
    {
       sensor = analogRead(0);
       voltage = (sensor*5000)/1023; 
       voltage = voltage - 500;
       celsius = voltage/10;
       fahrenheit = (1.8*celsius)+32;
  
       if(celsius <= coldTemp)
        {
          //result = 2; //без светодиодов (лампочка горит на Ардуино
          digitalWrite(coldLED, HIGH);  //модификация со светодиодами
          delay(delel);
          digitalWrite(coldLED, LOW);
          delay(delel);
        }
      
       else if(celsius > coldTemp && celsius < hotTemp)
        {
          //result = 4;
          digitalWrite(coolLED, HIGH); //модификация со светодиодами
          delay(delel);
          digitalWrite(coolLED, LOW);
          delay(delel);
        }
      
        else
        {
          //result = 6;
          digitalWrite(hotLED, HIGH); //модификация со светодиодами
          delay(delel);
          digitalWrite(hotLED, LOW);
          delay(delel);
        }
    }
    
    void display()
    {
       Serial.print("Temprerature is ");
       Serial.print(celsius, 2);
       Serial.print(" deg. C / ");
       Serial.print(fahrenheit, 2);
       Serial.println (" deg. F ");
    }
};
    



void loop()
{
    /*class Termo
    {
     display();
      check();      это бред здесь написан. Оставил как напоминание, что так писать тупо :D
      };
 
      delay(2000); 
      */


  checkTemp Indication;

  Indication.check();
  Indication.display();

      
}
