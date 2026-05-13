#include "main.h"


void adc_init_custom(void) {
    adc1_config_width(ADC_WIDTH_BIT_12);

    adc1_config_channel_atten(LDR_ADC_CHANNEL, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(POT_ADC_CHANNEL, ADC_ATTEN_DB_11);
}