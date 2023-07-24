#include "Temperature.h"

#define VOLT_TO_TEMP (73.0/3960.0)

static const char *TAG = "example";

TemperatureSensor* temperatureSensorInit(double pin)
{
    TemperatureSensor *temperatureSensor = (TemperatureSensor *) malloc(sizeof(TemperatureSensor));
    temperatureSensor->pin = pin;

    
    adc1_config_channel_atten(pin, ADC_ATTEN_DB_11);    

    return temperatureSensor;
}

double temperatureSensorRead(TemperatureSensor *temperatureSensor)
{

    temperatureSensor->prevTemperature = temperatureSensor->temperature;

    double reading = adc1_get_raw((adc1_channel_t) temperatureSensor->pin);

    // ESP_LOGI(TAG, "Reading: %f\n", reading);

    double voltage = reading;

    temperatureSensor->temperature = voltage * VOLT_TO_TEMP;

    // ESP_LOGI(TAG, "PrevTemp != Temp: %d\n", temperatureSensor->prevTemperature != temperatureSensor->temperature);

    // if(temperatureSensor->prevTemperature != temperatureSensor->temperature){
        // ESP_LOGI(TAG, "Voltage: %f\n", voltage);
        // ESP_LOGI(TAG, "Temperature: %f\n", temperatureSensor->temperature);
    // }

    return temperatureSensor->temperature;

}