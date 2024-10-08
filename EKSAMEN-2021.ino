//EKSAMEN DES. 2021
//DEL 2 

//OPPG. 3)
const int potPin = A0;
//-------------------

const int butnPin = 3;
const int redLedPin = 7;
const int blueLedPin = 8;

bool pressed = false;
unsigned int lastPressed;
//------Oppg. 5---------
struct Student{
  String Navn;
  unsigned long Tlf;
  bool Betalt;
};


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(potPin, INPUT);
pinMode(butnPin, INPUT);

pinMode(redLedPin, OUTPUT);
pinMode(blueLedPin, OUTPUT);
//Til oppg. 4
attachInterrupt(digitalPinToInterrupt(butnPin), butnInterrupt, CHANGE); //

}

void loop() {
  // put your main code here, to run repeatedly:
  //Oppg. 3a)
  /*
  int potVal = analogRead(potPin);
  delay(3000);
  Serial.println(potVal);
  */
//Oppg 3b)
/*
int potValues[200];
for(int i = 0, i < 200; i++){
  potValues[i] = analogRead(potPin);
  delay(10);
}
for(int i = 0; i < 200; i++){
  if(potValues[i] > 500){
    Serial.println(potValues[i]);
  }
}
long potSum;
for(int i = 0, i < 200; i++){
  potSum += potValues[i];
}
Serial.println(potSum);
while(1){}

*/
//Oppg. 4)

static bool redState = LOW;
static bool blueState = LOW;

if(pressed == true){
  redState = HIGH;
  if(millis() > lastPressed + 1000){
    blueState = HIGH; 
  }
}
else{
  redState = LOW;
  blueState = LOW;
}

digitalWrite(redLedPin, redState);
digitalWrite(blueLedPin, blueState);


//Oppg. 5
Student studenter[100];



}


//Oppg. 4
void butnInterrupt(){
  if(digitalRead(butnPin) == HIGH){
    pressed = true; 
    lastPressed = millis();
  }
  else{
    pressed = false;
  }
}

//Oppg. 5a)
void printStudent(Student arr[], int antallStudenter){    //Gir funksjonen tilgang til arrayet og antallet som ikke ligger globalt printStudent(studenter)
  for(int i = 0; i < antallStudenter; i++){
    Serial.print("Navn: ");
    Serial.println(arr[i].Navn);
    Serial.print("Tlf: ");
    Serial.println(arr[i].Tlf);
    Serial.print("Betalt avgift: ");
    if(arr[i].Betalt == 1){
      Serial.println("ja");
    }
    else{
      Serial.println("nei");
    }
  }

}




void loop(){
  //5. b)
}

void register_student(Student arr[], int& index){    //int& index må lage et alias for index slik at det ikke blir "en kopi"
  Serial.println("enter name");
  while(Serial.available() == 0){} //Venter til brukeren skriver og trykker enter
  
  Serial.println("Enter phone number");
  while(Serial.available() == 0){}
  Serial.parseInt();

  arr[index].tlf = Serial.parseInt();

  Serial.println("Has the student payed (y/n)");
  char ans = Serial.read();
while(!done){
  while(Serial.available() == 0){} //Venter til brukeren skriver og trykker enter
  if(ans == "y" || ans == "Y"){
    arr[index].betalt = true;
    done = true;
  }
  else if(ans == "n" || ans == "Y"){
    arr[index].betalt = false;
    done = true;
  }
  else{
    Serial.println("Try again");
  }
}
 index++;
 Serial.println("Succes");
}





