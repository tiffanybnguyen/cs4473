serial = {100: 113, 200: 428, 400: 1638}
parallel = {
    8:  {100: 19, 200: 62, 400: 223},
    16: {100: 14, 200: 36, 400: 116},
    32: {100: 11, 200: 23, 400: 63},
}

ns = [100, 200, 400]
ps = [8, 16, 32]

print("Speedup")
print("p\\n\t" + "\t".join(str(n) for n in ns))
for p in ps:
    row = []
    for n in ns:
        s = serial[n] / parallel[p][n]
        row.append(f"{s:.4f}")
    print(f"{p}\t" + "\t".join(row))

print("\nEfficiency")
print("p\\n\t" + "\t".join(str(n) for n in ns))
for p in ps:
    row = []
    for n in ns:
        s = serial[n] / parallel[p][n]
        e = s / p
        row.append(f"{e:.4f}")
    print(f"{p}\t" + "\t".join(row))
