import numpy as np
import matplotlib.pyplot as plt

# Load data
data = np.loadtxt("output.dat")

# Columns
E  = data[:,0]
P2 = data[:,1]
V2 = data[:,2]
E2 = data[:,3]
Pmumu=data[:,4]
Pmue=data[:,5]
Pmutau=data[:,6]
X=P2+V2+E2
# Create plot
plt.figure(figsize=(8,6))

plt.plot(E, P2, label=r"$P^2$", linewidth=2)
plt.plot(E, V2, label=r"$V^2$", linewidth=2)
plt.plot(E, E2, label=r"$E^2$", linewidth=2)
plt.plot(E, X, label=r"$P^2 + V^2 +E^2$", linewidth=2)
# Labels
plt.xlabel("Energy E (GeV)", fontsize=14)
plt.ylabel("$P^2, V^2 ,E^2$", fontsize=14)

# Title
plt.title("T2K Triality Quantities vs Energy", fontsize=16)

# Grid
plt.grid(True)

# Legend
plt.legend(fontsize=12)

# Save figure
plt.savefig("triality_plot.png", dpi=300)

# Show plot
plt.show()

plt.figure(figsize=(8,6))
plt.plot(E, Pmumu, label=r"$Pmumu$", linestyle='dashed')
plt.plot(E, Pmue, label=r"$Pmue$", linestyle='dashed')
plt.plot(E, Pmutau, label=r"$Pmutau$", linestyle='dashed')
plt.fill_between(E, Pmutau, color="lightcoral", alpha=0.4)
plt.ylabel("Pmumu, Pmue, Pmutau", fontsize=14)
plt.xlabel("Triality Quantities", fontsize=14)

# Title
plt.title("T2K Triality Quantities vs Energy", fontsize=16)

# Grid
plt.grid(True)

# Legend
plt.legend(fontsize=12)

# Save figure
plt.savefig("triality_plot_prob.png", dpi=300)
plt.show()