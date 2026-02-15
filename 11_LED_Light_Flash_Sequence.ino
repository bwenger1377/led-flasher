//11-LED Light Flashing Sequence
//Written by Benjamin Wenger on 12-25-2025
//Last Updated 12-28-2025

//Define Pin Locations
const int R1 = 13;
const int W1 = 12;
const int R2 = 11;
const int W2 = 10;
const int R3 = 9;
const int W3 = 8;
const int R4 = 7;
const int BL1 = 6;
const int BL2 = 5;
const int BL3 = 4;
const int BL4 = 3;

//Define Light Groupings
int red_lights[] = {R1,R2,R3,R4};
int white_lights[] = {W1,W2,W3};
int blue_lights[] = {BL1,BL2,BL3,BL4};
int all_lights[] = {R1,R2,R3,R4,W1,W2,W3,BL1,BL2,BL3,BL4};

//Define a macro to find the length of any array
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

//Initialize length variables using the above macro
int red_length = ARRAY_LENGTH(red_lights);
int white_length = ARRAY_LENGTH(white_lights);
int blue_length = ARRAY_LENGTH(blue_lights);
int all_length = ARRAY_LENGTH(all_lights);

//Function to flash one LED
void light_flash(int pin, int duration) {
  digitalWrite(pin,HIGH);
  delay(duration);
  digitalWrite(pin,LOW);
}

//Function to flash an array of LEDs
void lights_flash(int pins[], int length, int duration) {
  for (int ii = 0; ii < length; ii++) {
    digitalWrite(pins[ii],HIGH);
  }
  delay(duration);
  for (int ii = 0; ii < length; ii++) {
    digitalWrite(pins[ii],LOW);
  }
}

//Function to print any array of values to the serial monitor
void arr_print(int array[], int length) {
  for (int ii = 0; ii < length; ii++) {
    Serial.print(array[ii]); 
    Serial.print('\t');
  }
  Serial.println();
}

void setup() {
  //Set Baudrate
  Serial.begin(115200);

  //Delay 5 seconds to establish a connection with the USB port
  delay(5000);

  //Print Hello World to Verify Serial function
  Serial.println("Hello World");

  //Declare pins as inputs or outputs
  for (int ii = 0; ii < all_length; ii++) {
      pinMode(all_lights[ii],OUTPUT);
  }

  //Initialize Light States
  for (int ii = 0; ii < all_length; ii++) {
      digitalWrite(all_lights[ii],LOW);
  }

  //Tell User all lights are off
  Serial.println("All lights are off.");

  //Print all combinations of lights
  arr_print(all_lights,all_length);
  arr_print(red_lights,red_length);
  arr_print(white_lights,white_length);
  arr_print(blue_lights,blue_length);
}

void loop() {
  //Flash all lights
  lights_flash(all_lights,all_length,500);

  //Flash red lights
  lights_flash(red_lights,red_length,500);

  //Flash white lights
  lights_flash(white_lights,white_length,500);

  //Flash blue lights
  lights_flash(blue_lights,blue_length,500);

  //Flash all lights twice
  for (int ii = 1; ii < 3; ii++) {
    lights_flash(all_lights,all_length,500);
    delay(500);
  }

  //Flash each light individually starting with R1 and ending with BL4
  for (int ii = 0; ii < all_length; ii++) {
    light_flash(all_lights[ii],100);
  }
}