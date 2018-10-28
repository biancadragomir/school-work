class AddressException(Exception):
    def __init__(self, msg):
        self.__msg = msg

    def __str__(self):
        return self.__msg


class AddressValidator:
    def __init__(self):
        pass

    @staticmethod
    def validate(address):
        if type(address.id) is not int or int(address.id) <= 0:
            raise AddressException("the id is not valid! ")
        if type(address.number) is not int or int(address.number) <= 0 or int(address.number) > 100:
            raise AddressException("the number is not valid! ")
        if len(address.name) < 3:
            raise AddressException("the name is less than 3 characters! ")
