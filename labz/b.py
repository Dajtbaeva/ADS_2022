y, ok = int(input()), False
if (y % 4 == 0) and (y % 100 == 0) or (y % 400 == 0):
    ok = True
print(ok)