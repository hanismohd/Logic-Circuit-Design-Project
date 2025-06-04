#include <reg51.h>

// Stepper motor coil control pins
sbit IN1 = P2^0;
sbit IN2 = P2^1;
sbit IN3 = P2^2;
sbit IN4 = P2^3;

// Function to create a small delay
void delay() {
    int i;
    for(i = 0; i < 1000; i++);
}

// Full step sequence for clockwise
void step_CW() {
    IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0; delay();
    IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0; delay();
    IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0; delay();
    IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1; delay();
}

// Full step sequence for anticlockwise
void step_CCW() {
    IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1; delay();
    IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0; delay();
    IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0; delay();
    IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0; delay();
}

// Rotate 180° CW (100 steps)
void rotate_180_CW() {
    int i;
    for(i = 0; i < 25; i++) {
        step_CW();
    }
}

// Rotate 180° CCW
void rotate_180_CCW() {
    int i;
    for(i = 0; i < 25; i++) {
        step_CCW();
    }
}

void main() {
    while(1) {
        if(P1 == 0x01) {      // P1.0 pressed
            rotate_180_CW();
        }
        else if(P1 == 0x02) { // P1.1 pressed
            rotate_180_CCW();
        }
    }
}
