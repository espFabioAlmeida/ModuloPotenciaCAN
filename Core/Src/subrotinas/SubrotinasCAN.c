///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasCAN
//AUTOR:      Fábio Almeida
//CRIADO:     19/09/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
PROTOCOLO CAN
==============================================================================*/
void protocoloCAN() {

	switch(enderecoModulo) {
		case 90:
		case 94:
			valorMotor = make16(canRxBuffer[1], canRxBuffer[0]);
			break;

		case 91:
		case 95:
			valorMotor = make16(canRxBuffer[3], canRxBuffer[2]);
			break;

		case 92:
		case 96:
			valorMotor = make16(canRxBuffer[5], canRxBuffer[4]);
			break;

		case 93:
		case 97:
			valorMotor = make16(canRxBuffer[7], canRxBuffer[6]);
			break;
	}

	if(valorMotor) {
		flagMotorLigado = true;
	}
	else {
		flagMotorLigado = false;
	}

	enviaPacoteCAN();
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
