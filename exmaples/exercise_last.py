

# create a class, and one non-static function, and one read only member
# two normal variables, constructor (default and base)
class Tristan:
    skill = 10

    def __init__(self, a = 0, d = "Tremor"):
        self.age = a
        self.disability = d

    @property
    def age(self):
        return self.age
    @age.setter
    def age(self, value):
        self._age = value

    def cool(self):
        print(self.skill)

    @classmethod
    def rank(cls, a, x):
        pass

melwin = Tristan(2, "None")

# main function here oder so
# initialize a object from the class