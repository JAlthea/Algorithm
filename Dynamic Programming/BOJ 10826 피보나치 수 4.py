n = int(input())
a = 0
b = 1

for i in range(2, n + 1):
    t = b
    b = a + b
    a = t

if n == 0:
    print(0)
elif n == 1:
    print(1)
else:
    print(b)
