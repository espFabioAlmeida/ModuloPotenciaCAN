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


extern uint32_t
	enderecoCPU;

#endif /* INC_GLOBAL_H_ */
