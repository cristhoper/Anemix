#include <EEPROM.h>

#define STEP 1000

// set the ledPins
int RGB1_pin[3]={9,10,11};
int RGB2_pin[3]={3,5,6};

// Set initial color
int redVal1 = 0, grnVal1 = 0, bluVal1 = 0;
int redVal2 = 0, grnVal2 = 0, bluVal2 = 0;


int loopCount = 60; // How often should DEBUG report?
int repeat = 3;     // How many times should we loop before stopping? (0 for no stop)
int j = 0;          // Loop counter for repeat

// Initialize color variables
int prevR1 = redVal1;
int prevG1 = grnVal1;
int prevB1 = bluVal1;

int prevR2 = redVal2;
int prevG2 = grnVal2;
int prevB2 = bluVal2;

int
RGB11[3] = {EEPROM.read(1),EEPROM.read(2),EEPROM.read(3)},
RGB12[3] = {EEPROM.read(4),EEPROM.read(5),EEPROM.read(6)},
RGB13[3] = {EEPROM.read(7),EEPROM.read(8),EEPROM.read(9)},
RGB14[3] = {EEPROM.read(10),EEPROM.read(11),EEPROM.read(12)},
RGB15[3] = {EEPROM.read(13),EEPROM.read(14),EEPROM.read(15)},
RGB21[3] = {EEPROM.read(16),EEPROM.read(17),EEPROM.read(18)},
RGB22[3] = {EEPROM.read(19),EEPROM.read(20),EEPROM.read(21)},
RGB23[3] = {EEPROM.read(22),EEPROM.read(23),EEPROM.read(24)},
RGB24[3] = {EEPROM.read(25),EEPROM.read(26),EEPROM.read(27)},
RGB25[3] = {EEPROM.read(28),EEPROM.read(29),EEPROM.read(30)};

int
T1[2] = {EEPROM.read(31),EEPROM.read(32)},
T2[2] = {EEPROM.read(33),EEPROM.read(34)},
T3[2] = {EEPROM.read(35),EEPROM.read(36)},
T4[2] = {EEPROM.read(37),EEPROM.read(38)},
T5[2] = {EEPROM.read(39),EEPROM.read(40)};

int i = 0;
// Program variables

void(* resetFunc) (void) = 0; 

void setup(){
    
    Serial.begin(9600);
    
    pinMode(RGB1_pin[0], OUTPUT);
    pinMode(RGB1_pin[1], OUTPUT);
    pinMode(RGB1_pin[2], OUTPUT);
    
    pinMode(RGB2_pin[0], OUTPUT);
    pinMode(RGB2_pin[1], OUTPUT);
    pinMode(RGB2_pin[2], OUTPUT);

}

void loop(){
  crossFade(RGB11,RGB21,T1);
  crossFade(RGB12,RGB22,T2);
  crossFade(RGB13,RGB23,T3);
  crossFade(RGB14,RGB24,T4);
  crossFade(RGB15,RGB25,T5);
}


