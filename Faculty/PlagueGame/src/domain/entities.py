class Person:
    def __init__(self, id, immunization, status):
        self.__id = id
        self.__immunization = immunization
        self.__status = status

    @property
    def id(self):
        return self.__id

    @property
    def immunization(self):
        return self.__immunization

    @property
    def status(self):
        return self.__status

    @status.setter
    def status(self, value):
        self.__status = value

    @immunization.setter
    def immunization(self, value):
        self.__immunization = value

    def __str__(self):
        return str(self.id) + " - " + self.immunization + " and " + self.status

    def __eq__(self, other):
        return self.id == other.id and self.immunization == other.immunization and self.status == other.status
