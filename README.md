# 🚗 Carrinho Autônomo com Arduino

Projeto desenvolvido utilizando **Arduino Uno**, sensores ultrassônicos e ponte H para criar um robô móvel capaz de navegar autonomamente, detectar obstáculos e reconstruir sua trajetória utilizando Python.

---

## 📸 Projeto

### Vista lateral

<p align="center">
  <img src="imagens/carrinho_lateral.jpg" width="700">
</p>

---

### Componentes principais

<p align="center">
  <img src="imagens/componentes.jpg" width="700">
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
  <img width="614" height="615" alt="gráfico" src="https://github.com/user-attachments/assets/1b78660e-9007-4351-a935-23cbb2e935a6" />

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
  <img width="1280" height="720" alt="Video Project 10 (8)" src="https://github.com/user-attachments/assets/60f3f5b1-9757-410f-ae2e-ad647d3572a9" />
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
