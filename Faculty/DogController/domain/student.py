class Dog:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def get_name(self):
        return self.__name

    def get_age(self):
        return self.__age

    def set_age(self, age):
        self.__age = age

    def set_name(self, name):
        self.__name = name

    def __str__(self):
        return "\t - " + str(self.get_name()) + " (" + str(self.get_age()) + ") "
