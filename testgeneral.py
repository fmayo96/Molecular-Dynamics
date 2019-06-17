import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("testgeneral.txt")

xrand = data[:,0]
xgauss = data[:,1]

plt.figure(1)
plt.hist(xgauss,bins=100)
plt.show()
plt.figure(2)
plt.hist(xrand,bins=100)
plt.show()

