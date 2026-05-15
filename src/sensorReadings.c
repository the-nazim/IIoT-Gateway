#include "main.h"

int read_ldr(void) {
    int adc_value = adc1_get_raw(LDR_ADC_CHANNEL);
    return adc_value;
}

int read_pot(void) {
    int adc_value = adc1_get_raw(POT_ADC_CHANNEL);
    return adc_value;
}

void read_dht(dht_data *sensorData) {
    float humidity, temperature;
    esp_err_t res = dht_read_float_data(DHT_TYPE_AM2301, DHT22_PIN, &humidity, &temperature);
    if (res == ESP_OK) {
        sensorData->humidity = humidity;
        sensorData->temperature = temperature;
        // return sensorData; // Return humidity as an example
    } 
    else {
        // ESP_LOGE(TAG, "Failed to read from DHT22 sensor");
        // return -1.0; // Indicate error
        sensorData->humidity = -1.0;
        sensorData->temperature = -1.0;
    }
}

int read_gas_sensor(void) {
    int adc_value = adc1_get_raw(GAS_SENSOR_ADC_CHANNEL);
    return adc_value;
}

float read_ultrasonic(void) {
    gpio_set_level(ULTRASONIC_TRIG, 1);
    esp_rom_delay_us(10);
    gpio_set_level(ULTRASONIC_TRIG, 0);

    int64_t timeout = esp_timer_get_time();
    while(gpio_get_level(ULTRASONIC_ECHO) == 0) {
        if (esp_timer_get_time() - timeout > 30000) {
            return -1;
        }
    }

    int64_t start_time = esp_timer_get_time();
    while(gpio_get_level(ULTRASONIC_ECHO) == 1) {
        if (esp_timer_get_time() - start_time > 30000) {
            return -1;
        }
    }

    int64_t end_time = esp_timer_get_time();
    
    float duration = end_time - start_time;
    float distance = duration * 0.0343 / 2; // Speed of sound is 343 m/s or 0.0343 cm/us
    return distance;
}