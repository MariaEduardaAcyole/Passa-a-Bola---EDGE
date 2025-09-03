# Passa-a-Bola---EDGE

## Descrição do projeto
O Placar Eletrônico é um sistema Edge IoT para controlar e exibir a pontuação de jogos em tempo real.
Ele utiliza botões físicos para cada time e display de 7 segmentos ou LEDs para mostrar a pontuação imediatamente, funcionando como uma mesa de controle do juiz/árbitro.
O processamento ocorre localmente no dispositivo Edge, garantindo respostas rápidas e confiáveis.

## 👤 Autor | RM | GITHUB
- [Arthur Marcio](https://github.com/TutuMbs) - 563359
- [Gabriela Abdelnor Tavares](https://github.com/GabihAbdTavares) - 562291
- [Maria Eduarda Sousa Acyole de Oliveira](https://github.com/MariaEduardaAcyole) – 566337
- [Mayke Santos](https://github.com/Maykesantos98) - 562680
- [Matheus Goes](https://github.com/Goes1404) - 566407

## ⚙️ Tecnologias e Componentes Utilizados
- **Arduino UNO** (microcontrolador principal)
- **Botões (Push Buttons)** – entrada para incrementar ou resetar o placar
- **Display LCD 16x2 com módulo I2C** – saída para exibir o placar
- **Resistores** (pull-up internos já utilizados no código)
- **Interface Serial (Monitor Serial do Arduino IDE ou Wokwi)** – para simulação de envio de dados tipo API


## Video do Placar:
[![Assista ao vídeo](./Video-simulador.gif)](https://www.youtube.com/watch?v=FpRyiQhOh0U)

## Arquitetura proposta 

### 📝 Explicação

1. **Entrada (Botões):**
   - Três botões são usados para interação:
     - Incrementar pontos do **Time A**
     - Incrementar pontos do **Time B**
     - Resetar os placares  

2. **Processamento (Arduino UNO):**
   - Detecta quando os botões são pressionados.
   - Atualiza as variáveis `pontosA` e `pontosB`.
   - Controla a atualização do display LCD.

3. **Saída (LCD e Serial):**
   - O **LCD via I2C** mostra o placar atualizado em tempo real.
   - O **Monitor Serial** imprime logs simulando o envio de dados para uma API REST.

---

## 📦 Recursos Necessários
- Conta no [Wokwi](https://wokwi.com) ou **Arduino IDE** instalado
- Componentes:
  - Arduino UNO
  - LCD 16x2 com I2C
  - 3 Botões
  - Jumpers e protoboard (se for físico)
- Código do projeto (já incluso no repositório ou acessível pelo link do Wokwi)

---

## ▶️ Instruções de Uso
1. Acesse o projeto no [Wokwi](https://wokwi.com/projects/440753418502759425)  
   ou abra o código no **Arduino IDE**.
2. Conecte os componentes conforme o diagrama (já configurado no Wokwi).
3. Execute a simulação ou faça o upload no Arduino físico.
4. **Interaja com os botões:**
   - 🔘 **Time A** → incrementa pontos do time A.
   - 🔘 **Time B** → incrementa pontos do time B.
   - 🔘 **Reset** → zera os placares.
5. Veja o placar atualizado no **LCD** e os logs de envio no **Monitor Serial**.

---
