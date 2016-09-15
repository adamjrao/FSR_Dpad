/*
 * FSR D-pad
 * Author: Adam Rao
 * Function: This code utilizes the principle of double thresholding to track the state of 4 FSR sensors
*/

// do not use the cloud functions - assume programming through Arduino IDE
#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

const int threshold1 = 1200;    // Lower threshold
const int threshold2 = 1300;    // Upper threshold
int UP = A0;
int DOWN = A2;
int LEFT = A1;
int RIGHT = A3;

void setup() {
pinMode(UP,INPUT_PULLDOWN);
pinMode(DOWN,INPUT_PULLDOWN);
pinMode(LEFT,INPUT_PULLDOWN);
pinMode(RIGHT,INPUT_PULLDOWN);
}

void loop() {
    // Define variables to track the state of each button
    int UP_val = 0;
    int DOWN_val = 0;
    int LEFT_val = 0;
    int RIGHT_val = 0;
    
    if (analogRead(UP) > threshold2) {
      // if at any point the sensor reading exceeds the upper threshold the button is pressed
      UP_val = 1;
    }
    if (analogRead(UP) < threshold1) {
      // if at any point the sensor reading is lower than the lower threshold the button is not pressed
      UP_val = 0;
    }
    else {
      // if the sensor reading is between the two threshold values then its state is whatever it was previously
      UP_val = UP_val;
    }
    if (analogRead(DOWN) > threshold2) {
      DOWN_val = 1;
    }
    if (analogRead(DOWN) < threshold1) {
      DOWN_val = 0;
    }
    else {
      DOWN_val = DOWN_val;
    }
    if (analogRead(LEFT) > threshold2) {
      LEFT_val = 1;
    }
    if (analogRead(LEFT) < threshold1) {
      LEFT_val = 0;
    }
    else {
      LEFT_val = LEFT_val;
    }
    if (analogRead(RIGHT) > threshold2) {
      RIGHT_val = 1;
    }
    if (analogRead(RIGHT) < threshold1) {
      RIGHT_val = 0;
    }
    else {
      RIGHT_val = RIGHT_val;
    }
    
    //Print status of buttons
    if (UP_val){
      Serial.println("Up");
      Serial.println(analogRead(UP));
    }
    if (DOWN_val){
      Serial.println("Down");
      Serial.println(analogRead(DOWN));
    }
    if (LEFT_val){
      Serial.println("Left");
      Serial.println(analogRead(LEFT));
    }
    if (RIGHT_val){
      Serial.println("Right");
      Serial.println(analogRead(RIGHT));
    }
    
}
