# Algorithm for LZW Coding

pixels = [39, 39, 126, 126, 39, 39, 126, 126, 126, 126, 39, 39, 126, 126, 39, 39]
crs = "" # Current Recognised Sequence
tsq = "" # Total Sequence = crs + pixel
pd = {}  # Pixel Dictionary
eo = []  # Encoded Output

for i in range(256):
    pd[i] = str(i)

index = 256
dstring = ["Sequence", "Pixel", "Output", "Location", "Entry"]

print('{:^15}  {:^15}  {:^15} {:^15} {:^15}'.format(dstring[0], dstring[1], dstring[2], dstring[3], dstring[4]))

for pixel in pixels:
    dstring[0] = "--" if crs == "" else crs
    dstring[1] = str(pixel)
    tsq = str(pixel) if crs == "" else str(crs) + "-" + str(pixel)
    hasSeen = False
    for key in pd:
        if pd[key] == tsq:
            dstring[2] = "--"
            dstring[3] = "--"
            dstring[4] = "--"
            hasSeen = True
            crs = tsq
            break
    if not hasSeen:
        for key in pd:
            if pd[key] == crs:
                dstring[2] = str(key)
                dstring[3] = str(index)
                dstring[4] = tsq
                eo.append(key)
                crs = str(pixel)
                pd[index] = tsq
                index = index + 1
                break
    print('{:>15}  {:>15}  {:>15} {:>15} {:>15}'.format(dstring[0], dstring[1], dstring[2], dstring[3], dstring[4]))

for key in pd:
    if pd[key] == crs:
        eo.append(key)

print("\n")
for i in range(len(eo)):
    print(str(eo[i]), end=("-" if i < len(eo) - 1 else "\n"))
