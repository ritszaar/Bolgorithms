# Algorithm for generating arithmetic codes

probabilities = [0.25, 0.25, 0.25, 0.25]

message = [1, 1, 0]
lower = 0
upper = 1

for i in range(len(message)):
    diff = upper - lower
    for j in range(message[i]):
        lower += diff * probabilities[j]
    upper = lower + diff * probabilities[message[i]]

print(lower, upper)
