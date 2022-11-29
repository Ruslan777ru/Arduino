#define led1 7
#define led2 8
#define led3 9
#define led4 10
#define led5 11

int  pin_button1 = 2;  //подключаем наши кнопки к пинам
int  pin_button2 = 4;
int flag = 0;         //создаём флажок для определения состояний наших кнопок

int btn_clicked = 0; //задаём переменную для функции millis()

void setup() {
  
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}


void button1(int &flag) 
  
{
    if (digitalRead(pin_button1) == true && flag == 0)
    {
      flag = 2;
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led4, HIGH);
      delay(1000);
      digitalWrite(led5, HIGH);
      delay(3000);
      btn_clicked = millis();  //производится отсчёт времени
    }

     if(digitalRead(pin_button2) == true && flag == 2)
     {
       flag = 0;
       digitalWrite(led1, LOW);
       delay(1000);
       digitalWrite(led2, LOW);
       delay(1000);
       digitalWrite(led3, LOW);
       delay(1000);
       digitalWrite(led4, LOW);
       delay(1000);
       digitalWrite(led5, LOW);
       //delay(3000);
     }
  
    if(digitalRead(pin_button2) == false && flag == 2 && millis() - btn_clicked >= 10000)
    {
      flag = 0;               //сбрасываем всё до начального
      btn_clicked = 0;        //состояния
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
}


void button2(int &flag)

{
  if (digitalRead(pin_button2) == true && flag == 0)
    {
      flag = 1;
     
      digitalWrite(led5, HIGH);
      delay(1000);
      digitalWrite(led4, HIGH);
      delay(1000);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led1,HIGH);
      delay(3000);
      btn_clicked = millis();
    }

     if(digitalRead(pin_button1) == true && flag == 1)
     {
       flag = 0;
       
       digitalWrite(led5, LOW);
       delay(1000);
       digitalWrite(led4, LOW);
       delay(1000);
       digitalWrite(led3, LOW);
       delay(1000);
       digitalWrite(led2, LOW);
       delay(1000);
       digitalWrite(led1, LOW);
     }
  
    if(digitalRead(pin_button1) == false && flag == 1 && millis() - btn_clicked >= 10000)
    {
      flag = 0;
      btn_clicked = 0;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
}



void loop()
{   
  button1(flag);    
  button2(flag);
}
