import matplotlib.pyplot as plt;
import numpy as np

def read_data(filename):
    result = {}

    f = open(filename, "r")

    s = f.readline()
    cycle_meas_n = int(s)
    cycle_avg = 0
    for i in range(cycle_meas_n):
        s = f.readline()
        cycle_avg += int(s)
    cycle_avg /= cycle_meas_n
    result["cycle_avg"] = cycle_avg

    s = f.readline()
    fft_n = int(s)
    fft = np.zeros(fft_n//2)
    for i in range(fft_n//2):
        s = f.readline()
        fft[i] = np.sqrt(int(s))
    result["fft"] = fft

    f.close()

    return result

results = {}
results["hazard3"] = {}
results["m33"] = {}

results["h3_gcc"] = read_data("data/gcc_hazard3.txt")
results["h3_clang"] = read_data("data/clang_hazard3.txt")
results["m33_gcc"] = read_data("data/gcc_m33.txt")
results["m33_clang"] = read_data("data/clang_m33.txt")

plt.figure()

plt.plot(results["h3_gcc"]["fft"], label=f"Hazard3 (GCC), {results['h3_gcc']['cycle_avg']} cycles")
plt.plot(results["m33_gcc"]["fft"], label=f"Cortex-M33 (GCC), {results['m33_gcc']['cycle_avg']} cycles")
plt.plot(results["h3_clang"]["fft"], label=f"Hazard3 (Clang), {results['h3_clang']['cycle_avg']} cycles")
plt.plot(results["m33_clang"]["fft"], label=f"Cortex-M33 (Clang), {results['m33_clang']['cycle_avg']} cycles")
plt.grid()
plt.legend()
plt.tight_layout()



plt.figure()
cycle_meas = [
    results["h3_clang"]["cycle_avg"],
    results["m33_clang"]["cycle_avg"],
    results["h3_gcc"]["cycle_avg"],
    results["m33_gcc"]["cycle_avg"],
]
labels = [
    "Hazard3 (Clang)",
    "ARM Cortex-M33 (Clang)",
    "Hazard3 (GCC)",
    "ARM Cortex-M33 (GCC)",
]
plt.bar([0, 1, 2, 3], cycle_meas, color=["red", "blue", "green", "orange"])
plt.xticks([0, 1, 2, 3], labels, fontsize=8)
plt.ylabel("CPU cycles")
plt.title("Pico 2 FFT CPU cycle measurements")
plt.tight_layout()

plt.savefig("figures/fft_cycles.svg", format="svg")

plt.show()
