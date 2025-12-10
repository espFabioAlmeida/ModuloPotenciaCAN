# Modulo Potêcia CAN
Porjeto Automasensor: Módulo Potência CAN <br>

# Escopo
Possui as mesmas funções do módulo de potência, porém a comunicação é via CAN. <br>
Recebe o valor do setpoint PWM via CAN e aciona a saída da PWM, valor entre 0 e 4095. <br>
O endereço é selecionado pelas 3 entradas no conector. SW1 -> SW3. A SW4 (resistor/jumper) não é utilizado por enquanto. <br>

# Protocolo CAN
Endereço CPU: 0x132F7890 => Os últimos 2 dígitos refere-se ao endereço. Podendo ser do 90 ao 97. <br>
<br>
BYTE 0: Motor Ligado 0 ou 1 <br>
BYTE 1: High Byte valor PWM <br>
BYTE 2: Low Byte valor PWM <br>
BYTE 3: Livre <br>
BYTE 4: Livre <br>
BYTE 5: Livre <br>
BYTE 6: Livre <br>
BYTE 7: Livre <br>
