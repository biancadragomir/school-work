class Grade:
    def __init__(self, id, lab_number, lab_problem, value):
        self.__id = id
        self.__lab_number = lab_number
        self.__lab_problem = lab_problem
        self.__value = value

    def __str__(self):
        return str(self.__id) + " - " + str(self.__value)
