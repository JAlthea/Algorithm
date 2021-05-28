n, m = map(int, input().split())

a = 1
for i in range(n):
    a = a * (i + 1)

b = 1
for i in range(m):
    b = b * (i + 1)

c = 1
for i in range(n - m):
    c = c * (i + 1)

print(a // b // c)
