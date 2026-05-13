#include "main.h"

void simulated_mqtt_publish(void) {
    printf("\n========== MQTT SIMULATION ==========\n");

    printf("Topic: factory/temperature\n");
    printf("Payload: %d\n\n", holdingRegisters[0]);

    printf("Topic: factory/humidity\n");
    printf("Payload: %d\n\n", holdingRegisters[1]);

    printf("Topic: factory/light\n");
    printf("Payload: %d\n\n", holdingRegisters[2]);

    printf("Topic: factory/potentiometer\n");
    printf("Payload: %d\n\n", holdingRegisters[3]);

    printf("=====================================\n");
}