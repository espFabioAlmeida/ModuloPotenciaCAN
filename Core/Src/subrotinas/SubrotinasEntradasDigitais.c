///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasEntradasDigitais.c
//AUTOR:      Fábio Almeida
//CRIADO:     13/03/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
# include "main.h"
# include "global.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
/*==============================================================================
LEITURA ENTRADA PULSOS
==============================================================================*/
void leituraEntradaPulsos() {
	//Essa função deve ser chamada a cada 1ms
	static uint8_t flagWhileEntrada = false;
	static uint16_t contadorTempo = 0, contadorFrequenciaEntrada = 0;

	contadorTempo ++;
	if(contadorTempo >= 1000) { //1s
		contadorTempo = 0;
		frequenciaEntrada = contadorFrequenciaEntrada;
		contadorFrequenciaEntrada = 0;
	}

	if(input(IN1_GPIO_Port, IN1_Pin)) {
		flagWhileEntrada = false;
		off(LED_IN1_GPIO_Port, LED_IN1_Pin);
		return;
	}

	on(LED_IN1_GPIO_Port, LED_IN1_Pin);

	if(flagWhileEntrada) {
		return;
	}

	flagWhileEntrada = true;

	contadorFrequenciaEntrada ++;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
