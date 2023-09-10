class Lurker:
    # Base constructor
    def __init__(self, v = 0, a = 0) -> None:
        self.v = v
        self.a = a
        print(hex(id(self)))

    # Some method
    def add(self, v, a):
        self.v += v
        self.a += a

a = Lurker(2, 2) # Base
b = Lurker() # Default