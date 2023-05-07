#include <Arduino.h>

int currentNum = 0;
int pin1 =  5;
int pin2 = 4;
int pin3 = 3;
int pin4 = 2;
int pinsArray[4] = {pin1, pin2, pin3, pin4 };


void setup() {
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}


void wait() {
    delay(1000);
}

int toPinValue(char ch) {
    if (ch == '1') {
        return HIGH;
    } else {
        return LOW;
    }
}

void displayBinaryNum(char bin[4]) {
    int originalLength = 0;

    //
    for (int i = 0; i < 4; i++) {
        if (bin[i] == '\000') {
            break;
        }
        originalLength++;
    }

    int prependLength = 4 - originalLength;
    for (int i = 0; i < 4; i++) {
        if (i < prependLength) {
            digitalWrite(pinsArray[i], toPinValue('0'));
        } else {
            digitalWrite(pinsArray[i], toPinValue(bin[i - prependLength]));
        }
    }
}

void reset() {
    for (int i : pinsArray) {
        digitalWrite(i, toPinValue('0'));
    }
}

void loop() {
    char *binary = new char[4];

    itoa(currentNum, binary, 2);
    displayBinaryNum(binary);

    currentNum++;
    if (currentNum > 15) {
        currentNum = 0;
    }

    wait();
}
