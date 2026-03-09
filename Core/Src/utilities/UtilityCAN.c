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
#define ENDERECO_ECU_PACOTE_1		0x1BB81A01
#define ENDERECO_ECU_PACOTE_2		0x1BB81A02
#define ENDERECO_ECU_PACOTE_3		0x1BB81A03
#define ENDERECO_RESPOSTA_PADRAO	0x1E30FC90
/*==============================================================================
RECEBE PACOTE CAN
==============================================================================*/
void recebePacoteCAN() {
	if(flagPacoteCAN) {
		flagPacoteCAN = false;

		switch(enderecoModulo) {
			case 90:
			case 91:
			case 92:
			case 93:
				if(canRxHeader.ExtId == ENDERECO_ECU_PACOTE_1) {
					protocoloCAN();
					flagLedCOM = true;
				}
				break;

			case 94:
			case 95:
			case 96:
			case 97:
				if(canRxHeader.ExtId == ENDERECO_ECU_PACOTE_2) {
					protocoloCAN();
					flagLedCOM = true;
				}
				break;
		}
	}
}
/*==============================================================================
ENVIA PACOTE CAN
==============================================================================*/
void enviaPacoteCAN() {
	uint8_t endereco = enderecoModulo - ENDERECO_MODULO_PADRAO;

	canTxHeader.ExtId = ENDERECO_RESPOSTA_PADRAO + endereco;
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
