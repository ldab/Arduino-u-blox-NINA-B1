/******************************************************************************
u-blox NINA-B1 Arduino example
Leonardo Bispo
March - 2019
https://github.com/ldab/Arduino-u-blox-NINA-B1

Distributed as-is; no warranty is given.
******************************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include "Ticker.h"
#include "Adafruit_SHT31.h"

// Since the u-blox NINA-B1 board uses the generic Arduino variant, we need to reasing the pins;
// the pins below are accordingly to the EVK-NINA-B1 board https://www.u-blox.com/en/product/evk-nina-b1

#define NINA_RX       5 // P0.05 - GPIO23
#define NINA_TX       6 // P0.06 - GPIO22
#define NINA_SDA      2 // P0.02 - GPIO24
#define NINA_SCL      3 // P0.05 - GPIO25
#define LED_DS1       7 // P0.07 - GPIO21
#define LED_DS2       31 // P0.07 - GPIO31

// Initialize the Temperature and Humidity Sensor SHT31
Adafruit_SHT31 sht31 = Adafruit_SHT31();

// Created functions prior to calling them as .cpp files are differnt from Arduino .ino
void blinky( void );
void readSensor( void );

// Create timers using Ticker library in oder to avoid delay()
Ticker blinkLED(blinky, 500);
Ticker readIT(readSensor, 800);

// Variables used on the code
float t = NAN;
float h = NAN;
bool  LED = false;

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_DS1, OUTPUT);
  pinMode(LED_DS2, OUTPUT);

  // Assign UART TX and RX pins accordingly
  Serial.setPins(NINA_RX, NINA_TX);
  Serial.begin(115200);

  // Assign I2C pins accordingly
  Wire.setPins(NINA_SDA, NINA_SCL);

  if (! sht31.begin(0x44))    // Set to 0x45 for alternate i2c addr
  {
    Serial.println("Couldn't find SHT31");
  }

  // Start the Timer function
  blinkLED.start();
  readIT.start();

}

void loop()
{
  blinkLED.update();
  readIT.update();
}

void readSensor( void )
{
  t = sht31.readTemperature();
  h = sht31.readHumidity();

  if (! isnan(t)) {  // check if 'is not a number'
    Serial.print("Temp ºC = "); Serial.println(t);
  } else { 
    Serial.println("Failed to read temperature");
  }
  
  if (! isnan(h)) {  // check if 'is not a number'
    Serial.print("Hum. % = "); Serial.println(h);
  } else { 
    Serial.println("Failed to read humidity");
  }
  Serial.println();
  
}

void blinky( void )
{
  // Toggle LED_DS1
  digitalWrite(LED_DS1, LED);

  // Toggle LED_DS2
  digitalWrite(LED_DS2, !LED);

  LED = !LED;
}
