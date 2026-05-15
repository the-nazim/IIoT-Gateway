#include "main.h"

void sensorTask(void *pvParameters) {

    dht_data sensorData;
    while(1)
    {
        // Read sensors
        int ldrValue = read_ldr();
        int potValue = read_pot();
        read_dht(&sensorData); // Pass pointer to sensorData
        float dhtHumidity = sensorData.humidity; // Assuming sensorData is updated in read_dht()
        float dhtTemperature = sensorData.temperature; // Assuming sensorData is updated in read_dht()

        // Update Modbus holding registers
        holdingRegisters[0] = (uint16_t)(dhtTemperature * 10); // Store temperature as integer (e.g., 25.3 -> 253)
        holdingRegisters[1] = (uint16_t)(dhtHumidity * 10);    // Store humidity as integer (e.g., 60.5 -> 605)
        holdingRegisters[2] = (uint16_t)ldrValue;             // Store LDR value
        holdingRegisters[3] = (uint16_t)potValue;             // Store potentiometer value

        // Simulate MQTT publish
        simulated_mqtt_publish();

        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay for 5 seconds before next reading
    }
}