
/*
 * affichage.c
 *
 *  Nov. 25, 2020
 *  Original file : Bosch
 *  Modified by : kamel adi
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_i2c.h"
#include "delay/delay.h"
#include "LiquidCrystal_I2C.h"


#include "bmp280.h"

#define I2C_MASTER_BASEADDR I2C0
#define	I2C_BUFFER_LEN 25
struct bmp280_dev bmp;

volatile uint32_t g_systickCounter;

void SysTick_Handler(void)
{
if (g_systickCounter != 0U)
{
g_systickCounter--;
}
}
void SysTick_DelayTicks(uint32_t n)
{
g_systickCounter = n;
while (g_systickCounter != 0U)
{
}
}

void delay_ms(uint32_t period_ms);
int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t spi_reg_write(uint8_t cs, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t spi_reg_read(uint8_t cs, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
void print_rslt(const char api_name[], int8_t rslt);
void initializeLCD();
void initializeBMP();
void resultBMP();
void initGPIO();
int8_t rslt;
struct bmp280_dev bmp;
struct bmp280_config conf;
struct bmp280_uncomp_data ucomp_data;
int32_t temp32;
double temp;
int MOTOR_STATUS = 0;



int main(void)
{

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
    BOARD_InitLEDsPins();
    initGPIO();
    initializeLCD();
    initializeBMP();





    while (1)
    {
    	resultBMP();
    }

    return 0;
}


int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
	status_t status;

		uint32_t iError = 0;
		uint8_t array[I2C_BUFFER_LEN]= {0};
		uint8_t stringpos = 0;
		array[0] = reg_addr;

		i2c_master_transfer_t masterXfer;
	    memset(&masterXfer, 0, sizeof(masterXfer));

		masterXfer.slaveAddress   = i2c_addr;
		masterXfer.direction      = kI2C_Write;
		masterXfer.subaddress     = reg_addr;
		masterXfer.subaddressSize = 1;
		masterXfer.data           = &array[0];
		masterXfer.dataSize       = length;
		masterXfer.flags          = kI2C_TransferDefaultFlag;

		for (stringpos = 0; stringpos < length; stringpos++) {
				array[stringpos] = *(reg_data + stringpos);
			}

		status = I2C_MasterTransferBlocking(I2C_MASTER_BASEADDR, &masterXfer);

		if (status == kStatus_Success)
		{
			iError = 0;
		}
		else
		{
				iError = 2;  // Doit être revu ....
		}

		return (uint8_t)iError;

}


int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{

		status_t status;
		uint32_t iError = 0;
		uint8_t array[I2C_BUFFER_LEN] = {0};
		uint8_t stringpos = 0;
		array[0] = reg_addr;
		i2c_master_transfer_t masterXfer;

		memset(&masterXfer, 0, sizeof(masterXfer));
		masterXfer.slaveAddress   = i2c_addr;
		masterXfer.direction      = kI2C_Read;
		masterXfer.subaddress     = reg_addr;
		masterXfer.subaddressSize = 1;
		masterXfer.data           = array;
		masterXfer.dataSize       = length;
		masterXfer.flags          = kI2C_TransferDefaultFlag;

		status = I2C_MasterTransferBlocking(I2C_MASTER_BASEADDR, &masterXfer);

		if (status == kStatus_Success)
			{
				iError = 0;
			}
			else
			{
					iError = 2;  // Doit être revu ....
			}

		for (stringpos = 0; stringpos < length; stringpos++) {
			*(reg_data + stringpos) = array[stringpos];
		}

		return (uint8_t)iError;
}

int8_t spi_reg_write(uint8_t cs, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{

    /* Implement the SPI write routine according to the target machine. */
    return -1;
}

