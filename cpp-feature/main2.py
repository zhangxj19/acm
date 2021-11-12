import numpy as np
from matplotlib import pyplot
from mpl_toolkits.mplot3d import Axes3D

class Soluton:
    def sample_sphere_uniform(self, num_points):
        vec = np.zeros((3, num_points))
        R = 1
        for k  in range(num_points):
            # write code here
            alpha = np.random.uniform(0, 2 * np.pi)
            tho = np.random.uniform(0, np.pi)
            r = np.sin(tho)
            rd = np.random.uniform(0, 1)
            if rd < r:
              x = np.sin(tho) * np.cos(alpha)
              y = np.sin(tho) * np.sin(alpha)
              z = np.cos(tho)
              vec[:, k] = [x, y, z]
        return vec

fig = pyplot.figure()
ax = Axes3D(fig)
instance = Soluton()
xi, yi, zi = instance.sample_sphere_uniform(10000)
ax.scatter(xi, yi, zi, s=1, c='r')
pyplot.show()