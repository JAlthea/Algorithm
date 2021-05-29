n = int(input())
a = 1
b = 1
for i in range(2, n):
    c = a
    a = a + b
    b = c

print(a)
