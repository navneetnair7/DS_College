def heapify(A, i, n):
    l = 2 * i
    r = 2 * i + 1
    if l < n and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r < n and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        heapify(A, largest, n)

def build(A):
    n = len(A)
    for i in range(n // 2, -1, -1):
        heapify(A, i, n)
        print(A)

def heapSort(A, n):
    build(A)
    for j in range(n):
        A[0], A[n - j - 1] = A[n - j - 1], A[0]
        heapify(A, 0, n - j - 1)
        print(A)
    # A[0], A[1] = A[1], A[0]

def incKey(A, i, key):
    if key < A[i]:
        print("The new key is smaller than original key")
    else:
        A[i] = key
        while i >= 0 and A[i // 2] < A[i]:
            A[i], A[i // 2] = A[i // 2], A[i]
            i = i // 2
    # build(A)


t = int(input("Enter the number of elements in the heap: "))
A = list(map(int, input("Enter the elements: ").split()))
build(A)
print("The MAX heap is: ", A)
heapSort(A, t)
print("Sorted Heap: ", A)
build(A)
j, v = map(int, input("Enter the new key and the index: ").split())
incKey(A, v, j)
print("Heap after increment: ", A)