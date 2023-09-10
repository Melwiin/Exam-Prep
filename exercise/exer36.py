myList = [i**3 for i in range(20) if i % 2 == 0]

for i in range(20):
    if i % 2 == 0:
        myList.append(i**3)

# How do you create myList in only one line using list comprehension ?
