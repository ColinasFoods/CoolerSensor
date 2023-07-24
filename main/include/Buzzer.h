#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief States of the buzzer
*/
enum BuzzerState
{
    ON,
    OFF
};

struct Buzzer
{
    double pin;
    double timeSinceUpdate;
    enum BuzzerState currState;
};

typedef struct Buzzer Buzzer;

/**
 * @brief Initialize the buzzer
 * @param pin The pin the buzzer is connected to
 * @param currstate The current state of the buzzer
*/
Buzzer* buzzerInit(double pin, enum BuzzerState currstate);

/**
 * @brief Turn on the buzzer
 * @param buzzer The buzzer to turn on
*/
void buzzerTurnOn(Buzzer *buzzer);

/**
 * @brief Turn off the buzzer
 * @param buzzer The buzzer to turn off
*/
void buzzerTurnOff(Buzzer *buzzer);

/**
 * @brief Toggle the buzzer
 * @param buzzer The buzzer to toggle
*/
void buzzerToggle(Buzzer *buzzer);

/**
 * @brief Turn on the buzzer for a certain amount of time
 * @param buzzer The buzzer to turn on
 * @param time The amount of time to turn on the buzzer
*/
void buzzerTimeOn(Buzzer *buzzer, double time);

/**
 * @brief Get the time since the last update
 * @param buzzer The buzzer to get the time since the last update
*/
double buzzerGetTimeSinceUpdate(Buzzer *buzzer);

/**
 * @brief Set the time since the last update
 * @param buzzer The buzzer to set the time since the last update
*/
void buzzerSetTimeSinceUpdate(Buzzer *buzzer);