/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*! @name PORTB0 (number 35), J4[12]/A5-I2C0_SCL/ADC0_SE8
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_I2C0_SCL_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_I2C0_SCL_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_I2C0_SCL_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTB1 (number 36), J4[10]/A4-I2C0_SDA/ADC0_SE9
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_I2C0_SDA_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_I2C0_SDA_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_I2C0_SDA_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTD4 (number 61), J1[9]/SDA_LED
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SDA_LED_FGPIO FGPIOD             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SDA_LED_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SDA_LED_GPIO_PIN_MASK (1U << 4U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SDA_LED_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_SDA_LED_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_SDA_LED_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTC10 (number 55), J2[1]/I2C1_SCL
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_I2C1_SCL_FGPIO FGPIOC              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_I2C1_SCL_GPIO GPIOC                /*!<@brief GPIO peripheral base pointer */
#define BOARD_I2C1_SCL_GPIO_PIN_MASK (1U << 10U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_I2C1_SCL_PORT PORTC                /*!<@brief PORT peripheral base pointer */
#define BOARD_I2C1_SCL_PIN 10U                   /*!<@brief PORT pin number */
#define BOARD_I2C1_SCL_PIN_MASK (1U << 10U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*! @name PORTA13 (number 29), J1[10]/D4-TPM1_CH1/D4-LED_BLUE
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_MOTOR_FGPIO FGPIOD              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_MOTOR_GPIO GPIOD                /*!<@brief GPIO peripheral base pointer */
#define BOARD_MOTOR_GPIO_PIN_MASK (1U << 1U) /*!<@brief GPIO pin mask */



/* Symbols to be used with PORT driver */
#define BOARD_MOTOR_PORT PORTD                /*!<@brief PORT peripheral base pointer */
#define BOARD_MOTOR_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_MOTOR_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */





/* Symbols to be used with GPIO driver */
#define BOARD_LED_BLUE_FGPIO FGPIOA              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO GPIOA                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO_PIN_MASK (1U << 13U) /*!<@brief GPIO pin mask */



/* Symbols to be used with PORT driver */
#define BOARD_LED_BLUE_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_BLUE_PIN 13U                   /*!<@brief PORT pin number */
#define BOARD_LED_BLUE_PIN_MASK (1U << 13U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*! @name PORTB18 (number 41), J2[11]/D11[1]/LED_RED
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_RED_FGPIO FGPIOB              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO_PIN_MASK (1U << 18U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_RED_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_RED_PIN 18U                   /*!<@brief PORT pin number */
#define BOARD_LED_RED_PIN_MASK (1U << 18U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTB19 (number 42), J2[13]/D11[4]/LED_GREEN
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_GREEN_FGPIO FGPIOB              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO GPIOB                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO_PIN_MASK (1U << 19U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_GREEN_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_GREEN_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_LED_GREEN_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void);

/*! @name PORTA4 (number 26), J2[5]/SW1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW1_FGPIO FGPIOA             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW1_GPIO GPIOA               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW1_GPIO_PIN_MASK (1U << 4U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW1_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW1_PIN 4U                   /*!<@brief PORT pin number */
#define BOARD_SW1_PIN_MASK (1U << 4U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*! @name PORTC1 (number 44), J3[13]/SW3
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW3_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW3_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW3_GPIO_PIN_MASK (1U << 1U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW3_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW3_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_SW3_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitButtonsPins(void);

/*! @name PORTE29 (number 17), TOUCH_A
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_TOUCH_A_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_TOUCH_A_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_TOUCH_A_GPIO_PIN_MASK (1U << 29U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_TOUCH_A_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_TOUCH_A_PIN 29U                   /*!<@brief PORT pin number */
#define BOARD_TOUCH_A_PIN_MASK (1U << 29U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTE30 (number 18), TOUCH_B
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_TOUCH_B_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_TOUCH_B_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_TOUCH_B_GPIO_PIN_MASK (1U << 30U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_TOUCH_B_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_TOUCH_B_PIN 30U                   /*!<@brief PORT pin number */
#define BOARD_TOUCH_B_PIN_MASK (1U << 30U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTSIPins(void);

/*! @name USB0_DP (number 5), J10[3]
  @{ */
/* @} */

/*! @name USB0_DM (number 6), J10[2]
  @{ */
/* @} */

/*! @name PORTA5 (number 27), J2[4]/D9-TPM0_CH2
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_TPM0_CH2_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_TPM0_CH2_PIN 5U                   /*!<@brief PORT pin number */
#define BOARD_TPM0_CH2_PIN_MASK (1U << 5U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name USB_VDD (number 7), P3V3_KL27Z
  @{ */
/* @} */

/*! @name PORTC0 (number 43), J4[4]/A1-ADC0_SE14
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_USB_SOF_OUT_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_USB_SOF_OUT_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_USB_SOF_OUT_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                   /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitUSBPins(void);

/*! @name PORTC3 (number 46), J2[15]/U10[11]/J28[1]/INT1_ACCEL
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INT1_ACCEL_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_INT1_ACCEL_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INT1_ACCEL_GPIO_PIN_MASK (1U << 3U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INT1_ACCEL_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INT1_ACCEL_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_INT1_ACCEL_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*! @name PORTC2 (number 45), J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INT2_ACCEL_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_INT2_ACCEL_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INT2_ACCEL_GPIO_PIN_MASK (1U << 2U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INT2_ACCEL_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INT2_ACCEL_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_INT2_ACCEL_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*! @name PORTD6 (number 63), J2[18]/J24[1]/D14-I2C1_SDA
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_ACCEL_I2C1_SDA_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_ACCEL_I2C1_SDA_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_ACCEL_I2C1_SDA_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTD7 (number 64), J2[20]/J23[1]/D15-I2C1_SCL
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_ACCEL_I2C1_SCL_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_ACCEL_I2C1_SCL_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_ACCEL_I2C1_SCL_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitACCEL_I2CPins(void);

/*! @name PORTD7 (number 64), J2[20]/J23[1]/D15-I2C1_SCL
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_MAG_I2C1_SCL_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_MAG_I2C1_SCL_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_MAG_I2C1_SCL_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                    /* @} */

/*! @name PORTD6 (number 63), J2[18]/J24[1]/D14-I2C1_SDA
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_MAG_I2C1_SDA_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_MAG_I2C1_SDA_PIN 6U                   /*!<@brief PORT pin number */
#define BOARD_MAG_I2C1_SDA_PIN_MASK (1U << 6U)      /*!<@brief PORT pin mask */
                                                    /* @} */

/*! @name PORTC2 (number 45), J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INT1_MAG_FGPIO FGPIOC             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_INT1_MAG_GPIO GPIOC               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INT1_MAG_GPIO_PIN_MASK (1U << 2U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INT1_MAG_PORT PORTC               /*!<@brief PORT peripheral base pointer */
#define BOARD_INT1_MAG_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_INT1_MAG_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitMAGNET_I2CPins(void);

#define SOPT5_LPUART0RXSRC_LPUART_RX 0x00u /*!<@brief LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX 0x00u /*!<@brief LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*! @name PORTA1 (number 23), J1[2]/J25[1]/D0-UART0_RX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_RX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_RX_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_RX_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*! @name PORTA2 (number 24), J1[4]/J26[1]/D1-UART0_TX
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_DEBUG_UART0_TX_PORT PORTA               /*!<@brief PORT peripheral base pointer */
#define BOARD_DEBUG_UART0_TX_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_DEBUG_UART0_TX_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void);

/*! @name PORTE22 (number 11), THER_A
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_THER_A_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_THER_A_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_THER_A_GPIO_PIN_MASK (1U << 22U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_THER_A_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_THER_A_PIN 22U                   /*!<@brief PORT pin number */
#define BOARD_THER_A_PIN_MASK (1U << 22U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTE23 (number 12), THER_B
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_THER_B_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_THER_B_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_THER_B_GPIO_PIN_MASK (1U << 23U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_THER_B_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_THER_B_PIN 23U                   /*!<@brief PORT pin number */
#define BOARD_THER_B_PIN_MASK (1U << 23U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTHERPins(void);

/*! @name PORTA18 (number 32), EXTAL_32KHZ
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_EXTAL0_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_EXTAL0_PIN 18U                   /*!<@brief PORT pin number */
#define BOARD_EXTAL0_PIN_MASK (1U << 18U)      /*!<@brief PORT pin mask */
                                               /* @} */

/*! @name PORTA19 (number 33), XTAL_32KHZ
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_XTAL0_PORT PORTA                /*!<@brief PORT peripheral base pointer */
#define BOARD_XTAL0_PIN 19U                   /*!<@brief PORT pin number */
#define BOARD_XTAL0_PIN_MASK (1U << 19U)      /*!<@brief PORT pin mask */
                                              /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSCPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
