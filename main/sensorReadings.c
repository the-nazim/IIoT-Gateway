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
    esp_err_t res = dht_read_float_data(DHT_TYPE_DHT11, DHT22_PIN, &humidity, &temperature);
    if (res == ESP_OK) {
        sensorData->humidity = humidity;
        sensorData->temperature = temperature;
        // return sensorData; // Return humidity as an example
    } 
    else {
        ESP_LOGE(TAG, "Failed to read from DHT22 sensor");
        // return -1.0; // Indicate error
    }
}