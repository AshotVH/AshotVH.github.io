import plotly.graph_objects as go
import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator
import math

t1 = time.perf_counter()
file = open("../adiabatic/delta_05pi_p_01.txt", "r")
coordinates1 = file.read().splitlines()
file.close()
file = open("../five_layers_new/delta_05pi_p12.csv", "r")
coordinates2 = file.read().splitlines()
file.close()


points = np.zeros((180, 900))

for i in range(180):
    for j in range(900):
        points[i, j] = float(coordinates1[i * 900 + j].split(',')[2]) - float(coordinates2[i * 900 + j].split(',')[2])
yy = np.linspace(0, 90, 180)
xx = np.linspace(50, 950, 900)
fig1 = go.Figure(data=[go.Surface(x=xx, y=yy, z=points)])
fig1.show()
t2 = time.perf_counter()
print(t2 - t1)

# fig2, ax = plt.subplots(subplot_kw={"projection": "3d"})


# Y = np.linspace(0, 90, 180)
# X = np.linspace(50, 950, 900)
# X, Y = np.meshgrid(X, Y)
# R = np.sqrt(X ** 2 + Y ** 2)
# Z = np.sin(R)

# # Plot the surface.
# surf = ax.plot_surface(X, Y, points11, cmap=cm.plasma,
#                        linewidth=0, antialiased=False)

# # Customize the z axis.
# ax.set_zlim(0, 0.5)
# ax.zaxis.set_major_locator(LinearLocator(10))
# # A StrMethodFormatter is used automatically
# ax.zaxis.set_major_formatter('{x:.02f}')

# # Add a color bar which maps values to colors.
# fig2.colorbar(surf, shrink=0.5, aspect=5)

# plt.show()
