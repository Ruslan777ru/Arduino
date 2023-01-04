#define input  8
#define output 13

void setup() {
  
  pinMode(input, INPUT_PULLUP);
  pinMode(output, OUTPUT);      
  digitalWrite(output, LOW);    

  Serial.begin(9600); 
  
}

void right_button()
{
   if (digitalRead(input) == HIGH)Serial.write('0');
   else Serial.write('1');
}


void loop() {
  if(Serial.available()) {
    char data_rcvd = Serial.read();   // прочитать один байт из последовательного буфера и сохранить в data_rcvd

    if(data_rcvd == '1') digitalWrite(output, HIGH);  // включить светодиод
    if(data_rcvd == '0') digitalWrite(output, LOW);   // выключить светодиоод
  }
 right_button();
}
