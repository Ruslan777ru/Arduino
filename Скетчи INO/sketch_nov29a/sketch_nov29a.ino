#define led1 7       //подключаем наши заголовки
#define led2 8       //для светодиодов
#define led3 9
#define led4 10
#define led5 11

const int  pin_button1 = 2;  //подключаем наши кнопки к пинам
const int  pin_button2 = 4;
int flag = 0;         //создаём флажок для определения состояний наших кнопок

long btn_clicked = 0; //задаём переменную для функции millis()

void setup() {
  
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);  //подключаем выходы наших светодиодов к пинам
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  digitalWrite(led1, LOW); //даём команду, что при включении они все у нас будут выключены
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}


void button1(int &flag)     //создаём функцию для первой кнопки и иницируем в ней наш флажок 
  
{
    if (digitalRead(pin_button1) == true && flag == 0)  //проверяем условие нажатия на нашу кнопку 1
    {
      flag = 2;                 //даём нашему флажку значение 2, которое свяжет наши действия с кнопкой 2 при включенной кнопке 1
      digitalWrite(led1, HIGH); //начинаем включать наши светодиоды с интервалом в 1 секунду
      delay(1000);
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led4, HIGH);
      delay(1000);
      digitalWrite(led5, HIGH);
      btn_clicked = millis();  //производится отсчёт времени 
    }

     if(digitalRead(pin_button2) == true && flag == 2)
     {
       flag = 0;                  //возвращаем наш флажок в начальное состояние
       digitalWrite(led1, LOW);
       delay(1000);
       digitalWrite(led2, LOW);
       delay(1000);
       digitalWrite(led3, LOW);
       delay(1000);
       digitalWrite(led4, LOW);
       delay(1000);
       digitalWrite(led5, LOW);
     }
  
    if(digitalRead(pin_button2) == false && flag == 2 && millis() - btn_clicked >= 10000) //осуществляем цикл, при котором при нажатой кнопке 1 кнопка 2 не активирована
    {                                                                                     //и ставим время ожидания до 10 секунд включительно
      flag = 0;               //сбрасываем всё до начального
      btn_clicked = 0;        //состояния
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    }
}


void button2(int &flag)    //по аналогии повторяем все те же действия, что и с кнопкой 1

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
  button1(flag);    //готовим наши функции к работе, иницируя в них наш флажок
  button2(flag);
}
