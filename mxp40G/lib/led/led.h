/**
 * \file
 * \brief LED API header.
 */
#ifndef _LED_H
#define _LED_H

/**
 * LED Base Address Value.
 */
#define LED_BASE_ADDRESS 0xabab /* not defined */
/**
 * LED Bus Width.
 */
#define LED_BUS_WIDTH 0xffff
/**
 * LED ON value. 
 */
#define LED_ON 1
/**
 * LED OFF value.
 */
#define LED_OFF 0

/**
 * \brief This function turns on a led.
 *
 * \param[in] led_id  A number that represents the led to turn on.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0.
 */
int led_turn_on(unsigned int led_id);

/**
 * \brief This function turns off a led.
 *
 * \param[in] led_id  A number that represents the led to turn off. 
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0. 
 */
int led_turn_off(unsigned int led_id);

/**
 * \brief This function turns on all the leds.
 *
 * \return This function returns -1 if an error occurs otherwise, it returns 0. 
 */
int led_turn_on_all(void);

/**
 * \brief This function turns off all the leds.
 * 
 * \return This function returns -1 if an error occurs otherwise, it returns 0. 
 */
int led_turn_off_all(void);

int set_led_status(unsigned int led_id, unsigned int value);

#endif /* _LED_H */
