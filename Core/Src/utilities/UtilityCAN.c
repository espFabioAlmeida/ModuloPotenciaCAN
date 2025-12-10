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
	//Por enquanto não há dados a serem transmitidos pela CAN
	/*
	canTxHeader.ExtId = HIDRA_ADDRESS;
	canTxHeader.RTR = CAN_RTR_DATA;
	canTxHeader.IDE = CAN_ID_EXT;
	canTxHeader.DLC = 8;
	canTxHeader.TransmitGlobalTime = DISABLE;

	if(HAL_CAN_AddTxMessage(&hcan, &canTxHeader, canTxBuffer, &canTxMailbox) != HAL_OK) {
	    Error_Handler();
	}

	while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan) != 3) {
		//Aguarda fim da transmissão
	}*/
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
