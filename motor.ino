#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP32.h>

//Motor A
String serialStr;
int enableA = 23; //motor A
int pinA1 = 19;
int pinA2 = 18;

//Motor B
int enableB = 5;  //motor B
int pinB1 = 26;
int pinB2 = 25;

//define time for run
// in milliseconds
int running = 10000; // 10 seconds
boolean play;

char ssid[] = "UMR-LAB_2";
char wifiPassword[] = "Ubon2565";

//website > create esp8266 > copy data and paste below.
char username[] = "be1f8690-a5ee-11ed-b193-d9789b2af62b";
char password[] = "9912a0cce4ba397137e6b3db0612b8310a5de679";
char clientID[] = "cdefd8f0-a5f2-11ed-8d53-d7cd1025126a";

void setup() {
  Serial.begin(9600);
  //Config pin modes
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);

}

void loop() {
  Cayenne.loop();
  delay(2000);
}

//forward
CAYENNE_IN(10){
  int i = getValue.asInt();
  if (i == 1) { 
    digitalWrite(enableA, HIGH);
    digitalWrite(pinA1, HIGH);
    digitalWrite(pinA2, LOW);
    digitalWrite(enableB, HIGH);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, HIGH);
    }
  else {
    digitalWrite(enableA, LOW);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(enableB, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
  }
}

//backward
CAYENNE_IN(15){
  int i = getValue.asInt();
  if (i == 1) { 
    digitalWrite(enableA, HIGH);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(enableB, HIGH);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
    delay(1000);
    }
  else {
    digitalWrite(enableA, LOW);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(enableB, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
  }
}

//left
CAYENNE_IN(20){
  int i = getValue.asInt();
  if (i == 1) { 
    digitalWrite(enableA, HIGH);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, HIGH);
    digitalWrite(enableB, LOW);
    }
  else {
    digitalWrite(enableA, LOW);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(enableB, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
  }
}

//right
CAYENNE_IN(25){
  int i = getValue.asInt();
  if (i == 1) { 
    digitalWrite(enableB, HIGH);
    digitalWrite(pinB1, HIGH);
    digitalWrite(pinB2, LOW);
    digitalWrite(enableA, LOW);
    }
  else {
    digitalWrite(enableA, LOW);
    digitalWrite(pinA1, LOW);
    digitalWrite(pinA2, LOW);
    digitalWrite(enableB, LOW);
    digitalWrite(pinB1, LOW);
    digitalWrite(pinB2, LOW);
  }
}
