#include "driver/adc.h"
#include "driver/gpio.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

//@brief Speed of sound in cm/uS
#define SOUND_SPEED 0.034

enum DoorState
{
    OPEN,
    CLOSED
};

/**
 * @brief States of the ultrasonic sensor
 * @param triggerPin The pin the trigger is connected to
 * @param echoPin The pin the echo is connected to
 * @param doorOpen Whether the door is open or closed
 * @param timeDoorStateChanged The time the door state changed
 * @param currDoorState The current state of the door
 * @param distance The distance the ultrasonic sensor is from the door
*/
struct Ultrasonic
{
    double triggerPin;
    double echoPin;
    double timeDoorStateChanged;
    enum DoorState currDoorState;
    double distance;
};

typedef struct Ultrasonic Ultrasonic;

/**
 * @brief Initialize the ultrasonic sensor
 * @param triggerPin The pin the trigger is connected to
 * @param echoPin The pin the echo is connected to
*/
Ultrasonic* ultrasonicInit(double triggerPin, double echoPin);

/**
 * @brief Get the distance from the ultrasonic sensor
 * @param ultrasonic The ultrasonic sensor to get the distance from
*/
enum DoorState ultrasonicIsDoorOpen(Ultrasonic *ultrasonic);

/**
 * @brief Get the distance from the ultrasonic sensor
 * @param ultrasonic The ultrasonic sensor to get the distance from
*/
double ultrasonicGetDistance(Ultrasonic *ultrasonic);


