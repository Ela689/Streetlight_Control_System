# Define pin numbers
led = 13  # Pin for the LED
sensor_pir = 2  # Pin for the motion sensor (PIR)
sensor_light = 8  # Pin for the light sensor

# Initial states
value_pir = False  # Initial state of the motion sensor
state_pir = False  # Current state of the motion sensor
state_light = False  # Current state of the light sensor
next_value = None  # Value received from the Android app

# Setup function
def setup():
    global next_value
    pinMode(led, OUTPUT)  # Initialize LED pin as output
    pinMode(sensor_pir, INPUT)  # Initialize motion sensor pin as input
    pinMode(sensor_light, INPUT)  # Initialize light sensor pin as input
    Serial.begin(9600)  # Initialize serial communication
    next_value = None  # Reset next_value

# Main loop function
def loop():
    command()  # Call the command function

# Command function
def command():
    global next_value
    if Serial.available() > 0:  # Check if data is available
        next_value = Serial.read()  # Read the next value from serial
        Serial.print(next_value)  # Print the received value
        Serial.print("\n")  # Print newline character
        if next_value == '0':  # Turn off LED
            digitalWrite(led, LOW)
        elif next_value == '1':  # Turn on LED
            digitalWrite(led, HIGH)
        elif next_value == '2':  # Turn on/off based on motion sensor
            pir()
        elif next_value == '3':  # Turn on/off based on light sensor
            light()
        elif next_value == '4':  # Turn on/off based on both sensors
            smart()

# Function to handle light sensor
def light():
    global next_value
    while next_value == '3':  # Keep running until a new value is received
        state_light = digitalRead(sensor_light)  # Read the light sensor state
        Serial.print("Intensity: ")  # Print intensity
        Serial.println(state_light)  # Print light intensity
        delay(50)  # Delay for stability
        if state_light == HIGH:  # If it's bright
            digitalWrite(led, HIGH)  # Turn on LED
            Serial.println("LIGHT OFF & LED ON")  # Print status
            command()  # Call the command function
        else:  # If it's dark
            digitalWrite(led, LOW)  # Turn off LED
            Serial.println("LIGHT ON & LED OFF")  # Print status
            command()  # Call the command function

# Function to handle motion sensor
def pir():
    global next_value
    while next_value == '2':  # Keep running until a new value is received
        value_pir = digitalRead(sensor_pir)  # Read the motion sensor state
        if value_pir == HIGH:  # If motion is detected
            digitalWrite(led, HIGH)  # Turn on LED
            delay(100)  # Delay for stability
            if state_pir == LOW:  # If motion is detected for the first time
                Serial.println("Motion detected!")  # Print status
                state_pir = HIGH  # Update state
                command()  # Call the command function
        else:  # If no motion is detected
            digitalWrite(led, LOW)  # Turn off LED
            delay(100)  # Delay for stability
            if state_pir == HIGH:  # If motion stopped
                Serial.println("Motion stopped!")  # Print status
                state_pir = LOW  # Update state
                command()  # Call the command function

# Function to handle both sensors
def smart():
    global next_value
    while next_value == '4':  # Keep running until a new value is received
        state_light = digitalRead(sensor_light)  # Read the light sensor state
        value_pir = digitalRead(sensor_pir)  # Read the motion sensor state
        if state_light == HIGH and value_pir == HIGH:  # If it's bright and motion is detected
            digitalWrite(led, HIGH)  # Turn on LED
            command()  # Call the command function
        else:  # If it's dark or no motion is detected
            digitalWrite(led, LOW)  # Turn off LED
            command()  # Call the command function

# Run setup function once
setup()

# Run loop function repeatedly
while True:
    loop()
