# 🚗 Carrinho Autônomo com Arduino

Projeto desenvolvido utilizando **Arduino Uno**, sensores ultrassônicos e ponte H para criar um robô móvel capaz de navegar autonomamente, detectar obstáculos e reconstruir sua trajetória utilizando Python.

---

## 📸 Projeto

### Vista lateral

<p align="center">
  <img width="700" alt="WhatsApp Image 2026-07-18 at 17 27 16" src="https://github.com/user-attachments/assets/90ef3f09-2bce-49a8-877a-61e0808ef9c6" />
</p>

---

### Componentes principais

<p align="center">
  <img width="700" alt="1784408373124-b50d0ec7-7383-42c0-bb48-b273141fbab423_1" src="https://github.com/user-attachments/assets/fd993ea7-402e-4131-80a1-8e1ebb6b9907" />
</p>

O robô é composto por:

- Arduino Uno
- 2 Pontes H L298N
- 4 Motores DC
- 3 Sensores Ultrassônicos HC-SR04
- Chassi 4WD
- Alimentação por baterias

---

## 📊 Reconstrução da trajetória

A imagem à esquerda apresenta o mapa reconstruído a partir dos dados coletados durante a navegação. À direita, está a execução correspondente do robô, permitindo comparar o percurso real com a estimativa produzida pelo algoritmo.

<table align="center">
<tr>

<td align="center" width="50%">

<img width="100%" alt="gráfico" src="https://github.com/user-attachments/assets/1b78660e-9007-4351-a935-23cbb2e935a6" />

<b>🗺️ Mapa reconstruído</b>

</td>

<td align="center" width="50%">

<img width="100%" alt="Video Project 10 (8)" src="https://github.com/user-attachments/assets/60f3f5b1-9757-410f-ae2e-ad647d3572a9" />

<b>🎥 Execução do robô</b>

</td>

</tr>
</table>

O gráfico apresenta:

- 🔵 Obstáculos detectados
- 🔷 Trajetória estimada
- 🟠 Posição inicial
- 🟢 Posição final
- 🔺 Orientação final do robô

---

## ✨ Funcionalidades

- Navegação autônoma
- Desvio inteligente de obstáculos
- Controle de velocidade conforme a distância
- Odometria baseada em tempo
- Reconstrução da trajetória em Python
- Estimativa da posição dos obstáculos
- Registro de dados para análise

---

## 🛠 Tecnologias

- Arduino (C++)
- Python
- Matplotlib

---

## 🔧 Hardware

- Arduino Uno
- 3 Sensores HC-SR04
- 2 Pontes H L298N
- 4 Motores DC
- Chassi 4WD
- Protoboard
- Baterias

---

## 🚀 Melhorias futuras

- Encoder nas rodas
- IMU (MPU6050)
- SLAM
- Controle PID
- Comunicação Bluetooth/Wi-Fi
- Planejamento de trajetória

---

## 👨‍💻 Autor

**Lucas Yuuki Sasaki Ramos**

Engenharia de Controle e Automação — UFRGS

GitHub: https://github.com/lucas-yuuki
