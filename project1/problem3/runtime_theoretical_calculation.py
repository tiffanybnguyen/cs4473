import math

# calculate serial time
def T_serial(n: int) -> float:
    return n**2 + 2*n

# calculate parallel time
def T_parallel(n: int, p: int) -> float:
    return (n**2)/p + 2*n + 100*math.log2(p)

# calculate speedup
def speedup(n: int, p: int) -> float:
    return T_serial(n) / T_parallel(n, p)

# calculate efficiency
def efficiency(n: int, p: int) -> float:
    return speedup(n, p) / p

ns = [100, 200, 400]
ps = [8, 16, 32]

# ---- Speedup table ----
print("Speedup")
print("p\\n\t" + "\t".join(f"{n}" for n in ns))
for p in ps:
    row = [f"{speedup(n, p):.4f}" for n in ns]
    print(f"{p}\t" + "\t".join(row))

print()

# ---- Efficiency table ----
print("Efficiency")
print("p\\n\t" + "\t".join(f"{n}" for n in ns))
for p in ps:
    row = [f"{efficiency(n, p):.4f}" for n in ns]
    print(f"{p}\t" + "\t".join(row))
