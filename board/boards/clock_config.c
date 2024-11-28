/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/
/*
 * How to setup clock using clock driver functions:
 *
 * 1. CLOCK_SetSimSafeDivs, to make sure core clock, bus clock, flexbus clock
 *    and flash clock are in allowed range during clock mode switch.
 *
 * 2. Call CLOCK_Osc0Init to setup OSC clock, if it is used in target mode.
 *
 * 3. Call CLOCK_SetMcgliteConfig to set MCG_Lite configuration.
 *
 * 4. Call CLOCK_SetSimConfig to set the clock configuration in SIM.
 */

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v7.0
processor: MKL27Z64xxx4
package_id: MKL27Z64VLH4
mcu_data: ksdk2_0
processor_version: 8.0.1
board: FRDM-KL27Z
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

#include "fsl_smc.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SIM_CLKOUT_SEL_IRC48M_CLK                         7U  /*!< CLKOUT pin clock select: IRC48M clock */
#define SIM_FLEXIO_CLK_SEL_IRC48M_CLK                     1U  /*!< FLEXIO clock select: IRC48M clock */
#define SIM_LPUART_CLK_SEL_IRC48M_CLK                     1U  /*!< LPUART clock select: IRC48M clock */
#define SIM_OSC32KSEL_OSC32KCLK_CLK                       0U  /*!< OSC32KSEL select: OSC32KCLK clock */
#define SIM_RTC_CLKOUT_SEL_OSCERCLK_CLK                   1U  /*!< RTC clock output select: OSCERCLK clock */
#define SIM_TPM_CLK_SEL_IRC48M_CLK                        1U  /*!< TPM clock select: IRC48M clock */
#define SIM_USB_CLK_48000000HZ                     48000000U  /*!< Input SIM frequency for USB: 48000000Hz */

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* System clock frequency. */
extern uint32_t SystemCoreClock;

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
    BOARD_BootClockRUN();
}

/*******************************************************************************
 ********************** Configuration BOARD_BootClockRUN ***********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockRUN
called_from_default_init: true
outputs:
- {id: Bus_clock.outFreq, value: 24 MHz}
- {id: CLKOUT.outFreq, value: 48 MHz}
- {id: COPCLK.outFreq, value: 32.768 kHz}
- {id: Core_clock.outFreq, value: 48 MHz}
- {id: ERCLK32K.outFreq, value: 32.768 kHz}
- {id: FLEXIOCLK.outFreq, value: 48 MHz}
- {id: Flash_clock.outFreq, value: 24 MHz}
- {id: LPO_clock.outFreq, value: 1 kHz}
- {id: LPUART0CLK.outFreq, value: 48 MHz}
- {id: LPUART1CLK.outFreq, value: 48 MHz}
- {id: MCGIRCLK.outFreq, value: 8 MHz}
- {id: MCGPCLK.outFreq, value: 48 MHz}
- {id: OSCERCLK.outFreq, value: 32.768 kHz}
- {id: RTC_CLKOUT.outFreq, value: 32.768 kHz}
- {id: System_clock.outFreq, value: 48 MHz}
- {id: TPMCLK.outFreq, value: 48 MHz}
- {id: USB48MCLK.outFreq, value: 48 MHz}
settings:
- {id: MCGMode, value: HIRC}
- {id: CLKOUTConfig, value: 'yes'}
- {id: COPClkConfig, value: 'yes'}
- {id: FLEXIOClkConfig, value: 'yes'}
- {id: LPUART0ClkConfig, value: 'yes'}
- {id: LPUART1ClkConfig, value: 'yes'}
- {id: MCG.CLKS.sel, value: MCG.HIRC}
- {id: MCG_C2_OSC_MODE_CFG, value: ModeOscLowPower}
- {id: MCG_MC_HIRCEN_CFG, value: Enabled}
- {id: OSC0_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC_CR_SYS_OSC_CAP_LOAD_CFG, value: SC12PF}
- {id: RTCCLKOUTConfig, value: 'yes'}
- {id: SIM.CLKOUTSEL.sel, value: MCG.MCGPCLK}
- {id: SIM.COPCLKSEL.sel, value: OSC.OSCERCLK}
- {id: SIM.FLEXIOSRCSEL.sel, value: MCG.MCGPCLK}
- {id: SIM.LPUART0SRCSEL.sel, value: MCG.MCGPCLK}
- {id: SIM.LPUART1SRCSEL.sel, value: MCG.MCGPCLK}
- {id: SIM.RTCCLKOUTSEL.sel, value: OSC.OSCERCLK}
- {id: SIM.TPMSRCSEL.sel, value: MCG.MCGPCLK}
- {id: SIM.USBSRCSEL.sel, value: MCG.MCGPCLK}
- {id: TPMClkConfig, value: 'yes'}
- {id: USBClkConfig, value: 'yes'}
sources:
- {id: MCG.HIRC.outFreq, value: 48 MHz}
- {id: OSC.OSC.outFreq, value: 32.768 kHz, enabled: true}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockRUN configuration
 ******************************************************************************/
