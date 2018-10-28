class AddressController:
    """
    the controller for the addresses
    """
    def __init__(self, address_repository):
        self.__address_repository = address_repository

    def add(self, address):
        """
        method used for adding a new address
        :param address: type address, containing an id, a name, a number, and coordinates x and y
        :return: nothing
        """
        self.__address_repository.add(address)

    def return_all(self):
        """
        method used for seeing all the addresses from the repository
        :return: the contents of the repository
        """
        return self.__address_repository.return_all()

    def display_string(self, sir):
        return list(self.__address_repository.display_string(sir))

    def distance(self, adresa, distanta):
        return self.__address_repository.distance(adresa, distanta)

    def return_by_id(self, ids):
        return self.__address_repository.return_by_id(ids)



