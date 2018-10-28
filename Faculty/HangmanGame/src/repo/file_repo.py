from domain.entities import Sentence
from repo.repository import Repository


class FileRepository(Repository):
    """
    the class for the file repository; inheritance from the class Repository
    used for taking the sentences from a file instead of a memory based repo
    """
    def __init__(self, fileName):
        Repository.__init__(self)
        self.__fName = fileName
        self.read_from_file()

    def read_from_file(self):
        """
        function used for reading from the file and for adding those lines to the repo as sentence instances
        :return:
        """
        # try:
        #     f = open(self.__fName, 'r')
        #     line = f.readline().strip()
        #     while line != "":
        #         Repository.add(self, line)
        #         line = f.readline().strip()
        # except IOError as ie:
        #     print("there was a problem while reading from the file! ")
        # finally:
        # f.close()

        f = open(self.__fName, 'r')
        line = f.readline().strip()
        while line != "":
            id = len(self.return_all())
            sent = Sentence(id, line)
            Repository.add(self, sent)
            line = f.readline().strip()
        f.close()

    def write_to_file(self):
        """
        the function that writes to the file when adding a new sentence for example
        :return:
        """
        f = open(self.__fName, 'w')
        sentences = Repository.return_all(self)
        for s in sentences:
            m = s.fraza
            string = str(m)
            string += "\n"
            f.write(string)
        f.close()

    def add(self, sentence):
        """
        overrides the function that adds a new sentence from the repository
        :param sentence:
        :return:
        """
        Repository.add(self, sentence)
        self.write_to_file()

    def return_all(self):
        """
        funtction that overrides the function from the repository class that returns all the sentences
        :return:
        """
        return Repository.return_all(self)
