# Can you write the constructor for the following Python object ? It should print in the console
# the memory address of the newly created object.

class Lurker:
# Implement the constructor below ...
    def __init__ (self, v, a):
        self.v = v
        self.a = a
        print(hex(id(self)))

# Some method
    def add(self, v, a):
        self.v += v
        self.a += a

a = Lurker(2, 2)