class PersonController:
    def __init__(self, person_repository):
        self.__person_repository = person_repository

    def add(self, person):
        self.__person_repository.add(person)

    def return_all(self):
        return self.__person_repository.get_all()

    def simulate_day(self):
        return self.__person_repository.simulate_day()

    def kill(self):
        return self.__person_repository.killSomeone()

    def vaccinate(self):
        return self.__person_repository.vaccinateSomeone()
