import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("test_Energia.txt")

Ecin = data[:,0]
Epot = data[:,1]

Etot = np.zeros(len(Ecin))
for i in range(0,len(Ecin)):
	 Etot[i] = Ecin[i] + Epot[i] 

plt.figure()
plt.plot(Ecin[0:8000],'.')
plt.plot(Epot[0:8000],'.')
plt.plot(Etot[0:8000],'.')
plt.grid()
plt.legend(["Ecin","Epot","Etot"])
plt.show()
