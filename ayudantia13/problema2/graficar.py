import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Cargar los datos desde el archivo de texto
data = np.loadtxt("resultados.txt")

# Extraer las coordenadas x, y, z y la temperatura de los datos
x = data[:, 0]
y = data[:, 1]
z = data[:, 2]
temperatura = data[:, 3]

# Crear una figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Graficar los puntos en el espacio 3D con colores según la temperatura
# aqui le digo que el color y el tamaño dependen de la temperatura
sc = ax.scatter(x, y, z, c=temperatura, cmap='jet', s = temperatura)

# Agregar una barra de color
cbar = plt.colorbar(sc)

# Mostrar la visualización
plt.show()

# Mostrar la visualización
plt.show()