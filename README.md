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

- Arduino / ESP32
- Botões Push-Button (para marcar pontos)
- Display de 7 segmentos ou LEDs (para exibir pontuação)
- Protoboard e cabos de conexão
- Node.js / Express (para controle remoto ou interface web, opcional)
- Protocolos IoT (MQTT ou HTTP, se houver integração com servidor)

## Video do Placar:
[![Assista ao vídeo](video-simulador.gif)](https://www.youtube.com/watch?v=FpRyiQhOh0U)

## Arquitetura proposta (diagrama e explicação)

 [Botões de Pontuação] ---> [Placa Edge (Arduino/ESP32)] ---> [Display de 7 segmentos/LEDs]
          ↑                                          
          └---------> [Servidor Web/Interface opcional]


# DIAGRAMA

## Explicação:
- Cada botão representa um time. Ao ser pressionado, a placa Edge atualiza a pontuação correspondente.
- O display ou LEDs mostram a pontuação em tempo real.
- Opcionalmente, o dispositivo pode enviar dados a um servidor web para registro ou visualização remota.

## Recursos Necessários

- Placa Arduino ou ESP32
- Botões Push-Button (mínimo 2, um para cada time)
- Display de 7 segmentos ou LEDs
- Protoboard, resistores e cabos
- Fonte de energia ou USB

## Instruções de Uso

1. Clone o repositório:

```git clone https://github.com/SeuUsuario/PlacarEletronico-EDGE.git```

2. Configure os botões e displays na placa Edge conforme o circuito.

3. Faça upload do código para o Arduino/ESP32 usando o Arduino IDE.

4. Pressione os botões durante o jogo e observe a pontuação atualizada no display.

5. (Proximos passos) Inicie a interface web para monitorar remotamente:
