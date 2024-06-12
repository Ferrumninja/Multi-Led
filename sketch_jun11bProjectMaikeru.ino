int sensorPin = A0;
int sensorPin1 = A1;

int ledPins[] = { 13, 12, 8 };
int ledPins1[] = { 2, 4, 7 };

int pincount = 3;

//int lightLevel, high = 0, low = 1023;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int index;
  for (index = 0; index <= 3; index++) {
    pinMode(ledPins[index], OUTPUT);
    //Specify the second list of arrayed pins as an output.
    pinMode(ledPins1[index], OUTPUT);
  }

  //"Serial.begin" performs an exchange of data between the arduino and a 
  //sensor. In this case the photo resistors will capture date.
}

void loop() {
  int index;
  //Refers to the order of the LEDs
  //lightLevelRight = analogRead(sensorPin1);
  //lightLevelLeft = analogRead(sensorPin);
  //Set lightLevel to equate to the data received by the arduino from the
  //first light resister.
  //  manualTune();
  for (index = 0; index <= pincount; index++) {
    digitalWrite(ledPins[index], HIGH);
    digitalWrite(ledPins1[index], HIGH);
  }

  // if lightlevel changes -> turn on the left bank

  // if lightlevel1 changes -> turn on the right bank

/*  if (1 = 0) {
    digitalWrite(ledPins[0], HIGH);
  } else if (0 = 0) {
    digitalWrite(ledPins[1], HIGH);
  }
  
*/
}

void manualTune() {
  /*
  in here write the manual tune from the dog ass code
  */
}