int8_t spi_reg_read(uint8_t cs, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{

    /* Implement the SPI read routine according to the target machine. */
    return -1;
}


void print_rslt(const char api_name[], int8_t rslt)
{
    if (rslt != BMP280_OK)
    {
        printf("%s\t", api_name);
        if (rslt == BMP280_E_NULL_PTR)
        {
            printf("Error [%d] : Null pointer error\r\n", rslt);
        }
        else if (rslt == BMP280_E_COMM_FAIL)
        {
            printf("Error [%d] : Bus communication failed\r\n", rslt);
        }
        else if (rslt == BMP280_E_IMPLAUS_TEMP)
        {
            printf("Error [%d] : Invalid Temperature\r\n", rslt);
        }
        else if (rslt == BMP280_E_DEV_NOT_FOUND)
        {
            printf("Error [%d] : Device not found\r\n", rslt);
        }
        else
        {
            /* For more error codes refer "*_defs.h" */
            printf("Error [%d] : Unknown error code\r\n", rslt);
        }
    }
}

void initializeBMP(){
	/* Map the delay function pointer with the function responsible for implementing the delay */
	    bmp.delay_ms = delay_ms;

	    /* Assign device I2C address based on the status of SDO pin (GND for PRIMARY(0x76) & VDD for SECONDARY(0x77)) */
	    bmp.dev_id = /*BMP280_I2C_ADDR_SEC;*/ BMP280_I2C_ADDR_PRIM;

	    /* Select the interface mode as I2C */
	    bmp.intf = BMP280_I2C_INTF;

	    /* Map the I2C read & write function pointer with the functions responsible for I2C bus transfer */
	    bmp.read = i2c_reg_read;
	    bmp.write = i2c_reg_write;

	    /* To enable SPI interface: comment the above 4 lines and uncomment the below 4 lines */

	    /*
	     * bmp.dev_id = 0;
	     * bmp.read = spi_reg_read;
	     * bmp.write = spi_reg_write;
	     * bmp.intf = BMP280_SPI_INTF;
	     */
	    rslt = bmp280_init(&bmp);
	    print_rslt(" bmp280_init status", rslt);

	    /* Always read the current settings before writing, especially when
	     * all the configuration is not modified
	     */
	    rslt = bmp280_get_config(&conf, &bmp);
	    print_rslt(" bmp280_get_config status", rslt);

	    /* configuring the temperature oversampling, filter coefficient and output data rate */
	    /* Overwrite the desired settings */
	    conf.filter = BMP280_FILTER_COEFF_2;

	    /* Temperature oversampling set at 4x */
	    conf.os_temp = BMP280_OS_4X;

	    /* Pressure over sampling none (disabling pressure measurement) */
	    //conf.os_pres = BMP280_OS_NONE;

	    /* Setting the output data rate as 1HZ(1000ms) */
	    conf.odr = BMP280_ODR_1000_MS;
	    rslt = bmp280_set_config(&conf, &bmp);
	    print_rslt(" bmp280_set_config status", rslt);

	    /* Always set the power mode after setting the configuration */
	    rslt = bmp280_set_power_mode(BMP280_NORMAL_MODE, &bmp);
	    print_rslt(" bmp280_set_power_mode status", rslt);
}

void initializeLCD(){
	// initialize the LCD

    if (SysTick_Config(SystemCoreClock / 1000U))
    {
     PRINTF("Echec dans l'initialisation du systick\n");
    }

    i2c_master_config_t config = {
                .enableMaster = true,
                .enableStopHold = false,
                .baudRate_Bps = 100000,
                .glitchFilterWidth = 0
             };


        I2C_MasterInit(I2C_MASTER_BASEADDR, &config, CLOCK_GetFreq(I2C0_CLK_SRC));

	            	begin();

	            	backlight();
	            	cursor();

	            	clear();
	            	print("PROJET");
	            	setCursor(0,1);
	            	print("Ventillateur");
	            	setCursor(0,0);


}

void initGPIO(){
		GPIOB->PSOR |= 1<<19;
	    GPIOB->PDDR |= 1<<19;
	    GPIOB->PSOR |= 1<<18;
	    GPIOB->PDDR |= 1<<18;
	    GPIOA->PSOR |= 1<<13;
	    GPIOA->PDDR |= 1<<13;
}

void resultBMP(){
			rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);

	        /* Getting the 32 bit compensated temperature */
	        rslt = bmp280_get_comp_temp_32bit(&temp32, ucomp_data.uncomp_temp, &bmp);

	        /* Getting the compensated temperature as floating point value */
	        rslt = bmp280_get_comp_temp_double(&temp, ucomp_data.uncomp_temp, &bmp);
	        printf("UT: %ld, T32: %ld, T: %f \r\n", ucomp_data.uncomp_temp, temp32, temp);
	        //writeNumber((float)temp);
	        /* Sleep time between measurements = BMP280_ODR_1000_MS */

	        if(temp<=25) // Température minimale du buffer
	        {
	        	MOTOR_STATUS = 0; // Moteur Off
	        	GPIOB->PSOR |= 1<<19; // Éteindre LED verte
	        	GPIOA->PCOR |= 1<<13; // Allumer LED bleue
	        	GPIOD->PCOR |= 1<<1; // Éteindre moteur

	        }
	        else if(temp>=26) // Température maximale du buffer
	        {
	        	if(MOTOR_STATUS!=1){ // Moteur est en mode OFF
	        	GPIOA->PSOR |= 1<<13; // Éteindre LED bleue
	        	GPIOB->PCOR |= 1<<18; // Allumer LED rouge

                SysTick_DelayTicks(2000U);

                MOTOR_STATUS = 1; // Moteur On
                GPIOD->PDDR |= 1<<1; // Set moteur comme output
                GPIOB->PSOR |= 1<<18; // Éteindre LED rouge
                GPIOB->PCOR |= 1<<19; // Allumer LED verte
                GPIOD->PSOR |= 1<<1; // Allumer moteur
                }

	        }


	        	clear();
	        	char intStr[50];

	        	if(MOTOR_STATUS==1){
	        		sprintf(intStr, "temp: %.2fC ON", temp);
	        	} else {
	        		sprintf(intStr, "temp: %.2fC OFF", temp);
	        	}

	        	print(intStr);

}


