n = int(input("Enter the number of cities: "))
l = {}
for i in range(n):
    temp = []
    city = input("Enter city name: ")
    c = int(input("How many cities is {} connected to? ".format(city)))
    for j in range(c):
        temp.append(input("Enter city: "))
    l[city] = temp

for i in l:
    print(i, "-> ", end = '')
    for j in l[i]:
        print(j, "-> ", end = '')
    print("/")
    print()
# print(l)

start = input("Enter starting point for BFS: ")
q = []
q.append(start)

visited = {}
distance = {}
distance[start] = 0
parent = {}
parent[start] = None

print(q)
while len(q) != 0:
    p = q[0]
    d = distance[p]
    if p not in visited:
        visited[p] = "✓"
        for j in l[p]:
            if j not in visited:
                q.append(j)
                distance[j] = d + 1
                parent[j] = p
    q.pop(0)
    print("queue- ", q)
print("Visited: ", end = '')
print(visited)
print("Distance: ", end = '')
print(distance)
print("Parent: ", end = '')
print(parent)