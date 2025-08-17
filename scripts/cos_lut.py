import math
import matplotlib.pyplot as plt
import numpy as np

arr = np.zeros(1024)

for i in range(0, 1024):
    val = int((math.cos(2*math.pi*i/1024))*(2**31-1))
    arr[i] = val
    print(f"{val:3}", end=", ")
    if (i + 1) % 4 == 0:
        print()

plt.plot(arr)
plt.show()
