int sensorPin = A0;
int sensorPin1 = A1;

int ledPins[] = { 13, 12, 8 };
int ledPins1[] = { 2, 4, 7 };

int pincount = 3;
//int pincount1 = 3;

int lightLevelRight;
int lightLevelLeft;

int lightLevel, high = 0, low = 1023;

void setup() {
  int i;
  // put your setup code here, to run once:
  Serial.begin(9600);

//  int i;
  for (int i = 0; i <= 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    //Specify the second list of arrayed pins as an output.
    pinMode(ledPins1[i], OUTPUT);
  }

  //"Serial.begin" performs an exchange of data between the arduino and a 
  //sensor. In this case the photo resistors will capture date.
}

void loop() {
  int i;
  //Refers to the order of the LEDs
  lightLevelRight = analogRead(sensorPin1);
  lightLevelLeft = analogRead(sensorPin);
  //Set lightLevelRight and lightLevelLeft to equate to the data received by the arduino from the
  //left and right light resisters.
  manualTune();
  Serial.println(lightLevelRight);

  // if lightlevel changes -> turn on the right bank
  if (lightLevelRight <= 500) {
    for (int i = 0; i <= pincount; i++){
      digitalWrite(ledPins1[i], HIGH);
    }
  } else {
    for (int i = 0; i <= pincount; i++){
      digitalWrite(ledPins1[i], LOW);
    }
  }
  if (lightLevelLeft <=500) {
    for (int i = 0; i <= pincount; i++){
      digitalWrite(ledPins[i], HIGH);
    }
  } else {
    for (int i = 0; i <= pincount; i++){
      digitalWrite(ledPins[i], LOW);
    }
  }
  // if lightlevel1 changes -> turn on the left bank

/*  if (1 = 0) {
    digitalWrite(ledPins[0], HIGH);
  } else if (0 = 0) {
    digitalWrite(ledPins[1], HIGH);
  }
  
*/
}

void manualTune() 
{
  lightLevel = map(lightLevel, 0, 1023, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
}