import matplotlib.pyplot as plt
import numpy as np

filepath = 'iteration_data.txt'
with open(filepath) as fp:
   H = [line.split() for line in fp]
   line = fp.readline()
   cnt = 1
   while line:
       #print("Line {}: {}".format(cnt, line.strip()))
       line = fp.readline()
       cnt += 1
#print(lines)
H = np.array(H)
"""
table = []
for r in range(400):
 counter = -2
 row = []
 for c in range(400): 
  row.append(counter)
  counter+=0.01
  #print(counter)
  table.append(row)
"""
H_np = np.array(H)
#print(np.matrix(H))

#print(H_np)
#print((np.shape(H_np)))
#print((np.shape(T_np)))

feature_x = np.linspace(-2.0, 2.0, 400)
print(feature_x)
feature_y = np.linspace(-2.0, 2.0, 400)

# Creating 2-D grid of features
[X, Y] = np.meshgrid(feature_x, feature_y)

fig, ax = plt.subplots(1, 1)

Z = H_np

# plots contour lines
ax.contourf(X, Y, Z)

ax.set_title('Contour Plot')
ax.set_xlabel('feature_x')
ax.set_ylabel('feature_y')

plt.show()

