# Modulo Potêcia CAN
Porjeto Automasensor: Módulo Potência CAN <br>

# Escopo
Possui as mesmas funções do módulo de potência, porém a comunicação é via CAN. <br>
Recebe o valor do setpoint PWM via CAN e aciona a saída da PWM, valor entre 0 e 4095. <br>
O endereço é selecionado pelas 3 entradas no conector. SW1 -> SW3. A SW4 (resistor/jumper) não é utilizado por enquanto. <br>

# Pinagem Conector
1-OUT MOTOR <br>
2-VCC <br>
3-CAN H <br>
4-CAN L <br>
5-FIM DE LINHA (FECHAR COM O 14) <br>
6-+5V <br>
7-IN 1 <br>
8-GND <br>
9-OUT MOTOR <br>
10-VCC <br>
11-ADD +1 <br>
12-ADD +2 <br>
13-ADD +4 <br>
14-FIM DE LINHA (FECHAR COM O 5) <br>
15-NC <br>
16-GND <br>
17-OUT MOTOR <br>
18-VCC <br>
19-NC <br>
20-NC <br>
21-NC <br>
22-NC <br>
23-NC <br>
24-GND <br>

# Protocolo CAN
Endereço CPU: <br>
Endereço ECU Pacote 1: 0x1BB81A01 <br>
Endereço ECU Pacote 2: 0x1BB81A02 <br>
Endereço ECU Pacote 3: 0x1BB81A03 <br>
Pacote 1: <br>
BYTE 0: LSB PWM MODULO POTÊNCIA 90 <br>
BYTE 1: MSB PWM MODULO POTÊNCIA 90 <br>
BYTE 2: LSB PWM MODULO POTÊNCIA 91 <br>
BYTE 3: MSB PWM MODULO POTÊNCIA 91 <br>
BYTE 4: LSB PWM MODULO POTÊNCIA 92 <br>
BYTE 5: MSB PWM MODULO POTÊNCIA 92 <br>
BYTE 6: LSB PWM MODULO POTÊNCIA 93 <br>
BYTE 7: MSB PWM MODULO POTÊNCIA 93 <br>
<br>
Pacote 2: <br>
BYTE 0: LSB PWM MODULO POTÊNCIA 94 <br>
BYTE 1: MSB PWM MODULO POTÊNCIA 94 <br>
BYTE 2: LSB PWM MODULO POTÊNCIA 95 <br>
BYTE 3: MSB PWM MODULO POTÊNCIA 95 <br>
BYTE 4: LSB PWM MODULO POTÊNCIA 96 <br>
BYTE 5: MSB PWM MODULO POTÊNCIA 96 <br>
BYTE 6: LSB PWM MODULO POTÊNCIA 97 <br>
BYTE 7: MSB PWM MODULO POTÊNCIA 97 <br>
<br>
Pacote 3: Não é relevante para esse equipamento <br>
Endereço Resposta: 0x132A7890 => Os últimos 2 dígitos refere-se ao endereço. Podendo ser do 90 ao 97. <br>
<br>
BYTE 0: Motor Ligado 0 ou 1 <br>
BYTE 1: Low Byte valor PWM <br>
BYTE 2: High Byte valor PWM <br>
BYTE 3: Livre <br>
BYTE 4: Livre <br>
BYTE 5: Livre <br>
BYTE 6: Livre <br>
BYTE 7: Livre <br>
