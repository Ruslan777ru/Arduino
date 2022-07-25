
//Умножение числа на два

int number;

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  number = 0; //обнуляем переменную, подготовив 
          //её к принятию нового числа
  
  Serial.flush(); //отчищаем буфер порта от мусора перед ожиданием
  
  while(Serial.available() == 0){} //ничего не делаем, пока число != 0
  
  while (Serial.available() > 0)
  {
    number = Serial.read() - '0';
    //Прочитать цифру из буфера порта,
    //вычесть ASCII - кода цифры
    //код символа '0', чтобы получить число
    
  }
  
  Serial.print("You entered: ");
  Serial.println(number);
  Serial.print(number);
  Serial.print(" multiplied by two is ");
  number = number * 2;
  Serial.println(number);
}
