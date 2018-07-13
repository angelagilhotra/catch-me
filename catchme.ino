
const int motorPin11=3;
const int motorPin12=4;
const int motorPin21=5;
const int motorPin22=6;

const int trigPinTail = 9;
const int echoPinTail =10;

const int trigPinHead = 11;
const int echoPinHead = 12;

long durationTail;
long distanceTail;
long durationHead;
long distanceHead;

void setup() {
  
pinMode(trigPinTail, OUTPUT);
pinMode(echoPinTail, INPUT);
pinMode(trigPinHead, OUTPUT);
pinMode(echoPinHead, INPUT);

pinMode(motorPin11, OUTPUT);
pinMode(motorPin12, OUTPUT);
pinMode(motorPin21, OUTPUT);
pinMode(motorPin22, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPinTail,LOW);
delayMicroseconds(2);
digitalWrite(trigPinTail,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinTail, LOW);
durationTail = pulseIn(echoPinTail, HIGH);
distanceTail = durationTail*(0.034/2);

digitalWrite(trigPinHead,LOW);
delayMicroseconds(2);
digitalWrite(trigPinHead,HIGH);
delayMicroseconds(10);
digitalWrite(trigPinHead, LOW);
durationHead = pulseIn(echoPinHead, HIGH);
distanceHead = durationHead*(0.034/2);

Serial.print("Tail Distance: ");
Serial.println(distanceTail);

Serial.print("Head Distance: ");
Serial.println(distanceHead);

if(distanceTail<10 || distanceHead<20)
{
  /*for(int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }*/
  
  digitalWrite(motorPin11, LOW);
  digitalWrite(motorPin12, HIGH);

  digitalWrite(motorPin21, HIGH);
  digitalWrite(motorPin22, LOW);   
               
}
else 
{
  digitalWrite(motorPin11, LOW);
  digitalWrite(motorPin12, LOW);
  digitalWrite(motorPin21, LOW);
  digitalWrite(motorPin22, LOW);
}

}
