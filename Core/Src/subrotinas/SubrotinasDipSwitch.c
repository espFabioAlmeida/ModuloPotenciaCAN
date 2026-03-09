///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasDipSwitch.c
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
LEITURA DIP SWITCH
==============================================================================*/
void leituraDipSwitch() {
	enderecoModulo = ENDERECO_MODULO_PADRAO;

	if(!input(SW1_GPIO_Port, SW1_Pin)) {
		enderecoModulo ++;
	}

	if(!input(SW2_GPIO_Port, SW2_Pin)) {
		enderecoModulo += 2;
	}

	if(!input(SW3_GPIO_Port, SW3_Pin)) {
		enderecoModulo += 4;
	}

	switch(enderecoModulo) {
		case 90: contadorEnviaCAN = 0; break;
		case 91: contadorEnviaCAN = 2; break;
		case 92: contadorEnviaCAN = 4; break;
		case 93: contadorEnviaCAN = 6; break;
		case 94: contadorEnviaCAN = 10; break;
		case 95: contadorEnviaCAN = 12; break;
		case 96: contadorEnviaCAN = 14; break;
		case 97: contadorEnviaCAN = 16; break;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
