//#include<string.h>
int led = 13;
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int H = 9;
char command[6];
void setup()  
{   
  Serial.begin(57600);   
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(H,HIGH);
}  

void loop()  
{  
   if (Serial.available()>5) // ждём дескриптор и нужный символ
   {
    if (Serial.read()=='0') // проверяем первый символ, если это '0', то продолжаем принимать, если нет, то выходим из цикла чтения 
     {
       if (Serial.read()=='x')
         {
           for (int i=0; i < 4; i++)
            {
               command[i] = Serial.read();    
            }
         }
Serial.println(command);         

     
       switch (command[0])
        {
          case 'A':
          if (command[0] == command[1])
          {            
            if (command[2] == '1') set_one(A);                
              else set_one(B);
          }
          else
          {
            if (command[2] == '1') set_two(A,C);                   
              else set_two(B,D);
          }
          break;
          
          case 'B':
            if (command[2] == '1') set_one(C);                
              else set_one(D);
          break; 
           
          case 'C':
            if (command[0] == command[1])
            {            
              if (command[2] == '1') set_one(E);                
                else set_one(F);
            }
            else
            {
              if (command[2] == '1') set_two(E,G);                   
                else set_two(F,H);
            }
          break;
          
          case 'D':
            if (command[2] == '1') set_one(G);                
                  else set_one(H);
          break;
          
        }    
     
     
     }// конец if (Serial.read()=='Y')
   } // конец чтение порта 
   
   

}

void set_one(int pin)
{
  if (command[3] == '1')
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
}

void set_two(int pin1, int pin2)
{
  if (command[3] == '1')
    {
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
    }
    else
    {
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
    }
}



