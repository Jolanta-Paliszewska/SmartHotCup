/**
 * based on this:
 * http://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
 * Sensor test sketch
 * for more information see
 * http://www.ladyada.net/make/logshield/lighttemp.html
 */

// we tie 3.3V to ARef and measure it with a multimeter!
#define aref_voltage 3.3


//TMP36 Pin Variables
int tempPin = A0;
//the analog pin the TMP36's Vout (sense) pin is connected to
//the resolution is 10 mV / degree centigrade with a
//500 mV offset to allow for negative temperatures 
int tempReading; // the analog reading from the sensor
//int ledPin = 13;

/*
flip a flipdot
 author: fabianmoronzirfas
 Based on  an example from the Fritzing Creator Kit: www.fritzing.org/creatorkit.
 */
 
int flip=11;                    // dot direction one Pin
int flop=10;                    // dot direction two Pin


void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  // If you want to set the aref to something other than 5v
  analogReference(EXTERNAL);
  pinMode(flip,OUTPUT);        // pin A declared as OUTPUT
  pinMode(flop,OUTPUT);        // pin B declared as OUTPUT
}

void loop() {
  
  tempReading = analogRead(tempPin);
  
  //Serial.print("Temp reading = ");
  //Serial.print(tempReading);     // the raw analog reading

  // converting that reading to voltage,
  // which is based off the reference voltage
  float voltage = tempReading * aref_voltage;
  voltage /= 1024.0;

  // print out the voltage
  Serial.print(" - ");
  Serial.print(voltage); Serial.println(" volts");

  // now print out the temperature
  //converting from 10 mv per degree wit 500 mV offset
  float temperatureC = (voltage - 0.5) * 100 ;
  // to degrees ((volatge - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");

  // now convert to Fahrenheight
  //float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  //Serial.print(temperatureF); Serial.println(" degrees F");

 // delay(1000);
  
  if(temperatureC > 39) { // Don´t drink now! (red) 
    
  digitalWrite(flip,HIGH);     // dot direction one pin switched to HIGH (+5V)
  digitalWrite(flop,LOW);      // dot direction two pin switched to LOW  (GND)
  delay(10);
  digitalWrite(flip,LOW);    // dot direction one pin switched to LOW (GND)  
  delay(1000);
  
  } 

  else { //yellow //you can drink (yellow)
  digitalWrite(flip,LOW);     // dot direction one pin switched to HIGH (GND)
  digitalWrite(flop,HIGH);  // dot direction two pin switched to LOW  (+5V)
  delay(10);
  digitalWrite(flop,LOW);  // dot direction two pin switched to LOW  (GND)
  delay(1000);  
  }
    
}
