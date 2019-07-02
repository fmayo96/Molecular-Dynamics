import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("test_Energia.txt")

Ecin = data[:,0]
Epot = data[:,1]

Etot = np.zeros(len(Ecin))
T = np.zeros(len(Ecin))
for i in range(0,len(Ecin)):
	Etot[i] = Ecin[i] + Epot[i] 
	T[i] = Ecin[i] * 2/3	
plt.figure()
plt.subplot(221)
plt.plot(Etot,'r.')
plt.grid()
plt.ylabel("Etot")
plt.subplot(222)
plt.plot(T,'y.')
plt.grid()
plt.ylabel("Temperatura")
plt.subplot(223)
plt.plot(Ecin,'b.')
plt.grid()
plt.ylabel("Ecin")
plt.subplot(224)
plt.plot(Epot,'m.')
plt.ylabel("Epot")
plt.grid()
plt.show()
