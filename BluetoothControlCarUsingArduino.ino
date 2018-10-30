#define LMP  2
#define LMN  3
#define RMP  4
#define RMN  5
#define ENA  9
#define ENB  10


//int firstSensor = 0;         // first analog sensor
//int secondSensor = 0;    // second analog sensor
//int thirdSensor = 0;        // digital sensor
int inByte = 0;               // incoming serial byte
//char BYTE;
boolean status_unlock;
boolean status_bluetooth;

//long interval = 1000;           // interval at which to blink (milliseconds)
//long previousMillis = 0;        // will store last time LED was update
//int minite,sec;


void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  //pinMode(2, INPUT);   // digital sensor is on digital pin 2
  //establishContact();    // send a byte to establish contact until receiver responds 
  
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  
  digitalWrite(LMP, LOW);  // switch off MOTOR
  digitalWrite(LMN, LOW);  // switch off MOTOR
  digitalWrite(RMP, LOW);  // switch off MOTOR
  digitalWrite(RMN, LOW);  // switch off MOTOR
    

  status_bluetooth = true;
  status_unlock = false;
 // sec = 0;
}

void loop()
{
  if (Serial.available() > 0)
  {   
       
    inByte = Serial.read();                      // get incoming byte:  
     Serial.print(inByte); 
 if(inByte == 'A')
    {    
    
      analogWrite(ENA, 250);
    analogWrite(ENB, 250);
      digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
            
      inByte = 0;     
    }    
   
    if(inByte == 'B')
    {   analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, HIGH);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
    
                      
      inByte = 0;     
    }
        
    if(inByte == 'D')
    {    analogWrite(ENA, 250);
    analogWrite(ENB, 250);
       digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
          
      inByte = 0;     
    }
    
   if(inByte == 'C')
    {   analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
    
      //Serial.print('D', BYTE);                  
      inByte = 0;     
    }
       
    if(inByte == 'E')
    {   analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
      digitalWrite(LMP, LOW);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, LOW);
    
     
      //Serial.print('E', BYTE);                   
      inByte = 0;     
    }
    
  if(inByte == 'G')
    {   analogWrite(ENA, 250);
    analogWrite(ENB, 250); 
     digitalWrite(LMP, HIGH);         
      digitalWrite(LMN, LOW);
      digitalWrite(RMP, LOW);
      digitalWrite(RMN, HIGH);
        
      inByte = 0;     
    }
    
    if(inByte == 'F'){  
      analogWrite(ENA, 250);
    analogWrite(ENB, 250);  
       digitalWrite(LMP, LOW);         
      digitalWrite(LMN, HIGH);
      digitalWrite(RMP, HIGH);
      digitalWrite(RMN, LOW);
     
      
     // Serial.print('G', BYTE);  
      inByte = 0;     
    }
    
  
    
    /*if(inByte == 'S'){    
      
      Serial.print('S', BYTE);                  // send a char
      status_bluetooth = true;
      sec = 0;
          
    } */   
  } // if(Serial
  
  /*
  unsigned long currentMillis = millis();
      
              if(currentMillis - previousMillis > interval) {            
                previousMillis = currentMillis;         // save the last time you blinked the LED 
                
                sec++;
                
                if(status_unlock==true){
                
                  if(sec== 11){
                
                      digitalWrite(LED_PIN1, HIGH);        // switch on LED
                
                      delay(800);
                      digitalWrite(LED_PIN1, LOW);        // switch off LED
                
                      status_unlock = false;                  
                      sec = 0;
                  }
                }
                else sec = 0;                
                
              }
  
 */ 
    
} //Loop

/*void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('.', BYTE);                   // send a capital A
    delay(500);
  }
}

*/

