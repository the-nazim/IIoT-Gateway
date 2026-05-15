#include "main.h"


void adc_init_custom(void) {
    adc1_config_width(ADC_WIDTH_BIT_12);

    adc1_config_channel_atten(LDR_ADC_CHANNEL, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(POT_ADC_CHANNEL, ADC_ATTEN_DB_11);
}

void ultrasonic_init(void) {
    
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << ULTRASONIC_TRIG),
        .mode = GPIO_MODE_OUTPUT,
    };
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = (1ULL << ULTRASONIC_ECHO);
    io_conf.mode = GPIO_MODE_INPUT;
    gpio_config(&io_conf);

    gpio_set_level(ULTRASONIC_TRIG, 0);
}

void gas_sensor_init(void) {
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(GAS_SENSOR_ADC_CHANNEL, ADC_ATTEN_DB_11);
}