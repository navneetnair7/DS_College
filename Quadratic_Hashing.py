def hash(k, m):
    return k % m

l = list(map(int, input("Enter elements: ").split()))
m = int(input("Enter m: "))
a = [0] * m
c1, c2 = map(int, input("Enter c1 and c2: ").split())


for j in l:
    t = hash(j, m)
    if a[t] == 0 or a[t] == -1:
        a[t] = j
        print(a)
    else:
        i = 1
        while a[(t + c1 * i + c2 * i * i) % m] != 0 and a[(t + c1 * i + c2 * i * i) % m] != -1 and i <= m:
            print("Collision for", j, "at i = ", i)
            i += 1
           
        if i < m:
            a[(t + c1 * i + c2 * i * i) % m] = j
            print(a)
        else:
            print("Overflow for", j)

print(a)

g = int(input("Enter the element you want to delete from the list: "))

h = hash(g, m)
i = 1
if a[h] == g:
    a[h] = -1
    print(a)
else:
    while(a[(t + c1 * i + c2 * i * i) % m] != g and i != m):
        i += 1
    if i != m:
        a[(t + c1 * i + c2 * i * i) % m] = -1
        print(a)
    else:
        print("Not found")
