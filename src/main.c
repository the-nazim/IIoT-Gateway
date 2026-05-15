#include "main.h"

const char *TAG = "IIOT_GATEWAY";
uint16_t holdingRegisters[10] = {0};

void app_main(void)
{
    ESP_LOGI(TAG, "Starting IIoT Gateway...");
    adc_init_custom(); // Initialize ADC for LDR and potentiometer
    xTaskCreate(sensorTask, "Sensor Task", 4096, NULL, 5, NULL); // Create sensor reading task
}
