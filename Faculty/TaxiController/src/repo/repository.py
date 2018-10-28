from repo.validate_address import AddressValidator
from math import sqrt


class RepoException(Exception):
    def __init__(self, msg):
        self.__msg = msg

    def __str__(self):
        return self.__msg


class Repository:
    def __init__(self):
        self.__entities = []

    def findByID(self, entity_id):
        for i in self.__entities:
            if int(i.id) == int(entity_id):
                return True
        return False

    def add(self, address):

        if self.findByID(address.id) is False:
            if int(address.id) < 0:
                raise RepoException("the id must be positive! ")
            if len(str(address.name)) < 3:
                raise RepoException("the address name is too short! ")
            if int(address.number) < 0:
                raise RepoException("the number must be positive! ")
            if int(address.number) > 100:
                raise RepoException("the number can be at most 100! ")
            self.__entities.append(address)
        else:
            raise RepoException("the id is already there! ")

    def return_all(self):
        return self.__entities

    def display_string(self, sir):
        adrese = []
        for i in self.__entities:
            nume = str(i.name)
            if nume.find(sir) != -1:
                adrese.append(i)
        return list(adrese)

    def distance(self, adresa, distanta):
        adrese = []
        coordx = adresa.x
        coordy = adresa.y
        for i in self.__entities:
            if sqrt((int(coordx) - int(i.x)) ** 2 + (int(coordy) - int(i.y)) ** 2) < int(distanta):
                adrese.append(i)
        return adrese

    def return_by_id(self, ids):
        for i in self.__entities:
            if int(ids) == int(i.id):
                return i
