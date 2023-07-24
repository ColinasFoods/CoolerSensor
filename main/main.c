#include "Buzzer.h"
#include "Temperature.h"
#include "Ultrasonic.h"

Buzzer *buzzer;
TemperatureSensor *temperatureSensor;
Ultrasonic *ultrasonic;

void start()
{
    adc1_config_width(ADC_WIDTH_BIT_12);
    buzzer = buzzerInit(11, OFF);
    temperatureSensor = temperatureSensorInit(4);
    ultrasonic = ultrasonicInit(13, 12);
}

void loop()
{
    buzzerTurnOn(buzzer);
    temperatureSensorRead(temperatureSensor);

}

void app_main(void)
{
    start();
    while (1)
        loop();
}
