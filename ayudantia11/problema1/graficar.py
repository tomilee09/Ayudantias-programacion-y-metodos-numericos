import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Leer los datos del archivo
data = np.loadtxt('datos.txt')
x = data[:, 0]
t = data[:, 1]
temperature = data[:, 2]

# Obtener las dimensiones de x, t y temperature
nx = len(np.unique(x))
nt = len(np.unique(t))

# Reorganizar los datos en una matriz bidimensional
temperature = temperature.reshape((nt, nx))

# Crear una cuadrícula 2D a partir de los datos
X, T = np.meshgrid(np.unique(x), np.unique(t))

# Graficar la superficie
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, T, temperature, cmap='viridis')
ax.set_xlabel('Posición')
ax.set_ylabel('Tiempo')
ax.set_zlabel('Temperatura')
plt.show()