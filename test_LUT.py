import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("test_LUT.txt")
r = data[:,0]
F = data[:,1]
V= data[:,2]

plt.figure()
plt.plot(r,V,'.')
plt.plot(r,F,'.')
plt.show()
