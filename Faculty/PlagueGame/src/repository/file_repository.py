from domain.entities import Person
from repository.person_repository import PersonRepository


class FileRepoException(Exception):
    def __init__(self, msg):
        self.__msg = msg

    def __str__(self):
        return self.__msg


class FileRepo(PersonRepository):
    def __init__(self, fileName):
        PersonRepository.__init__(self)
        self.__fName = fileName
        self.__readFromFile()

    def __readFromFile(self):
        try:
            f = open(self.__fName, 'r')
            line = f.readline().strip()
            while line != "":
                args = line.split(",")
                person = Person(args[0], args[1], args[2])
                PersonRepository.add(self, person)
                line = f.readline().strip()
        except IOError:
            raise FileRepoException("sth is not ok... ")
        finally:
            f.close()

    def __writeToFile(self):
        f = open(self.__fName, 'w')
        persons = PersonRepository.get_all(self)
        for p in persons:
            pers = str(p.id) + "," + p.immunization + "," + p.status
            pers += "\n"
            f.write(pers)
        f.close()

    def add(self, person):
        PersonRepository.add(self, person)
        self.__writeToFile()

    def remove(self, person):
        PersonRepository.remove(self, person)
        self.__writeToFile()
