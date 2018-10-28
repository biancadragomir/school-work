class Repository:
    def __init__(self):
        """
        for initialising the entities from the repo
        """
        self.__entities = []

    def get_entities(self):
        """
        returns the entities from the repo
        :return:
        """
        return self.__entities

    def r_add(self, entity):
        """
        for adding a entity to the repo
        :param entity:
        :return:
        """
        self.__entities.append(entity)

    def r_delete(self, entity):
        """
        for deleting an entity
        :param entity:
        :return:
        """
        for i in range(len(self.__entities)):
            if str(self.__entities[i].get_name()) == str(entity.get_name()):
                del self.__entities[i]
                return 1
        return -1

    def get_size(self):
        """
        for returning the size of the repository
        :return:
        """
        return len(self.__entities)

