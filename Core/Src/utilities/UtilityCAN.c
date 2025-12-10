///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityCAN
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES
==============================================================================*/
/*==============================================================================
RECEBE PACOTE CAN
==============================================================================*/
void recebePacoteCAN() {
	if(flagPacoteCAN) {
		flagPacoteCAN = false;

		if(canRxHeader.ExtId == enderecoCPU) {
			protocoloCAN();
			flagLedCOM = true;
		}
	}
}
/*==============================================================================
ENVIA PACOTE CAN
==============================================================================*/
void enviaPacoteCAN() {
	canTxHeader.ExtId = enderecoResposta;
	canTxHeader.RTR = CAN_RTR_DATA;
	canTxHeader.IDE = CAN_ID_EXT;
	canTxHeader.DLC = 8;
	canTxHeader.TransmitGlobalTime = DISABLE;

	for(uint8_t i = 0; i < 8; i ++) { //não há dados a serem enviados por hora
		canTxBuffer[i] = 0x00;
	}

	if(HAL_CAN_AddTxMessage(&hcan, &canTxHeader, canTxBuffer, &canTxMailbox) != HAL_OK) {
	    Error_Handler();
	}

	while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan) != 3) {
		//Aguarda fim da transmissão
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
