from domain.address import Address
from repo.repository import Repository


class FileRepoException(Exception):
    def __init__(self, msg):
        self.__msg = msg

    def __str__(self):
        return self.__msg


class FileRepository(Repository):
    def __init__(self, fileName):
        Repository.__init__(self)
        self.__fName = fileName
        self.__readFromFile()

    def __readFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                args = line.split(",")
                address = Address(args[0], args[1], args[2], args[3], args[4])
                Repository.add(self, address)
                line = f.readline().strip()
        except IOError:
            raise FileRepoException("input output error when reading ")
        finally:
            f.close()

    def __writeToFile(self):
        f = open(self.__fName, "w")
        addresses = Repository.return_all(self)
        for a in addresses:
            adresa = str(a.id) + "," + str(a.name) + "," + str(a.number) + "," + str(a.x) + "," + str(a.y)
            adresa += "\n"
            f.write(adresa)
        f.close()

    def add(self, address):
        Repository.add(self, address)
        self.__writeToFile()

    def remove(self, address_id):
        Repository.remove(self, address_id)
        self.__writeToFile()

    def display_string(self, sir):
        return Repository.display_string(self, sir)

    def distance(self, adresa, distanta):
        return Repository.distance(self, adresa, distanta)

    def return_by_id(self, ids):
        return Repository.return_by_id(self, ids)
