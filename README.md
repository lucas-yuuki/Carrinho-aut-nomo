# 🚗 Carrinho Autônomo com Arduino

Projeto desenvolvido utilizando **Arduino Uno**, sensores ultrassônicos e ponte H para criar um robô móvel capaz de navegar autonomamente, detectar obstáculos e reconstruir sua trajetória utilizando Python.

---

## 📸 Projeto

### Vista lateral

<p align="center">
  <img width="400" height="300" alt="WhatsApp Image 2026-07-18 at 17 27 16" src="https://github.com/user-attachments/assets/90ef3f09-2bce-49a8-877a-61e0808ef9c6" />
</p>

---

### Componentes principais

<p align="center">
  <img width="512" height="384" alt="1784408373124-b50d0ec7-7383-42c0-bb48-b273141fbab423_1" src="https://github.com/user-attachments/assets/fd993ea7-402e-4131-80a1-8e1ebb6b9907" />
</p>

O robô é composto por:

- Arduino Uno
- 2 Pontes H L298N
- 4 Motores DC
- 3 Sensores Ultrassônicos HC-SR04
- Chassi 4WD
- Alimentação por baterias

---

## 📊 Reconstrução do mapa

Após a execução, o Arduino salva os dados de movimentação. Um programa em Python utiliza essas informações para reconstruir a trajetória do robô e estimar a posição dos obstáculos.

<p align="center">
  <img width="307" height="307" alt="gráfico" src="https://github.com/user-attachments/assets/1b78660e-9007-4351-a935-23cbb2e935a6" />

</p>

O gráfico apresenta:

- 🔵 Obstáculos detectados
- 🔷 Trajetória estimada
- 🟠 Posição inicial
- 🟢 Posição final
- 🔺 Orientação final do robô

---

## 🎥 Demonstração

<p align="center">
  <img width="640" height="360" alt="Video Project 10 (8)" src="https://github.com/user-attachments/assets/60f3f5b1-9757-410f-ae2e-ad647d3572a9" />
</p>

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
