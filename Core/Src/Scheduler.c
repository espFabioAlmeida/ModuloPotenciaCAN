///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    Scheduler
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
# include "main.h"
# include "global.h"
/*==============================================================================
TAREFAS 100us
==============================================================================*/
void tarefas100us() {

}
/*==============================================================================
TAREFAS 1ms
==============================================================================*/
void tarefas1ms() {

}
/*==============================================================================
TAREFAS 10ms
==============================================================================*/
void tarefas10ms() {

}
/*==============================================================================
TAREFAS 100ms
==============================================================================*/
void tarefas100ms() {
	static uint8_t contaPiscaLed = 0, conta500ms = 0;
	uint8_t comparacaoContaPiscaLed = 0;
	reiniciaWatchDog();


	if(flagLedCOM) {
		flagLedCOM = false;
		off(LED_COM_GPIO_Port, LED_COM_Pin);
	}
	else {
		on(LED_COM_GPIO_Port, LED_COM_Pin);
	}

	if(flagMotorLigado) {
		contaPiscaLed ++;

		if(valorMotor > VALOR_75_MOTOR) {
			comparacaoContaPiscaLed = 1;
		}
		else if(valorMotor > VALOR_50_MOTOR) {
			comparacaoContaPiscaLed = 3;
		}
		else if(valorMotor > VALOR_25_MOTOR) {
			comparacaoContaPiscaLed = 6;
		}
		else {
			comparacaoContaPiscaLed = 8;
		}

		if(contaPiscaLed >= comparacaoContaPiscaLed) {
			contaPiscaLed = 0;
			toggle(LED_CPU_GPIO_Port, LED_CPU_Pin);
		}
	}

	conta500ms ++;
	if(conta500ms >= 5) {
		conta500ms = 0;
		flagAtualizaMotor = true;
	}
}
/*==============================================================================
TAREFAS 1s
==============================================================================*/
void tarefas1s() {
	if(!flagMotorLigado) {
		toggle(LED_CPU_GPIO_Port, LED_CPU_Pin);
	}

}
/*==============================================================================
SCHEDULER
==============================================================================*/
void schedulerEngine() {
	static uint8_t conta100us = 0, conta1ms = 0, conta10ms = 0, conta100ms = 0;
	//Essa rotina deve ser chamada através de um timer configurado em 100us

	tarefas100us();
	conta100us ++;

	if(conta100us >= 10) {
		conta100us = 0;
		tarefas1ms();
		conta1ms ++;

		if(conta1ms >= 10) {
			conta1ms = 0;
			tarefas10ms();
			conta10ms ++;

			if(conta10ms >= 10) {
				conta10ms = 0;
				tarefas100ms();
				conta100ms ++;

				if(conta100ms >= 10) {
					conta100ms = 0;
					tarefas1s();
				}
			}
		}
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
