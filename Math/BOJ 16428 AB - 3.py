a, b = map(int, input().split())
if b > 0:
    p = a // b
else:
    b *= -1
    if a % b == 0:
        p = -a // b
    else:
        p = -a // b + 1
    b *= -1
print(p)
print(a - p * b)
