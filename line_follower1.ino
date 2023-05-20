const int sensor_LEFT =2 ; // digital pin for  LEFT sensor 
const int sensor_RIGHT=13; // digital pin for  RIGHT sensor 


const int en1 = 9; // Left motor control pin
const int en2 = 10; // Right motor control pin
const int LM1 = 4; //M1 IN2 ()
const int LM2 = 5; //M1 IN1  ()
const int RM3 = 7; // M2 IN1 ()
const int RM4 = 6; //M2 IN2 ()
//const int threshold = 500; // Sensor threshold value for black/white detection

void setup() {
  pinMode(sensor_LEFT, INPUT);
  pinMode(sensor_RIGHT, INPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM3, OUTPUT);
  pinMode(RM4, OUTPUT);
  
}

void loop() {
  int sensor_valLEFT = digitalRead(sensor_LEFT);
  int sensor_valRIGHT = digitalRead(sensor_RIGHT);
  

  
  if (sensor_valLEFT==0) { // It Detects white part in left sensor or black part in right sensor and turn the  left motor in forward & right motor in reverse 
    // Turn left
    analogWrite(en1, 150);//HIGH
    digitalWrite(LM1, LOW);//HIGH
    digitalWrite(LM2,HIGH);//LOW
    analogWrite(en2,150);//HIGH
    digitalWrite(RM3,HIGH); //LOW
    digitalWrite(RM4,LOW);//HIGH           
  } else if (sensor_valRIGHT==0) { // It Detects white part  in right sensor or black part in left sensor and turn the  right motor in forward & left motor in reverse 
    // Turn right
    analogWrite(en2, 150);//HIGH
    digitalWrite(RM3, LOW);//HIGH
    digitalWrite(RM4,HIGH);//LOW
    analogWrite(en1,150);//HIGH
    digitalWrite(LM1,HIGH);//LOW
    digitalWrite(LM2,LOW);//HIGH       
  } else if (sensor_valLEFT==0 && sensor_valRIGHT==0) { //It Detects  white part in both sensor & turns both motor in forward direction & Go straight
    analogWrite(en1, 150);//HIGH
    digitalWrite(LM2, LOW);//HIGH
    digitalWrite(LM1,HIGH);//LOW
    analogWrite(en2, 150);//HIGH
    digitalWrite(RM4, LOW);//HIGH
    digitalWrite(RM3,HIGH);//LOW
  } else {  //Detects black part in both sensor
    // Stop
    analogWrite(en1,150);//HIGH
    analogWrite(en2,150);//HIGH
    digitalWrite(LM1,LOW);//LOW
    digitalWrite(LM2,LOW);//LOW
    digitalWrite(RM3,LOW);//LOW
    digitalWrite(RM4,LOW);//LOW
  }
}

