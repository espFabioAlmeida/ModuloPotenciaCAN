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
#define CONVERSAO_PULSOS_RPM 30 //60 / (QUANTIDADE_PULSOS_REVOLUCAO * TEMPO_JANELA(s)) * 10 (delocado um zero)
//PULSOS POR REVOLUÇÃO = 10
/*==============================================================================
LEITURA ENTRADA PULSOS
==============================================================================*/
void leituraEntradaPulsos() {
	//Essa função deve ser chamada a cada 1ms
	static uint8_t flagWhileEntrada = false;
	static uint16_t contadorTempo = 0, contadorFrequenciaEntrada = 0;

	contadorTempo ++;
	if(contadorTempo >= 2000) { //2s
		contadorTempo = 0;
		rpmMotor = contadorFrequenciaEntrada * CONVERSAO_PULSOS_RPM;
		contadorFrequenciaEntrada = 0;
	}

	if(input(IN1_GPIO_Port, IN1_Pin)) {
		flagWhileEntrada = false;
		off(LED_IN1_GPIO_Port, LED_IN1_Pin); //Versão 2 da pci o led é no 4n25, mantém por compatibilidade
		return;
	}

	on(LED_IN1_GPIO_Port, LED_IN1_Pin); //Versão 2 da pci o led é no 4n25, mantém por compatibilidade

	if(flagWhileEntrada) {
		return;
	}

	flagWhileEntrada = true;

	contadorFrequenciaEntrada ++;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
