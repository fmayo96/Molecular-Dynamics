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

print("T final = ", T[len(Ecin)-1])

plt.figure()
plt.subplot(221)
plt.plot(Etot[1:len(Ecin)],'r.')
plt.grid()
plt.ylabel("Etot")
plt.subplot(222)
plt.plot(T[1:len(Ecin)],'y.')
plt.grid()
plt.ylabel("Temperatura")
plt.subplot(223)
plt.plot(Ecin[1:len(Ecin)],'b.')
plt.grid()
plt.ylabel("Ecin")
plt.subplot(224)
plt.plot(Epot[1:len(Ecin)],'m.')
plt.ylabel("Epot")
plt.grid()
plt.show()