void communication(){
  char serialRcvString_arr[30];
  
  // inData = HN#FFFFFF#FFFFFF|NN-NG

  Serial.println("A");
  delay(300);
  memset(serialRcvString_arr, 0, 30);
  while(Serial.available()>0) {
    int k = 0;
    k = Serial.readBytesUntil('G', serialRcvString_arr, Serial.available());
    if (k >= 20) {

      int color1R=0,color1G=0,color1B=0,color2R=0,color2G=0,color2B=0,colorTu=0,colorTf=0;
      char str_color[10];
      memset(str_color, 0, 10);
      
      strncpy(str_color,serialRcvString_arr+3,2); color1R = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
      strncpy(str_color,serialRcvString_arr+5,2); color1G = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
      strncpy(str_color,serialRcvString_arr+7,2); color1B = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
    
      strncpy(str_color,serialRcvString_arr+10,2); color2R = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
      strncpy(str_color,serialRcvString_arr+12,2); color2G = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
      strncpy(str_color,serialRcvString_arr+14,2); color2B = (int)strtol(str_color, NULL, 16);memset(str_color, 0, 10);
    
      if(serialRcvString_arr[18]=='-'){
        strncpy(str_color,serialRcvString_arr+17,1); colorTu = (int)strtol(str_color, NULL, 10);memset(str_color, 0, 10);
        strncpy(str_color,serialRcvString_arr+19,1); colorTf = (int)strtol(str_color, NULL, 10);
      }
      else{
        strncpy(str_color,serialRcvString_arr+17,2); colorTu = (int)strtol(str_color, NULL, 10);memset(str_color, 0, 10);
        strncpy(str_color,serialRcvString_arr+20,1); colorTf = (int)strtol(str_color, NULL, 10);
      }
    
      switch(serialRcvString_arr[1]){
        case '1':
          RGB11[0] = color1R; RGB11[1] = color1G; RGB11[2] = color1B;
          RGB21[0] = color2R; RGB21[1] = color2G; RGB21[2] = color2B;
          T1[0] = colorTu; T1[1] = colorTf;
          EEPROM.write(1,RGB11[0]);EEPROM.write(2,RGB11[1]);EEPROM.write(3,RGB11[2]);
          EEPROM.write(16,RGB21[0]);EEPROM.write(17,RGB21[1]);EEPROM.write(18,RGB21[2]);
          EEPROM.write(31,T1[0]);EEPROM.write(32,T1[1]);
          Serial.println("B");
          break;
        case '2':
          RGB12[0] = color1R; RGB12[1] = color1G; RGB12[2] = color1B;
          RGB22[0] = color2R; RGB22[1] = color2G; RGB22[2] = color2B;
          T2[0] = colorTu; T2[1] = colorTf;
          EEPROM.write(4,RGB12[0]);EEPROM.write(5,RGB12[1]);EEPROM.write(6,RGB12[2]);
          EEPROM.write(19,RGB22[0]);EEPROM.write(20,RGB22[1]);EEPROM.write(21,RGB22[2]);
          EEPROM.write(33,T2[0]);EEPROM.write(34,T2[1]);
          Serial.println("C");
          break;
        case '3':
          RGB13[0] = color1R; RGB13[1] = color1G; RGB13[2] = color1B;
          RGB23[0] = color2R; RGB23[1] = color2G; RGB23[2] = color2B;
          T3[0] = colorTu; T3[1] = colorTf;
          EEPROM.write(7,RGB13[0]);EEPROM.write(8,RGB13[1]);EEPROM.write(9,RGB13[2]);
          EEPROM.write(22,RGB23[0]);EEPROM.write(23,RGB23[1]);EEPROM.write(24,RGB23[2]);
          EEPROM.write(35,T3[0]);EEPROM.write(36,T3[1]);
          Serial.println("D");
          break;
        case '4':
          RGB14[0] = color1R; RGB14[1] = color1G; RGB14[2] = color1B;
          RGB24[0] = color2R; RGB24[1] = color2G; RGB24[2] = color2B;
          T4[0] = colorTu; T4[1] = colorTf;
          EEPROM.write(10,RGB14[0]);EEPROM.write(11,RGB14[1]);EEPROM.write(12,RGB14[2]);
          EEPROM.write(25,RGB24[0]);EEPROM.write(26,RGB24[1]);EEPROM.write(27,RGB24[2]);
          EEPROM.write(37,T4[0]);EEPROM.write(38,T4[1]);
          Serial.println("E");
          break;
        case '5':
          RGB15[0] = color1R; RGB15[1] = color1G; RGB15[2] = color1B;
          RGB25[0] = color2R; RGB25[1] = color2G; RGB25[2] = color2B;
          T5[0] = colorTu; T5[1] = colorTf;
          EEPROM.write(13,RGB15[0]);EEPROM.write(14,RGB15[1]);EEPROM.write(15,RGB15[2]);
          EEPROM.write(28,RGB25[0]);EEPROM.write(29,RGB25[1]);EEPROM.write(30,RGB25[2]);
          EEPROM.write(39,T5[0]);EEPROM.write(40,T5[1]);
          Serial.flush();
          Serial.println("F");
          break;
      }
    }
    delay(300);
  }
}

int calculateStep(int prevValue, int endValue) {
  int step = endValue - prevValue; // What's the overall gap?
  if (step) {                      // If its non-zero, 
    step = STEP/step;              //   divide by 1020
  } 
  return step;
}

int calculateVal(int step, int val, int i) {

  if ((step) && i % step == 0) { // If step is non-zero and its time to change a value,
    if (step > 0) {              //   increment the value if step is positive...
      val += 1;           
    } 
    else if (step < 0) {         //   ...or decrement it if step is negative
      val -= 1;
    } 
  }
  // Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  } 
  else if (val < 0) {
    val = 0;
  }
  return val;
}

void crossFade(int color1[3],int color2[3], int dutytime[2]) {
  
  communication();
 
  if(dutytime[1]==0 && dutytime[0] == 0 && color1[0]==0 && color1[1]==0 && color1[2]==0 && color2[0]==0 && color2[1]==0 && color2[2]==0) return;
  
  int stepR1 = calculateStep(prevR1, color1[0]);
  int stepG1 = calculateStep(prevG1, color1[1]);
  int stepB1 = calculateStep(prevB1, color1[2]);
  
  int stepR2 = calculateStep(prevR2, color2[0]);
  int stepG2 = calculateStep(prevG2, color2[1]);
  int stepB2 = calculateStep(prevB2, color2[2]);

  for (int i = 0; i <= STEP; i++) {

    redVal1 = calculateVal(stepR1, redVal1, i);
    grnVal1 = calculateVal(stepG1, grnVal1, i);
    bluVal1 = calculateVal(stepB1, bluVal1, i);

    redVal2 = calculateVal(stepR2, redVal2, i);
    grnVal2 = calculateVal(stepG2, grnVal2, i);
    bluVal2 = calculateVal(stepB2, bluVal2, i);

    
    analogWrite(RGB1_pin[0], redVal1);   // Write current values to LED pins
    analogWrite(RGB1_pin[1], grnVal1);      
    analogWrite(RGB1_pin[2], bluVal1);
    
    analogWrite(RGB2_pin[0], redVal2);   // Write current values to LED pins
    analogWrite(RGB2_pin[1], grnVal2);      
    analogWrite(RGB2_pin[2], bluVal2); 

    delay(dutytime[1]); // Pause for 'wait' milliseconds before resuming the loop

  }
  // Update current values for next loop
  prevR1 = redVal1; 
  prevG1 = grnVal1; 
  prevB1 = bluVal1;
  
  prevR2 = redVal2; 
  prevG2 = grnVal2; 
  prevB2 = bluVal2;
  delay(dutytime[0]*1000); // Pause for optional 'wait' milliseconds before resuming the loop
}

