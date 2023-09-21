import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('solucion.txt')
x = data[:, 0]
y = data[:, 1]

plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.show()