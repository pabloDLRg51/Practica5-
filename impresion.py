import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

archivo = open(
    r"C:\Users\pabli\OneDrive\Desktop\practicaLab5\Laboratorio5\build\Desktop_Qt_6_10_2_MinGW_64_bit-Debug\debug\datos.txt",
    "r",
    encoding="utf-8"
)

lineas = archivo.readlines()

archivo.close()

#guardar datos por tiempo
tiempos = []

#guardar particulas
datosTiempo = []

particulasActuales = {}

for linea in lineas:

    linea = linea.strip()

    if linea == "":
        continue

    #nuevo tiempo
    if "Tiempo" in linea:

        if particulasActuales != {}:
            datosTiempo.append(particulasActuales)

        tiempo = float(linea.split(":")[1])

        tiempos.append(tiempo)

        particulasActuales = {}

        continue

    partes = linea.split(":")

    nombre = partes[0].strip()

    datos = partes[1].split(",")

    x = float(datos[0])
    y = float(datos[1])
    vx = float(datos[2])
    vy = float(datos[3])

    particulasActuales[nombre] = {
        "x": x,
        "y": y,
        "vx": vx,
        "vy": vy
    }

#agregar ultimo tiempo
datosTiempo.append(particulasActuales)

#crear figura
fig, ax = plt.subplots(figsize=(10, 7))

ax.set_xlim(0, 800)
ax.set_ylim(0, 700)

ax.set_xlabel("Posicion X")
ax.set_ylabel("Posicion Y")

ax.set_title("Movimiento de particulas")

ax.grid(True)

#texto del tiempo
textoTiempo = ax.text(
    0.02,
    0.95,
    "",
    transform=ax.transAxes,
    fontsize=14
)

#scatter inicial
scatter = ax.scatter([], [])

def actualizar(frame):

    particulas = datosTiempo[frame]

    x = []
    y = []

    for nombre in particulas:

        x.append(particulas[nombre]["x"])
        y.append(particulas[nombre]["y"])

    scatter.set_offsets(list(zip(x, y)))

    textoTiempo.set_text(f"Tiempo: {tiempos[frame]}")

    return scatter, textoTiempo

animacion = FuncAnimation(
    fig,
    actualizar,
    frames=len(datosTiempo),
    interval=100
)

plt.show()