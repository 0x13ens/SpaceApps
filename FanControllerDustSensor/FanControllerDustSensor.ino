int dustPin=0;
float dustVal=0; 
int ledPower=2;
int delayTime=280;
int delayTime2=40;
float offTime=9680;
#define control 3 // pin that controls the Fan

void setup(){
Serial.begin(9600);
pinMode(ledPower,OUTPUT);
pinMode(dustPin, INPUT);
pinMode(control,OUTPUT);// define control pin as output
}
 
void loop(){
// ledPower is any digital pin on the arduino connected to Pin 2 on the sensor
digitalWrite(ledPower,LOW); 
delayMicroseconds(delayTime);
dustVal=analogRead(dustPin); 
delayMicroseconds(delayTime2);
digitalWrite(ledPower,HIGH); 
delayMicroseconds(offTime);
 
delay(1000);
if (dustVal>36.455)
Serial.println((float(dustVal/1024)-0.0356)*120000*0.035);
// get our dust density as a real sum and set as variable 

float dustval = ((float(dustVal/1024)-0.0356)*120000*0.035);
if(dustVal>300) // Air quality okay
digitalWrite(control,LOW); // turn the MOSFET Switch ON
delay(2000);// Wait for 2000 ms or 2 second

if(dustVal>500) // Air quality Crap 
digitalWrite(control,HIGH); // turn the MOSFET Switch ON
delay(2000);// Wait for 2000 ms or 2 second


Serial.println(dustVal);


}
