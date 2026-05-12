#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/uart.h"

#define UART_PORT UART_NUM_2
#define TX_PIN 17
#define RX_PIN 16

void app_main(void)
{
    uart_config_t uart_config = { // Configure UART parameters
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_driver_install(UART_PORT, 1024, 0, 0, NULL, 0); // Install UART driver
    uart_param_config(UART_PORT, &uart_config); // Configure UART parameters
    uart_set_pin(UART_PORT, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE); // Set UART pins

    const char* message = "Hello from Master Node!\n";
    uint8_t data[128];

    while(1) {
        printf("[MASTER] Sending message...\n");

        uart_write_bytes(UART_PORT, message, strlen(message)); // Send message over UART

        int len = uart_read_bytes(UART_PORT, data, sizeof(data)-1, pdMS_TO_TICKS(1000)); // Read response from slave

        if(len>0) {
            data[len] = 0;
            printf("[MASTER] Received: %s\n", data); // Print received message
        }

        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay before next transmission
    }
}
