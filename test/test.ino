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

if(tempC<0){
analogWrite(bluePin, 255);}
else if(tempC>0&&tempC<=45){
blueTemp= map(tempC, 0, 45, 255, 0);
analogWrite(bluePin, blueTemp);}
else if(tempC>37){
analogWrite(bluePin, 0);}

if(tempC<35){
analogWrite(greenPin, 0);}
else if(tempC>15&&tempC<=35){
greenTemp = map(tempC, 15, 35, 1, 254);
analogWrite(greenPin, greenTemp);}
else if(tempC>39&&tempC<=75){
greenTemp = map(tempC, 35, 75, 255, 0);
analogWrite(greenPin, greenTemp);}
else if(tempC>75){
analogWrite(greenPin, 0);}

if(tempC<45){
analogWrite(redPin, 0);}
else if(tempC>=75){
redTemp= map(tempC, 75, 90, 1, 255);
analogWrite(redPin, redTemp);}
else if(tempC>150){
analogWrite(redPin, 255);}

delay(1000);                           //wait 1000 ms before sending new data
}
