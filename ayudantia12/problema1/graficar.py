import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors

# Cargar los datos desde el archivo .txt
data = np.loadtxt('resultados.txt')
x = data[:, 0]
y = data[:, 1]
t = data[:, 2]
temperature = data[:, 3]

# Crear una cuadrícula 2D
X, Y = np.meshgrid(np.unique(x), np.unique(y))

# Reorganizar los datos en una matriz 2D para la gráfica
temperature_grid = temperature.reshape((len(np.unique(t)), len(np.unique(y)), len(np.unique(x))))

# Obtener el número de pasos de tiempo
num_timesteps = temperature_grid.shape[0]

# Definir los límites mínimos y máximos de temperatura para la leyenda
min_temp = np.min(temperature)
max_temp = np.max(temperature)

# Crear una leyenda de colores
norm = mcolors.Normalize(vmin=min_temp, vmax=max_temp)
cmap = plt.cm.hot
mappable = plt.cm.ScalarMappable(norm=norm, cmap=cmap)
mappable.set_array([])
fig, ax = plt.subplots()
ax.imshow(temperature_grid[0], extent=[np.min(x), np.max(x), np.min(y), np.max(y)], cmap=cmap, origin='lower')
ax.set_xlabel('x')
ax.set_ylabel('y')
# ax.set_title('Difusión de temperatura en el tiempo')
# ax.text(np.min(x), np.max(y), f'Tiempo: {t[0]}', color='white', fontsize=10, ha='left', va='top', backgroundcolor='black')

# Añadir la barra de color manualmente
cax = fig.add_axes([0.85, 0.15, 0.05, 0.7])  # Posición de la barra de color
colorbar = plt.colorbar(mappable, cax=cax)
# colorbar.set_label('Temperatura')

# Actualizar la figura para cada paso de tiempo
# for i in range(1, num_timesteps):
#     ax.imshow(temperature_grid[i], extent=[np.min(x), np.max(x), np.min(y), np.max(y)], cmap=cmap, origin='lower')
#     ax.set_title('Difusión de temperatura en el tiempo')
#     ax.text(np.min(x), np.max(y), f'Tiempo: {t[i]}', color='white', fontsize=10, ha='left', va='top', backgroundcolor='black')
#     # plt.pause(0.01)  # Pausa para mostrar cada paso de tiempo

i = num_timesteps-2
ax.imshow(temperature_grid[i], extent=[np.min(x), np.max(x), np.min(y), np.max(y)], cmap=cmap, origin='lower')
# ax.set_title('Difusión de temperatura en el tiempo')
# ax.text(np.min(x), np.max(y), f'Tiempo: {t[i]}', color='white', fontsize=10, ha='left', va='top', backgroundcolor='black')

plt.show()