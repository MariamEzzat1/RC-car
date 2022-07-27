 /*****************************
1 ===> FORWARD MOTOR
2 ===> BACKWARD MOTOR
3 ===> LIFT DIRECTION
4 ===> RIGHT DIRECTION
S ===> STOP MOTOR
6 ===> LINE FOLLOWER MODE
7 ===> CLIMBING MODE
8 ===> TURN OFF SYSTEMS
****************************/



#include <Servo.h>
Servo esc_signal;

/**********  motor pins  **********/
#define en1 9
#define in1 8
#define in2 7
#define en2 3
#define in3 5
#define in4 4
/**********************************/

/**********  IR sensors  **********/
#define LS 10      // left sensor
#define RS 11      // right sensor

/*********************************/

char var ;  //serial value

void setup() {
  /**********  MOTOR pins directions  **********/
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (en1, OUTPUT);
  pinMode (en2, OUTPUT);
/******************************************/
  
/**********  ESC initialization  **********/
  esc_signal.attach(12);  
  esc_signal.write(30);   
  delay(3000);  
/******************************************/

  Serial.begin (9600);
}

void loop() {
   if (Serial.available () > 0)
   {
    var = Serial.read ();
   }
   if(var == '1')
   {
/*************** FORWARD *******************/    
      digitalWrite (en1, HIGH);
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (en2, HIGH);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
/******************************************/      
    }
    else if(var == '3')
    {
/****************  LEFT  *******************/      
      digitalWrite (en1, HIGH);
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (en2, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
/******************************************/      
      }
    else if(var == '2')
    {
/**************  BACKWARD  ***************/      
      digitalWrite (en1, HIGH);
      digitalWrite (in1, LOW);
      digitalWrite (in2, HIGH);
      digitalWrite (en2, HIGH);
      digitalWrite (in3, LOW);
      digitalWrite (in4, HIGH);
/******************************************/      
      }
    else if(var == '4')
    {
/****************  RIGHT  *****************/      
      digitalWrite (en1, LOW);
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW); 
      digitalWrite (en2, HIGH);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
      }
      else if(var == '5')
    {
/****************  STOP   ****************/      
      digitalWrite (en1, LOW);
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW);   
      digitalWrite (en1, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
/******************************************/      
      }
      else if(var == '6')
    {
 /**********  LINE FOLLOWER  **************/     
      if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
      digitalWrite (en1, HIGH);
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (en2, HIGH);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
      digitalWrite (en1, LOW);
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW); 
      digitalWrite (en2, HIGH);
      digitalWrite (in3, HIGH);
      digitalWrite (in4, LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
      digitalWrite (en1, HIGH);
      digitalWrite (in1, HIGH);
      digitalWrite (in2, LOW);
      digitalWrite (en2, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
      digitalWrite (en1, LOW);
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW);   
      digitalWrite (en1, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
  }
/******************************************/
      }
      else if(var == '7')
    {
/************  CLIMBING   *****************/      
      esc_signal.write(120);
      delay(15);
/******************************************/      
      }
      else if(var == '8')
    {
/****************  STOP   ****************/      
      digitalWrite (en1, LOW);
      digitalWrite (in1, LOW);
      digitalWrite (in2, LOW);   
      digitalWrite (en1, LOW);
      digitalWrite (in3, LOW);
      digitalWrite (in4, LOW);
      esc_signal.write(0);
      delay(15);
/******************************************/
      
}
}