const mcglite_config_t mcgliteConfig_BOARD_BootClockRUN =
    {
        .outSrc = kMCGLITE_ClkSrcHirc,            /* MCGOUTCLK source is HIRC */
        .irclkEnableMode = kMCGLITE_IrclkEnable,  /* MCGIRCLK enabled, MCGIRCLK disabled in STOP mode */
        .ircs = kMCGLITE_Lirc8M,                  /* Slow internal reference (LIRC) 8 MHz clock selected */
        .fcrdiv = kMCGLITE_LircDivBy1,            /* Low-frequency Internal Reference Clock Divider: divided by 1 */
        .lircDiv2 = kMCGLITE_LircDivBy1,          /* Second Low-frequency Internal Reference Clock Divider: divided by 1 */
        .hircEnableInNotHircMode = true,          /* HIRC source is enabled */
    };
const sim_clock_config_t simConfig_BOARD_BootClockRUN =
    {
        .er32kSrc = SIM_OSC32KSEL_OSC32KCLK_CLK,  /* OSC32KSEL select: OSC32KCLK clock */
        .clkdiv1 = 0x10000U,                      /* SIM_CLKDIV1 - OUTDIV1: /1, OUTDIV4: /2 */
    };
const osc_config_t oscConfig_BOARD_BootClockRUN =
    {
        .freq = 32768U,                           /* Oscillator frequency: 32768Hz */
        .capLoad = (kOSC_Cap4P | kOSC_Cap8P),     /* Oscillator capacity load: 12pF */
        .workMode = kOSC_ModeOscLowPower,         /* Oscillator low power */
        .oscerConfig =
            {
                .enableMode = kOSC_ErClkEnable,   /* Enable external reference clock, disable external reference clock in STOP mode */
            }
    };

/*******************************************************************************
 * Code for BOARD_BootClockRUN configuration
 ******************************************************************************/
void BOARD_BootClockRUN(void)
{
    /* Set the system clock dividers in SIM to safe value. */
    CLOCK_SetSimSafeDivs();
    /* Initializes OSC0 according to board configuration. */
    CLOCK_InitOsc0(&oscConfig_BOARD_BootClockRUN);
    CLOCK_SetXtal0Freq(oscConfig_BOARD_BootClockRUN.freq);
    /* Set MCG to HIRC mode. */
    CLOCK_SetMcgliteConfig(&mcgliteConfig_BOARD_BootClockRUN);
    /* Set the clock configuration in SIM module. */
    CLOCK_SetSimConfig(&simConfig_BOARD_BootClockRUN);
    /* Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKRUN_CORE_CLOCK;
    /* Set RTC_CLKOUT source. */
    CLOCK_SetRtcClkOutClock(SIM_RTC_CLKOUT_SEL_OSCERCLK_CLK);
    /* Enable USB FS clock. */
    CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcIrc48M, SIM_USB_CLK_48000000HZ);
    /* Set LPUART0 clock source. */
    CLOCK_SetLpuart0Clock(SIM_LPUART_CLK_SEL_IRC48M_CLK);
    /* Set LPUART1 clock source. */
    CLOCK_SetLpuart1Clock(SIM_LPUART_CLK_SEL_IRC48M_CLK);
    /* Set FLEXIO clock source. */
    CLOCK_SetFlexio0Clock(SIM_FLEXIO_CLK_SEL_IRC48M_CLK);
    /* Set TPM clock source. */
    CLOCK_SetTpmClock(SIM_TPM_CLK_SEL_IRC48M_CLK);
    /* Set CLKOUT source. */
    CLOCK_SetClkOutClock(SIM_CLKOUT_SEL_IRC48M_CLK);
}

