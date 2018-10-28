class Sentence:
    """
    base class for a sentence
    id - the id of the sentence, automatically generated
    fraza - the sentence itself, introduced by the user
    """
    def __init__(self, id, fraza):
        self.__id = id
        self.__fraza = str(fraza)

    @property
    def fraza(self):
        return str(self.__fraza)

    def id(self):
        return self.__id

    def __str__(self):
        return str(self.__id) + " - " + str(self.__fraza)

    def __eq__(self, other):
        return self.fraza == other.fraza and self.id() == other.id()
