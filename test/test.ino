float tempC;
int tempPin = A0;
int redPin= 4;
int greenPin= 13;
int bluePin= 5;

int blueTemp= 0; int greenTemp= 0; int redTemp= 0;

void setup()
{
Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}

void loop()
{
tempC = analogRead(tempPin);           //read the value from the sensor
tempC = (5.0 * tempC * 100.0)/1024.0;  //convert the analog data to temperature
Serial.println((byte)tempC);             //send the data to the computer

if(tempC<0){ // stays on blue
analogWrite(bluePin, 255);}
else if(tempC>0&&tempC<=45){
blueTemp= map(tempC, 0, 45, 255, 0);
analogWrite(bluePin, blueTemp);}
else if(tempC>37){
analogWrite(bluePin, 0);}

if(tempC<75){ // changes to green
analogWrite(greenPin, 0);}
else if(tempC>75&&tempC<=75){
greenTemp = map(tempC, 75, 80, 1, 254);
analogWrite(greenPin, greenTemp);}
else if(tempC>76&&tempC<=80){
greenTemp = map(tempC, 80, 86, 255, 0);
analogWrite(greenPin, greenTemp);}
else if(tempC>80){
analogWrite(greenPin, 0);}

if(tempC<140){  // Changes to red
analogWrite(redPin, 0);}
else if(tempC>=150){
redTemp= map(tempC, 150, 149, 1, 255);
analogWrite(redPin, redTemp);}
else if(tempC>150){
analogWrite(redPin, 255);}

delay(1000);                           //wait 1000 ms before sending new data
}
