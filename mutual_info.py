# Algorithm for calculating Mutual Informaion I(x;y) and related quantities

import math

p = [
    [1/16, 3/8, 1/16, 1/2],
    [1/16, 3/16, 0, 1/4],
    [0, 3/16, 1/16, 1/4],
    [1/8, 3/4, 1/8, 1]
]

r = 3 # Number of columns (Number of xs)
s = 3 # Number of rows (Number of ys)

# H(x)
Hx = 0
for i in range(r):
    Hx += p[s][i] * math.log2(p[s][i])
Hx *= -1

# H(y)
Hy = 0
for j in range(s):
    Hy += p[j][r] * math.log2(p[j][r])
Hy *= -1

# H(x|y)
Hxy = 0
for i in range(r):
    for j in range(s):
        if p[j][i] == 0:
            continue
        Hxy += p[j][i] * math.log2(p[j][r]/(p[j][i]))

# H(y|x)
Hyx = 0
for i in range(r):
    for j in range(s):
        if p[j][i] == 0:
            continue
        Hyx += p[j][i] * math.log2(p[s][i]/(p[j][i]))

# I(x;y) and I(y;x)
Ixy = Hx - Hxy
Iyx = Hy - Hyx

print("H(x)   = " + str(Hx))
print("H(y)   = " + str(Hy))
print("H(x|y) = " + str(Hxy))
print("H(y|x) = " + str(Hyx))
print("I(x;y) = " + str(Ixy))
print("I(y;x) = " + str(Iyx))