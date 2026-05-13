#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "mqtt_client.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "esp_timer.h"
#include "dht.h" // Include the DHT22 sensor library header

// MQTT broker URI
#define MQTT_BROKER_URI "mqtt://broker.hivemq.com:1883"

extern const char *TAG;
extern esp_mqtt_client_handle_t mqtt_client;
extern uint16_t holdingRegisters[10]; // Modbus holding registers

#define LDR_ADC_CHANNEL ADC1_CHANNEL_6 // GPIO34
#define POT_ADC_CHANNEL ADC1_CHANNEL_4 // GPIO32
#define ULTRASONIC_TRIG GPIO_NUM_5
#define ULTRASONIC_ECHO GPIO_NUM_18
#define DHT22_PIN GPIO_NUM_4

extern const char *TAG = "IIOT_GATEWAY";
extern esp_mqtt_client_handle_t mqtt_client;
extern uint16_t holdingRegisters[10]; // Modbus holding registers

typedef struct {
    float temperature;
    float humidity;
} dht_data;

// Function prototypes
void adc_init_custom(void);
int read_ldr(void);
int read_pot(void);
void read_dht(dht_data *sensorData);
void simulated_mqtt_publish(void);
void sensorTask(void *pvParameters);

#endif // MAIN_H