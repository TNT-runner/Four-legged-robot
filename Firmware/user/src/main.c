#include "main.h"

#define LED_RCU         RCU_GPIOA
#define LED_PORT        GPIOA
#define LED_PIN         GPIO_PIN_6

void led_init(void)
{
    rcu_periph_clock_enable(LED_RCU);
	/*LED*/
	gpio_mode_set(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
    gpio_output_options_set(LED_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, LED_PIN);
}

int main(void)
{
    systick_config();
    led_init();
    while(1) {
        gpio_bit_toggle(LED_PORT,LED_PIN);
        delay_1ms(250);
    }
}
