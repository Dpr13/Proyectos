# Programa para generar imagenes termicas a partir de la matriz de 64 pixeles

import matplotlib.pyplot as plt
import numpy as np

matriz_raw = np.genfromtxt("matriz_prueba.txt", dtype=float, delimiter=",")
matriz_proc = np.delete(matriz_raw, 8, 1)
print(matriz_proc)

plt.imshow(matriz_proc, cmap='inferno')
plt.colorbar()
plt.show()
