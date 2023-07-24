#include "Buzzer.h"

Buzzer* buzzerInit(double pin, enum BuzzerState currstate)
{
    Buzzer *buzzer = (Buzzer *) malloc(sizeof(Buzzer));
    buzzer->pin = pin;
    buzzer->currState = currstate;
    gpio_set_direction((gpio_num_t) buzzer->pin, GPIO_MODE_OUTPUT);
    return buzzer;
}

void buzzerTurnOn(Buzzer *buzzer)
{
    buzzer->currState = ON;
    gpio_set_level((gpio_num_t) buzzer->pin, 1);
}

void buzzerTurnOff(Buzzer *buzzer)
{
    buzzer->currState = OFF;
    gpio_set_level((gpio_num_t) buzzer->pin, 0);
}

void buzzerToggle(Buzzer *buzzer)
{
    if (buzzer->currState == ON)
        buzzerTurnOff(buzzer);
    else
        buzzerTurnOn(buzzer);
}

void buzzerTimeOn(Buzzer *buzzer, double time)
{
    buzzerTurnOn(buzzer);
    vTaskDelay(time / portTICK_PERIOD_MS);
    buzzerTurnOff(buzzer);
}

double buzzerGetTimeSinceUpdate(Buzzer *buzzer)
{
    return buzzer->timeSinceUpdate;
}

