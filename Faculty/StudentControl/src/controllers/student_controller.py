class StudentController:
    def __init__(self, repository):
        self.__repository = repository

    def add(self, student):
        self.__repository.add(student)

    def return_all(self):
        return self.__repository.return_all()
