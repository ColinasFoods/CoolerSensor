#include "Ultrasonic.h"

#define DOOR_DISTANCE 10

Ultrasonic* ultrasonicInit(double triggerPin, double echoPin)
{
    Ultrasonic *ultrasonic = (Ultrasonic *) malloc(sizeof(Ultrasonic));
    ultrasonic->triggerPin = triggerPin;
    ultrasonic->echoPin = echoPin;

    adc1_config_channel_atten(echoPin, ADC_ATTEN_DB_11);
    gpio_set_direction(triggerPin, GPIO_MODE_OUTPUT);

    return ultrasonic;
}

enum DoorState ultrasonicIsDoorOpen(Ultrasonic *ultrasonic)
{
    double distance = ultrasonicGetDistance(ultrasonic);

    if (distance < DOOR_DISTANCE)
        ultrasonic->currDoorState = OPEN;
    else
        ultrasonic->currDoorState = CLOSED;

    return ultrasonic->currDoorState;
}

double ultrasonicGetDistance(Ultrasonic *ultrasonic)
{
    gpio_set_level((gpio_num_t) ultrasonic->triggerPin, 1);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    gpio_set_level((gpio_num_t) ultrasonic->triggerPin, 0);

    double reading = adc1_get_raw((adc1_channel_t) ultrasonic->echoPin);

    double voltage = reading;

    ultrasonic->distance = voltage * SOUND_SPEED / 2;

    return ultrasonic->distance;
}