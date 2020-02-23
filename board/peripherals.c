/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v7.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 7.0.1
board: FRDM-K64F
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 8c2dbb81-2b5a-4f0e-b4e8-89d0096b4c0d
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'msg'
- type_id: 'msg_6e2baaf3b97dbeef01c0043275f9a0e7'
- global_messages: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * UART4 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'UART4'
- type: 'uart'
- mode: 'interrupts'
- custom_name_enabled: 'false'
- type_id: 'uart_88ab1eca0cddb7ee407685775de016d5'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'UART4'
- config_sets:
  - uartConfig_t:
    - uartConfig:
      - clockSource: 'BusInterfaceClock'
      - clockSourceFreq: 'GetFreq'
      - baudRate_Bps: '9600'
      - parityMode: 'kUART_ParityDisabled'
      - stopBitCount: 'kUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '0'
      - idleType: 'kUART_IdleTypeStartBit'
      - enableTx: 'true'
      - enableRx: 'true'
  - interruptsCfg:
    - interrupts: 'kUART_RxDataRegFullInterruptEnable'
    - interrupt_vectors:
      - enable_rx_tx_irq: 'true'
      - interrupt_rx_tx:
        - IRQn: 'UART4_RX_TX_IRQn'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
      - enable_err_irq: 'false'
      - interrupt_err:
        - IRQn: 'UART4_ERR_IRQn'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const uart_config_t UART4_config = {
  .baudRate_Bps = 9600,
  .parityMode = kUART_ParityDisabled,
  .stopBitCount = kUART_OneStopBit,
  .txFifoWatermark = 0,
  .rxFifoWatermark = 0,
  .idleType = kUART_IdleTypeStartBit,
  .enableTx = true,
  .enableRx = true
};

void UART4_init(void) {
  UART_Init(UART4_PERIPHERAL, &UART4_config, UART4_CLOCK_SOURCE);
  UART_EnableInterrupts(UART4_PERIPHERAL, kUART_RxDataRegFullInterruptEnable);
  /* Enable interrupt UART4_RX_TX_IRQn request in the NVIC */
  EnableIRQ(UART4_SERIAL_RX_TX_IRQN);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  UART4_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
