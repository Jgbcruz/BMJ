# Mini Sumo Auto BMJ (Update: 16/05/2026)
  BMJ é um robô autoral feito pela Equipe de Robótica da UERJ, a UERJBotz, e originado a partir da ideia de confecção de um mini "pós-moderno, agressivo e preciso". Seu design foi feito por Matheus Baima, Marcos Mendonça e João Guilherme Cruz.
  <!-- 

 <div align="center">
  <img src="https://github.com/user-attachments/assets/ad887140-48a0-4c51-8952-10f8e7772970" width="800">
  <br>
  <sub><em><b>Figura 1:</b> Desenho técnico.</em></sub>
</div> 

-->
  
# Sensores 
BMJ tem 3 sensores frontais. 1 centralizado e 2 angulados em 30º em relação ao eixo de simetria do robô. Por se tratar dessa categoria, seu tamanho e sua altura ajudam na montagem e na organização dos demais componentes da eletrônica pois o robô pode ter no máximo 10cm X 10cm. BMJ também possui 2 sensores de linha frontais, fundamentais para evitar a queda do Dohyo.                                                 
- Pinagem no código:                                                                                            
  > Sensor Frontal Esquerdo pino XX
  > 
  > Sensor Frontal pino XX
  > 
  > Sensor Frontal Direito pino XX
  
  
- Detecção de XX cm;
- XX,X mm de comprimento x XX,X mm de largura x XX,X mm de altura;
- PRETO: Sinal (digital, 0 = 0V = sem obstáculo e 5V = 1 = com obstáculo);
- MARROM: Alimentação 5V;
- Azul: GND
<!--

<div align="center">
  <img src="https://github.com/user-attachments/assets/99f5d452-e4a5-4368-93ab-6d7e7bb192d1" width="250" alt="Sensor">
  <br>
  <sub><em><b>Figura 2:</b> Sensor Jsumo.</em></sub>
</div>

-->

# Sensor Receptor IR  
Há ainda um receptor infravermelho para o modo autônomo, para que o robô receba os comandos do juiz.  
<div align="center">
  <img src="https://github.com/user-attachments/assets/2eb800f3-2c23-4c45-bf8f-d138ca266f0e" width="250">
  <br>
  <sub><em><b>Figura 3:</b> Receptor IR VS1838B.</em></sub>
</div>

<!--

# Placa Eletrônica
A placa foi projetada e desenvolvida no site EasyEDA para o controlador ESP32 e duas ponte H DRV8833.
<div align="center">
  <img src="https://github.com/user-attachments/assets/ca5fbf65-0934-4d7f-98d1-76e312d2447a" width="400">
  <br>
  <sub><em><b>Figura 4:</b> Placa eletrônica desenvolvida especificamente para um mini sumo.</em></sub>
</div>  


<div align="center">
  <img src="https://github.com/user-attachments/assets/bcabcb4d-5d36-4fa3-80d5-55d7ac197249" width="400">
  <br>
  <sub><em><b>Figura 5:</b> Placa com pinagem.</em></sub>
</div>

<div align="center">
  <img src="https://github.com/user-attachments/assets/413e08a6-89bb-4d18-8af3-694319948d8f" width="400">
  <br>
  <sub><em><b>Figura 6:</b> Pinagem.</em></sub>
</div>

# ESP32  

Controlador escolhido por ser menor que um arduino comum e oferecer melhor processamento e variedade de funções e canais para PWM.  

<div align="center">
  <img src="https://github.com/user-attachments/assets/99d41dac-efae-4d13-92c0-32b5b8d3c3d4" width="250">
  <br>
  <sub><em><b>Figura 7:</b> ESP32.</em></sub>
</div>  

# DRV8833  
- Ponte H que tem um tamanho reduzido em comparação às demais do mercado e suporta corrente elevada para uma bateria de até 16,8 V.
  > Os pinos dos motores devem ser testados sempre que os atuadores passarem por manutenção. Recomenda-se rodar um programa teste para mover os motores para frente, verificar se realmente estão rodando neste sentido e caso contrário, modificar a pinagem no código.
  Por padrão já definido na placa, os pinos dos motores devem ser exclusivamente 18 e 19 para o motor esquerdo e 4 e 23 para o motor direito.
<div align="center">
  <img src="https://github.com/user-attachments/assets/99019e53-a489-4d2f-bde0-24088f7c3eab" width="400">
  <br>
  <sub><em><b>Figura 8:</b> Ponte H DRV8833.</em></sub>
</div>  

-->
