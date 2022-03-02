# Algorithm for generating Convolutional Codes

from audioop import reverse


def isEmptyRegister(reg):
    for i in range(reg):
        if (reg[i] != None):
            return False
    return True


g = [
    [1, 1, 1],
    [1, 0, 1]
]

m = [1, 0, 0, 1, 1, 1, 0, 1]
x0 = []
x1 = []
reg = [m[0], 0, 0] 

index = 1
while index < len(m) + len(reg):
    codebit = 0
    for i in range(len(g[0])):
        codebit += g[0][i] * reg[i]
    codebit %= 2
    x0.append(codebit)
    for i in reversed(range(len(reg))):
        reg[i] = reg[i - 1]
    reg[0] = m[index] if index < len(m) else 0
    index = index + 1

reg = [m[0], 0, 0]
index = 1
while index < len(m) + len(reg):
    codebit = 0
    for i in range(len(g[1])):
        codebit += g[1][i] * reg[i]
    codebit %= 2
    x1.append(codebit)
    for i in reversed(range(len(reg))):
        reg[i] = reg[i - 1]
    reg[0] = m[index] if index < len(m) else 0
    index = index + 1
    
x = [str(x0[i]) + str(x1[i]) for i in range(len(x0))]
print(x0)
print(x1)
print(x)

for i in range(2):
    for j in range(2):
        state = str(j) + str(i)
        for k in range(2):
            a = g[0][0] * k + g[0][1] * j + g[0][2] * i
            a %= 2
            b = g[1][0] * k + g[1][1] * j + g[1][2] * i
            b %= 2
            output = str(k) + "/" + str(a) + str(b)
            print(state, " --> ", output, " --> ", str(k) + str(j))