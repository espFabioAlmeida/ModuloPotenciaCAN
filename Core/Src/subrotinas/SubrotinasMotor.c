///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasMotor.c
//AUTOR:      Fábio Almeida
//CRIADO:     10/12/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
# include "main.h"
# include "global.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
/*==============================================================================
ATUALIZA MOTOR
==============================================================================*/
void atualizaMotor() {
	if(!flagAtualizaMotor) {
		return;
	}
	flagAtualizaMotor = false;

	if(contadorTimeoutAtualizacao >= TIMEOUT_ATUALIZACAO) {
		valorMotor = 0;
		flagMotorLigado = false;
	}

	if(flagMotorLigado) {
		if(valorMotor > VALOR_MAXIMO_MOTOR) {
			atualizaPWM(0);
			return;
		}
		atualizaPWM(valorMotor);
		return;
	}

	atualizaPWM(0);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
