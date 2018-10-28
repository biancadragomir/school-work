class StudentRepoException(Exception):
    def __init__(self, msg):
        self.__msg = msg

    def return_message(self):
        return self.__msg


class StudentRepository:
    def __init__(self):
        self.__entities = []

    def find_by_id(self, entity_id):
        for i in self.__entities:
            if int(i.get_id()) == int(entity_id):
                return True
        return False

    def add(self, student):
        if self.find_by_id(student.get_id()) is False:
            self.__entities.append(student)
        else:
            raise StudentRepoException("the id is already in the list! ")

    def return_all(self):
        return self.__entities
