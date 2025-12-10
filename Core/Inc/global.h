/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define VERSAO_FIRMWARE 1

enum BOOL {
	false,
	true
};

#define ENDERECO_CAN_CPU_PADRAO 0x132F7890

#define VALOR_MAXIMO_MOTOR 4095
#define VALOR_75_MOTOR ((VALOR_MAXIMO_MOTOR * 3) / 4)
#define VALOR_50_MOTOR (VALOR_MAXIMO_MOTOR / 2)
#define VALOR_25_MOTOR (VALOR_MAXIMO_MOTOR / 4)

extern CAN_TxHeaderTypeDef	canTxHeader;
extern CAN_RxHeaderTypeDef	canRxHeader;


extern uint8_t
	flagPacoteCAN,
	flagLedCOM,

	flagMotorLigado,
	flagAtualizaMotor;

extern uint16_t
	valorMotor;

extern uint32_t
	canTxMailbox,
	enderecoCPU;

extern uint8_t
	canTxBuffer[8],
	canRxBuffer[8];
#endif /* INC_GLOBAL_H_ */
