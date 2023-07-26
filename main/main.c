#include "Buzzer.h"
#include "Temperature.h"
#include "ultrasonic.h"

Buzzer *buzzer;
TemperatureSensor *temperatureSensor;
ultrasonic_sensor_t *ultrasonicSensor;

static const char *TAG = "example";

void start()
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    buzzer = buzzerInit(11, OFF);
    temperatureSensor = temperatureSensorInit(4);
    ultrasonicSensor->echo_pin = 5;
    ultrasonicSensor->trigger_pin = 7;
}

void loop()
{
    buzzerTurnOn(buzzer);

    uint32_t distance;
    ultrasonic_measure_cm(ultrasonicSensor, 400, &distance);
    ESP_LOGI(TAG, "Distance: %f", (double) distance);
}

void app_main(void)
{
    start();
    while (1)
        loop();
}
