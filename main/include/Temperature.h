#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_log.h"
#include "esp_adc_cal.h"

struct TemperatureSensor
{
    double pin;
    double temperature;
    double prevTemperature;
};

typedef struct TemperatureSensor TemperatureSensor;

/**
 * @brief Initialize the temperature sensor
 * @attention Pin must be 3, 2, 1, 0, 6, 5, or 4
*/
TemperatureSensor* temperatureSensorInit(double pin);

/**
 * @brief Read the temperature from the sensor in Celsius
*/
double temperatureSensorRead(TemperatureSensor *temperatureSensor);

