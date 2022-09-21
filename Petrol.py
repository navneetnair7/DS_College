p = [4, 6, 7, 4]
l = [4, 6, 7, 4]
d = [6, 5, 3, 5]
s = 0
c = 1
for i in range(4):
    if p[i] < d[i]:
        if s != 0:
            s += i + 1 - s
            p = l
        else:
            s += 1
        c = 1
    elif p[i] >= d[i]:
        if i + 1 == 4:
            i = -1
        p[i + 1] += (p[i] - d[i])
        c += 1
    if c == 4:
        break
print(s)
