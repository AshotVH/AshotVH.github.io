import plotly.graph_objects as go
# import plotly.express as px
from plotly.subplots import make_subplots
import numpy as np
import time
t1 = time.perf_counter()
showAngle = "18"
fig = go.Figure()
infile = open("../adiabatic/delta_05pi_p_01.txt", "r")
coordinates = infile.read().splitlines()
energies = []
prob = []
for coordinate in coordinates:
    res = coordinate.split(',')
    angle = res[0]
    if angle == showAngle:
        energies.append(int(res[1]))
        prob.append(float(res[2]))
infile.close()
fig.add_trace(go.Scatter(x=energies, y=prob,
                    mode='lines+markers',
                    name='normal'))
infile = open("../any_layers/std_files/delta_05pi_p_01.txt", "r")
coordinates = infile.read().splitlines()
energies = []
prob = []
for coordinate in coordinates:
    res = coordinate.split(',')
    angle = res[0]
    if angle == showAngle:
        energies.append(int(res[1]))
        prob.append(float(res[2]))
infile.close()
fig.add_trace(go.Scatter(x=energies, y=prob,
                    mode='lines',
                    name='adiabatic'))
fig.show()

# infile = open("delta_05pi_P12", "r")
# coordinates = infile.read().splitlines()
# last_elm = (coordinates[len(coordinates) - 1]).split()
# xx = int(last_elm[0]) + 1
# yy = int(last_elm[1]) + 1
# points12 = np.zeros((xx, yy))
# for coordinate in coordinates:
#     res = coordinate.split()
#     x = int(res[0])
#     y = int(res[1])
#     z = float(res[2])
#     points12[x, y] = z
# infile.close()

# infile = open("delta_05pi_P21", "r")
# coordinates = infile.read().splitlines()
# last_elm = (coordinates[len(coordinates) - 1]).split()
# xx = int(last_elm[0]) + 1
# yy = int(last_elm[1]) + 1
# points21 = np.zeros((xx, yy))
# for coordinate in coordinates:
#     res = coordinate.split()
#     x = int(res[0])
#     y = int(res[1])
#     z = float(res[2])
#     points21[x, y] = z
# infile.close()

# fig = make_subplots(rows=1, cols=3,
#                     specs=[[{'is_3d': True}, {'is_3d': True}, {'is_3d': True}]],
#                     subplot_titles=['Electron - Electron', 'Electron - Muon', 'Muon - Muon'],
#                     )
# fig.add_trace(go.Surface(z=points11), row=1, col=1)
# fig.add_trace(go.Surface(z=points12), row=1, col=2)
# fig.add_trace(go.Surface(z=points21), row=1, col=3)
# fig.update_layout(title_text="Neutrino oscillation probabilities")
# fig.show()
t2 = time.perf_counter()
print(t2 - t1)
