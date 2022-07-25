
// ************** СВЕТОДИОДНЫЙ КУБИК ****************

#define redLED    3
#define blueLED   2
#define orangeLED 1
#define yellowLED 4
#define whiteLED  5
#define greenLED  6

#define del       50

void setup()
{
  //pinMode(redLED, OUTPUT);     здесь я просто проверял
  //pinMode(blueLED, OUTPUT);    светодиоды, чтоб те не рванули.
  //pinMode(orangeLED, OUTPUT);  Прикол в том, что без резистора 
  //pinMode(yellowLED, OUTPUT);  будет папандос всей конструкции,
  //pinMode(whiteLED, OUTPUT);   в том числе и самой ардуинке.
  //pinMode(greenLED, OUTPUT);   Чтоб не отхватить от родителей -
  //               используйте резисторы ;D
  
  randomSeed(analogRead(0));
  
  for(int z = 1; z < 7; z++)  pinMode(z,OUTPUT);

}


void randomLED(int LED)
{
  int r;
  r = random(1,7);
  digitalWrite(r,HIGH);
  
  if(del > 0) delay(del);
    
  
  else if (del == 0)
  {
    do
    {}
    while(1);
  }
  digitalWrite(r, LOW);                 
}



void loop()
{
  //digitalWrite(redLED, 1);
  int a;
  
  for( a = 0; a < 100; a++) randomLED(del + 50);
  
  for( a = 1; a <= 10; a++) randomLED(a * 100);
  
  randomLED(0);
}