/*******************************************************************************
 ********************* Configuration BOARD_BootClockVLPR ***********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockVLPR
outputs:
- {id: Bus_clock.outFreq, value: 1 MHz}
- {id: Core_clock.outFreq, value: 2 MHz}
- {id: Flash_clock.outFreq, value: 1 MHz}
- {id: LPO_clock.outFreq, value: 1 kHz}
- {id: MCGIRCLK.outFreq, value: 2 MHz}
- {id: System_clock.outFreq, value: 2 MHz}
settings:
- {id: MCGMode, value: LIRC2M}
- {id: powerMode, value: VLPR}
- {id: MCG.LIRCDIV1.scale, value: '1', locked: true}
- {id: OSC0_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC_CR_ERCLKEN_CFG, value: Enabled}
- {id: OSC_CR_SYS_OSC_CAP_LOAD_CFG, value: SC12PF}
- {id: RTCCLKOUTConfig, value: 'yes'}
- {id: SIM.OUTDIV1.scale, value: '1', locked: true}
- {id: SIM.OUTDIV4.scale, value: '2', locked: true}
- {id: SIM.RTCCLKOUTSEL.sel, value: OSC.OSCERCLK}
sources:
- {id: MCG.LIRC.outFreq, value: 2 MHz}
- {id: OSC.OSC.outFreq, value: 32.768 kHz}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockVLPR configuration
 ******************************************************************************/
const mcglite_config_t mcgliteConfig_BOARD_BootClockVLPR =
    {
        .outSrc = kMCGLITE_ClkSrcLirc,            /* MCGOUTCLK source is LIRC */
        .irclkEnableMode = kMCGLITE_IrclkEnable,  /* MCGIRCLK enabled, MCGIRCLK disabled in STOP mode */
        .ircs = kMCGLITE_Lirc2M,                  /* Slow internal reference (LIRC) 2 MHz clock selected */
        .fcrdiv = kMCGLITE_LircDivBy1,            /* Low-frequency Internal Reference Clock Divider: divided by 1 */
        .lircDiv2 = kMCGLITE_LircDivBy1,          /* Second Low-frequency Internal Reference Clock Divider: divided by 1 */
        .hircEnableInNotHircMode = false,         /* HIRC source is not enabled */
    };
const sim_clock_config_t simConfig_BOARD_BootClockVLPR =
    {
        .er32kSrc = SIM_OSC32KSEL_OSC32KCLK_CLK,  /* OSC32KSEL select: OSC32KCLK clock */
        .clkdiv1 = 0x10000U,                      /* SIM_CLKDIV1 - OUTDIV1: /1, OUTDIV4: /2 */
    };
const osc_config_t oscConfig_BOARD_BootClockVLPR =
    {
        .freq = 0U,                               /* Oscillator frequency: 0Hz */
        .capLoad = (kOSC_Cap4P | kOSC_Cap8P),     /* Oscillator capacity load: 12pF */
        .workMode = kOSC_ModeExt,                 /* Use external clock */
        .oscerConfig =
            {
                .enableMode = kOSC_ErClkEnable,   /* Enable external reference clock, disable external reference clock in STOP mode */
            }
    };

/*******************************************************************************
 * Code for BOARD_BootClockVLPR configuration
 ******************************************************************************/
void BOARD_BootClockVLPR(void)
{
    /* Set the system clock dividers in SIM to safe value. */
    CLOCK_SetSimSafeDivs();
    /* Set MCG to LIRC2M mode. */
    CLOCK_SetMcgliteConfig(&mcgliteConfig_BOARD_BootClockVLPR);
    /* Set the clock configuration in SIM module. */
    CLOCK_SetSimConfig(&simConfig_BOARD_BootClockVLPR);
    /* Set VLPR power mode. */
    SMC_SetPowerModeProtection(SMC, kSMC_AllowPowerModeAll);
#if (defined(FSL_FEATURE_SMC_HAS_LPWUI) && FSL_FEATURE_SMC_HAS_LPWUI)
    SMC_SetPowerModeVlpr(SMC, false);
#else
    SMC_SetPowerModeVlpr(SMC);
#endif
    while (SMC_GetPowerModeState(SMC) != kSMC_PowerStateVlpr)
    {
    }
    /* Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKVLPR_CORE_CLOCK;
}

