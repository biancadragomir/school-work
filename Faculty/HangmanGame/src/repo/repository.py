class Repository:
    """
    the repository class for storing our entities
    """
    def __init__(self):
        self.__entities = []

    def add(self, sentence):
        """
        function for adding a new sentence to the repo. overridden in the file repo
        :param sentence: the sentence type class sentence to be added
        :return:
        """
        self.__entities.append(sentence)

    def return_all(self):
        """
        function that returns all the available sentences
        :return: all the sentences from the repo
        """
        return self.__entities
