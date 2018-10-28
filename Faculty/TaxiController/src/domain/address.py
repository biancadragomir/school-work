class Address:
    def __init__(self, id, name, number, x, y):
        self.__id = id
        self.__name = name
        self.__number = number
        self.__x = x
        self.__y = y

    @property
    def id(self):
        return self.__id

    @property
    def name(self):
        return self.__name

    @property
    def number(self):
        return self.__number

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y

    def __str__(self):
        return str(self.__id) + " " + str(self.__name) + " " + str(self.__number) + " " + str(self.__x) + " " + str(self.__y)