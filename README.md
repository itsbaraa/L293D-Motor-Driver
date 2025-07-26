# L293D Motor Driver

This Arduino project controls a 4 dc motors using a single L293D motor driver chip. The motors perform a sequence on startup and then switches to an autonomous obstacle avoidance mode using an ultrasonic sensor and a servo motor.

- **4 DC Motors** driven in parallel pairs (left side, right side).
- A **L293D Motor Driver** to control the motors.
- An **HC-SR04 Ultrasonic Sensor** to detect obstacles.

# How It Works

1.  **Startup Sequence**: The dc motors will start doing these tasks:
    -   Moves **forward** for 30 seconds.
    -   Moves **backward** for 30 seconds.
    -   Alternates **turning left and right** every second for a total of one minute.

2.  **Obstacle Detection**: The dc motors will keep moving forward until the ultrasonic sensor detects an object at **10cm or closer** then the dc motors will stop and switch to moving backwards and turning right to avoid the detected object.

# Circuit Diagram
  
<img width="1686" height="1025" alt="image" src="https://github.com/user-attachments/assets/d8fc2b60-1742-46d5-be20-91002a329942" />


# Showcase
  
https://github.com/user-attachments/assets/bf95b519-06f4-41c7-866a-16fc81980e5f
