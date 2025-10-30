# Passa-a-Bola — EDGE

## Descrição do Projeto

O Placar Eletrônico é um **sistema Edge IoT** para controlar e exibir a pontuação de jogos em tempo real.
Ele utiliza botões físicos para cada time e display de 7 segmentos ou LCD para mostrar a pontuação imediatamente, funcionando como uma mesa de controle do juiz/árbitro.
O processamento ocorre localmente no dispositivo Edge, garantindo respostas rápidas e confiáveis.

Durante as Sprints 3 e 4, o projeto evoluiu para incluir:

* **Simulação de envio de dados via Monitor Serial**, aproximando o funcionamento de uma API REST.
* **Interface mais intuitiva e responsiva** (usando TailwindCSS).
* **Validação de funcionalidades** conforme heurísticas de Nielsen.
* **Documentação e testes unitários** dos endpoints simulados.

## 👤 Autor | RM | GITHUB

* [Arthur Marcio](https://github.com/TutuMbs) - 563359
* [Gabriela Abdelnor Tavares](https://github.com/GabihAbdTavares) - 562291
* [Maria Eduarda Sousa Acyole de Oliveira](https://github.com/MariaEduardaAcyole) – 566337
* [Mayke Santos](https://github.com/Maykesantos98) - 562680
* [Matheus Goes](https://github.com/Goes1404) - 566407

## ⚙️ Tecnologias e Componentes Utilizados

* **ESP32** (controlador principal)
* **Botões (Push Buttons)** – entrada para incrementar ou resetar o placar
* **Display LCD 16x2 com módulo I2C** – saída para exibir o placar
* **Interface Serial** – para simulação de envio de dados (tipo API)
* **Wokwi** – simulação online

## 🎯 Funcionalidades e Melhorias

* Incremento e reset do placar via botões físicos.
* Exibição do placar em tempo real no **LCD**.
* Logs de envio simulados via **Monitor Serial**.
* Interface web com visual acessivel para exibição dos dados.

  * Visibilidade do status do sistema
  * Correspondência entre sistema e mundo real
  * Flexibilidade e eficiência de uso
  * Design estético e minimalista
  * Ajuda e documentação

## Video do Placar

[![Assista ao vídeo](./Video-simulador.gif)](https://www.youtube.com/watch?v=FpRyiQhOh0U)

## Arquitetura proposta

1. **Entrada (Botões)**

   * Time A → incrementa pontos do time A
   * Time B → incrementa pontos do time B
   * Reset → zera os placares

2. **Processamento (ESP32)**

   * Detecta pressionamento dos botões
   * Atualiza variáveis `pontosA` e `pontosB`
   * Controla atualização do display LCD

3. **Saída (LCD e Serial)**

   * LCD via I2C mostra o placar atualizado em tempo real
   * Monitor Serial imprime logs simulando envio de dados para API

## 📦 Recursos Necessários

* Conta no [Wokwi](https://wokwi.com) ou **Arduino IDE** instalado
* Componentes:

  * ESP32
  * LCD 16x2 com I2C
  * 3 Botões
  * Jumpers e protoboard (se for físico)
* Código do projeto (já incluso no repositório ou acessível pelo link do Wokwi)

## ▶️ Instruções de Uso

1. Acesse o projeto no [Wokwi](https://wokwi.com/projects/440753418502759425) ou abra o código no **Arduino IDE**.
2. Conecte os componentes conforme o diagrama (já configurado no Wokwi).
3. Execute a simulação ou faça a construção do projeto físico.
4. Interaja com os botões:

   * 🔘 **Time A** → incrementa pontos do time A
   * 🔘 **Time B** → incrementa pontos do time B
   * 🔘 **Reset** → zera os placares
5. Veja o placar atualizado no **LCD** e os logs de envio no **Monitor Serial**.

## Integração com Broker
1. Baixe o app MyMQTT
2. Faça a conexão com o ip do seu broker
3. Rode a simulação no wokwi

## Dashboard em python
1. Copie e cole o codigo fonte de python na sua IDE de preferencia
2. baixe as bibliotecas presentes no inicio do codigo
3. Rode o codigo
4. Rode a simulação no wokwi
