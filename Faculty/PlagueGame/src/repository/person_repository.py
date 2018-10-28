class PersonRepository:
    def __init__(self):
        self.__entities = []

    def add(self, person):
        self.__entities.append(person)

    def get_index(self, person):
        for i in range(len(self.__entities)):
            if self.__entities[i] == person:
                return int(i)
        return None

    def remove(self, person):
        if self.get_index(person) is None:
            return "the entity is not in the repository "
        else:
            for p in self.__entities:
                if p == person:
                    del self.__entities[self.get_index(person)]

    def find_by_id(self, person_id):
        for i in range(len(self.__entities)):
            if self.__entities[i].id == person_id:
                return self.__entities[i]
        return None

    def get_all(self):
        return self.__entities

    def simulate_day(self):
        ok = True
        for i in range(len(self.__entities)):
            if ok is True:
                if self.__entities[i].immunization == "nonvaccinated" and self.__entities[i].status == "healthy":
                    self.__entities[i].status = "ill"
                    ok = False
                    print('one more infected! ')

        if ok is True:
            print('there are no people to be infected ')
        ok=True
        for i in range(len(self.__entities)):
            if ok is True:
                if self.__entities[i].immunization == "vaccinated" and self.__entities[i].status == "ill":
                    self.__entities[i].status = "healthy"
                    ok = False
                    print('one more cured! ')

        if ok is True:
            print('there are no people to be cured ')

    def killSomeone(self):
        ok = True
        for i in range(len(self.__entities)):
            if ok is True:
                if self.__entities[i].status == "ill":
                    self.__entities.remove(self.__entities[i])
                    print('one more dead! ')
                    ok = False
                    break

        if ok is True:
            print('there are no people to kill :( ')


    def vaccinateSomeone(self):
        ok = True
        for i in range(len(self.__entities)):
            if ok is True:
                if self.__entities[i].immunization == "nonvaccinated":
                    self.__entities[i].immunization = "vaccinated"
                    print('one more vaccinated! ;) ')
                    ok = False
                    break
        if ok == True:
            print('there are no people to vaccinate\n ')
