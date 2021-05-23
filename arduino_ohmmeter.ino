/**********************************************************************************************************
 * 
 * Author:    Aly Khan Nuruddin
 * Date:      May 11, 2021
 * Purpose:   This program permits the user to determine the resistance of a test resistor by setting up an 
 *            Arduino-configured voltage divider circuit with a reference resistor of known resistance.
 *            
 **********************************************************************************************************/

int sensorPin = A0;                                 // Define the Analog Input Pin that "senses" the output voltage.
int sensorValue = 0;                                // Initialize the value of the Analog Input Pin.

int maxAnalog = 1024;                               // Initialize the value of the maximum analog voltage reading.

float inputVoltage = 5.0;                           // Initialize the value of the input voltage in Volts (V).
float outputVoltage = 0.0;                          // Initialize the value of the output voltage in Volts (V).
float refResistance = 1000.0;                       // Initialize the value of the reference resistance in Ohms (Ω).
float testResistance = 0.0;                         // Initialize the value of the test resistance in Ohms (Ω).

float buffer = 0.0;                                 // Initialize the value of the placeholder for calculations.

void setup ()
{
  Serial.begin(9600);                               // Initialize communication with the Serial Monitor at 9600 baud.
}

void loop(){
  sensorValue = analogRead(analogPin);              // Read the output voltage from the Analog Input Pin.
  
  if(sensorValue){                                  // Define the condition where the output voltage is obtained.
    buffer = inputVoltage * sensorValue;            // Compute the value of the placeholder in Volts (V).
    outputVoltage = buffer / maxAnalog;             // Convert the output voltage from integer values to Volts (V). 
    buffer = (inputVoltage/outputVoltage) - 1;      // Compute the value of the placeholder in Volts (V).
    testResistance= refResistance * buffer;         // Compute the value of the test resistance in Ohms (Ω).
    Serial.print("outputVoltage: ");                // Define the character string for the output voltage.
    Serial.println(outputVoltage);                  // Print the value of the output voltage on the Serial Monitor.
    Serial.print("testResistance: ");               // Define the character string for the test resistance.
    Serial.println(testResistance);                 // Print the value of the test resistance on the Serial Monitor.
    delay(1000);                                    // Delay the display of successive data values by 1000 milliseconds.
  }
}
