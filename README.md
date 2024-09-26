# Two Semaphores

The provided code appears to be designed to control a pedestrian traffic light system, including a buzzer and ultrasonic sensor. It incorporates several functions and variables to manage the traffic flow and pedestrian crossings.

# Initialization:

Defines constants for LED pins, non-LED pins, ultrasonic sensor constants, and button states.
    
Initializes the LED pins, buzzer pin, and serial communication.

# Ultrasonic Distance Measurement:

The readUltrasonicDistance function measures the distance to an object using the ultrasonic sensor.

It sends a trigger pulse and measures the time it takes for the echo to return.

The distance is calculated based on the speed of sound and the measured time.

# Pedestrian Red Blink:

The blinkPedestrianRed function blinks the pedestrian red LED and sounds the buzzer.

It takes onDuration and offDuration as parameters to control the blinking pattern.

# Semaphore Cycle:

The startSemaphore function initiates the traffic light cycle.

It lights up the vehicle green, then yellow, and finally red.

After a delay, it lights up the pedestrian red and sounds the buzzer.

It then lights up the pedestrian green and sounds the buzzer for a longer duration.

Finally, it blinks the pedestrian red and delays before starting the cycle again.

# Pedestrian Crossing:

The letPedestrianCross function allows pedestrians to cross.

It sounds the buzzer, lights up the vehicle red, and lights up the pedestrian green.

After a delay, it turns off the pedestrian green and vehicle red.

# Main Loop:

The loop function continuously checks the semaphore button and pedestrian button states.

If the semaphore button is pressed, it reads the ultrasonic distance and pedestrian button state.

If the distance is within the specified range or the pedestrian button is pressed, it calls letPedestrianCross. Otherwise, it calls startSemaphore.

Overall Functionality:

The code controls the traffic lights and pedestrian crossing based on the ultrasonic sensor readings and button presses.

It ensures that pedestrians can cross safely while maintaining traffic flow.

The buzzer provides auditory feedback to pedestrians.
