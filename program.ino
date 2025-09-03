// Define pin numbers
int led = 13;            // Pin for the LED
int sensor_pir = 2;      // Pin for the motion sensor (PIR)
int sensor_light = 8;    // Pin for the light sensor

// Initial states
bool value_pir = LOW;    // Initial state of the motion sensor
bool state_pir = LOW;    // Current state of the motion sensor
bool state_light = LOW;  // Current state of the light sensor
char next_value = 0;     // Value received from the Android app

// Setup function
void setup() {
    pinMode(led, OUTPUT);           // Initialize LED pin as output
    pinMode(sensor_pir, INPUT);    // Initialize motion sensor pin as input
    pinMode(sensor_light, INPUT);  // Initialize light sensor pin as input
    Serial.begin(9600);            // Initialize serial communication
}

// Main loop function
void loop() {
    command();  // Call the command function
}

// Command function
void command() {
    if (Serial.available() > 0) {  // Check if data is available
        next_value = Serial.read(); // Read the next value from serial
        Serial.print(next_value);   // Print the received value
        Serial.print("\n");         // Print newline character
        if (next_value == '0') {    // Turn off LED
            digitalWrite(led, LOW);
        } else if (next_value == '1') { // Turn on LED
            digitalWrite(led, HIGH);
        } else if (next_value == '2') { // Turn on/off based on motion sensor
            pir();
        } else if (next_value == '3') { // Turn on/off based on light sensor
            light();
        } else if (next_value == '4') { // Turn on/off based on both sensors
            smart();
        }
    }
}

// Function to handle light sensor
void light() {
    while (next_value == '3') {  // Keep running until a new value is received
        state_light = digitalRead(sensor_light);  // Read the light sensor state
        Serial.print("Intensity: ");              // Print intensity
        Serial.println(state_light);               // Print light intensity
        delay(50);  // Delay for stability
        if (state_light == HIGH) {  // If it's bright
            digitalWrite(led, HIGH);  // Turn on LED
            Serial.println("LIGHT OFF & LED ON");  // Print status
            command();  // Call the command function
        } else {  // If it's dark
            digitalWrite(led, LOW);  // Turn off LED
            Serial.println("LIGHT ON & LED OFF");  // Print status
            command();  // Call the command function
        }
    }
}

// Function to handle motion sensor
void pir() {
    while (next_value == '2') {  // Keep running until a new value is received
        value_pir = digitalRead(sensor_pir);  // Read the motion sensor state
        if (value_pir == HIGH) {  // If motion is detected
            digitalWrite(led, HIGH);  // Turn on LED
            delay(100);  // Delay for stability
            if (state_pir == LOW) {  // If motion is detected for the first time
                Serial.println("Motion detected!");  // Print status
                state_pir = HIGH;  // Update state
                command();  // Call the command function
            }
        } else {  // If no motion is detected
            digitalWrite(led, LOW);  // Turn off LED
            delay(100);  // Delay for stability
            if (state_pir == HIGH) {
                Serial.println("Motion stopped!");  // Print status
                state_pir = LOW;  // Update state
                command();  // Call the command function
            }
        }
    }
}

// Function to handle both sensors
void smart() {
    while (next_value == '4') {  // Keep running until a new value is received
        state_light = digitalRead(sensor_light);  // Read the light sensor state
        value_pir = digitalRead(sensor_pir);      // Read the motion sensor state
        if (state_light == HIGH && value_pir == HIGH) {  // If it's bright and motion is detected
            digitalWrite(led, HIGH);  // Turn on LED
            command();  // Call the command function
        } else {  // If it's dark or no motion is detected
            digitalWrite(led, LOW);  // Turn off LED
            command();  // Call the command function
        }
    }
}
