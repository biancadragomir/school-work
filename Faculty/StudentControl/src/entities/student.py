class Student:
    def __init__(self, id, name, group):
        self.__id = id
        self.__name = name
        self.__group = group

    def set_name(self, value):
        self.__name = value

    def set_group(self, value):
        self.__group = value

    def get_name(self):
        return self.__name

    def get_id(self):
        return int(self.__id)

    def get_group(self):
        return int(self.__group)

    def __str__(self):
        return str(self.__id) + " - " + str(self.__name) + " (" + str(self.__group) + ") "
