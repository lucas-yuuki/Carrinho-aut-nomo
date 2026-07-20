import math
import matplotlib.pyplot as plt

ARQUIVO = r"C:\Users\lucas\OneDrive\Área de Trabalho\mapa.txt"

# Velocidade máxima estimada (cm/s)
VMAX = 56.3

# Posição inicial
x = 0.0
y = 0.0
angulo = 0

# Dados do mapa
traj_x = [0.0]
traj_y = [0.0]

obs_x = []
obs_y = []


def mover(dist):
    global x, y

    if angulo == 0:
        y += dist

    elif angulo == 90:
        x += dist

    elif angulo == 180:
        y -= dist

    elif angulo == 270:
        x -= dist

    traj_x.append(x)
    traj_y.append(y)


def ponto_sensor(dist, off):
    """
    Calcula a posição do obstáculo considerando qualquer ângulo.
    """

    a = math.radians((angulo + off) % 360)

    ox = x + dist * math.sin(a)
    oy = y + dist * math.cos(a)

    return ox, oy



with open(ARQUIVO, encoding="utf8", errors="ignore") as f:

    for linha in f:

        linha = linha.strip()

        if not linha or linha in ("INICIO", "FIM"):
            continue


        try:

            dados = linha.split(",")

            if len(dados) != 6:
                continue


            t, pwm, tempo, esq, meio, dir = map(float, dados)

            t = int(t)


        except:
            continue



        # Movimento para frente
        if t == 0:

            distancia = VMAX * (pwm / 255) * (tempo / 1000)

            mover(distancia)


        # Giro esquerda
        elif t == 1:

            angulo = (angulo - 90) % 360


        # Giro direita
        elif t == 2:

            angulo = (angulo + 90) % 360



        # Sensores
        sensores = [
            (esq, -20),
            (meio, 0),
            (dir, 20)
        ]


        for distancia, offset in sensores:

            # ignora leituras ruins
            if distancia < 250:

                ox, oy = ponto_sensor(distancia, offset)

                obs_x.append(ox)
                obs_y.append(oy)



# ============================
# MAPA VISUAL
# ============================

plt.figure(figsize=(10,10))


# Obstáculos
plt.scatter(
    obs_x,
    obs_y,
    s=30,
    marker="s",
    label="Obstáculos"
)


# Trajetória
plt.plot(
    traj_x,
    traj_y,
    linewidth=2,
    label="Trajetória"
)


# Início
plt.scatter(
    traj_x[0],
    traj_y[0],
    s=100,
    marker="o",
    label="Início"
)


# Final
plt.scatter(
    traj_x[-1],
    traj_y[-1],
    s=100,
    marker="X",
    label="Fim"
)


# Carrinho
plt.scatter(
    x,
    y,
    s=150,
    marker="^",
    label="Robô"
)


plt.title("Mapa 2D do Robô")
plt.xlabel("X (cm)")
plt.ylabel("Y (cm)")


plt.axis("equal")
plt.grid(True)
plt.legend()

plt.show()