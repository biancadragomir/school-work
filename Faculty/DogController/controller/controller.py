class Controller:
    def __init__(self, repo):
        self.__repo = repo

    def c_add(self, entity):
        self.__repo.r_add(entity)

    def c_return_repo(self):
        return self.__repo.get_entities()

    def c_delete(self, entity):
        return self.__repo.r_delete(entity)
