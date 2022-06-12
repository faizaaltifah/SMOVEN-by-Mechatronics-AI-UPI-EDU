int data = 0;


#include <Servo.h>

#include <Wire.h>

#include <SparkFun_APDS9960.h>


// Pins

#define APDS9960_INT    2  // Needs to be an interrupt pin

#define LED_PIN1         3 // LED for showing interrupt

#define LED_PIN2         4 // LED for showing interrupt


// Constants

#define LIGHT_INT_HIGH  1000 // High light level for interrupt

#define LIGHT_INT_LOW   10   // Low light level for interrupt


// Global variables

SparkFun_APDS9960 apds = SparkFun_APDS9960();

uint16_t ambient_light = 0;

uint16_t red_light = 0;

uint16_t green_light = 0;

uint16_t blue_light = 0;

int isr_flag = 0;

uint16_t threshold = 0;



Servo myservo;  // create servo object to control a servo


int potpin = 0;  // analog pin used to connect the potentiometer

int val;    // variable to read the value from the analog pin


void setup() {

  // put your setup code here, to run once:

  // Set LED as output

  pinMode(LED_PIN1, OUTPUT);

  pinMode(LED_PIN2, OUTPUT);

  pinMode(APDS9960_INT, INPUT);

 

   myservo.attach(9);

  Serial.begin(9600);

   Serial.println();

  Serial.println(F("-------------------------------------"));

  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));

  Serial.println(F("-------------------------------------"));

 

  // Initialize interrupt service routine

  attachInterrupt(0, interruptRoutine, FALLING);

   if ( apds.init() ) {

    Serial.println(F("APDS-9960 initialization complete"));

  } else {

    Serial.println(F("Something went wrong during APDS-9960 init!"));

  }

 

  // Set high and low interrupt thresholds

  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {

    Serial.println(F("Error writing low threshold"));

  }

  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {

    Serial.println(F("Error writing high threshold"));

  }

 

  // Start running the APDS-9960 light sensor (no interrupts)

  if ( apds.enableLightSensor(false) ) {

    Serial.println(F("Light sensor is now running"));

  } else {

    Serial.println(F("Something went wrong during light sensor init!"));

  }

 

  // Read high and low interrupt thresholds

  if ( !apds.getLightIntLowThreshold(threshold) ) {

    Serial.println(F("Error reading low threshold"));

  } else {

    Serial.print(F("Low Threshold: "));

    Serial.println(threshold);

  }

  if ( !apds.getLightIntHighThreshold(threshold) ) {

    Serial.println(F("Error reading high threshold"));

  } else {

    Serial.print(F("High Threshold: "));

    Serial.println(threshold);

  }

 

  // Enable interrupts

  if ( !apds.setAmbientLightIntEnable(1) ) {

    Serial.println(F("Error enabling interrupts"));

  }

 

  // Wait for initialization and calibration to finish

  delay(500);

}


void loop() {

  // put your main code here, to run repeatedly:

  if (Serial.available()) {

    data = Serial.read();

    Serial.println(data);

  }

  if (data == 49 )

  {

   myservo.write(0);

  }

  else if (data == 50)

  {

       myservo.write(90);

    }

// If interrupt occurs, print out the light levels

  if ( isr_flag == 1 ) {

   

    // Read the light levels (ambient, red, green, blue) and print

    if (  !apds.readAmbientLight(ambient_light) ||

          !apds.readRedLight(red_light) ||

          !apds.readGreenLight(green_light) ||

          !apds.readBlueLight(blue_light) ) {

      Serial.println("Error reading light values");

    } else {

      Serial.print("Interrupt! Ambient: ");

      Serial.print(ambient_light);

      Serial.print(" R: ");

      Serial.print(red_light);

      Serial.print(" G: ");

      Serial.print(green_light);

      Serial.print(" B: ");

      Serial.println(blue_light);

    }

    if(ambient_light <= 4500){

    digitalWrite(LED_PIN1, HIGH);

    digitalWrite(LED_PIN2, HIGH);

    }else{

    digitalWrite(LED_PIN1, LOW);

    digitalWrite(LED_PIN2, LOW);

    }

   

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)

    isr_flag = 0;

    if ( !apds.clearAmbientLightInt() ) {

      Serial.println("Error clearing interrupt");

    }

   

  }

}

void interruptRoutine() {

  isr_flag = 1;

}
