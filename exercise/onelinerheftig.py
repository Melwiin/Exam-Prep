myList = []
for i in range(20):
    if i % 2 == 0:
        myList.append(i**3)

# One line =
myList = [i**3 for i in range(20) if i % 2 == 0]
