from domain.entities import Sentence


class Console:
    """
    base console class that will coordinate the program
    """
    def __init__(self, sentence_controller):
        self._sentence_controller = sentence_controller

    def print_commands(self):
        """
        prints the commands that are available
        :return:
        """
        string = "you have the following options:\n"
        string += "\ta - add a new sentence\n"
        string += "\ts - start the game\n"
        print(string)

    # def ui_add_sentence(self):
    #     """
    #     function to add a sentence
    #     :return:
    #     """
    #     sent = str(input("introduce the sentence and press enter: "))
    #     id = int(len(self._sentence_controller.return_all()))
    #     sentence = Sentence(id, sent)
    #     self._sentence_controller.add(sentence)

    def ui_add_sentence_2(self):
        """
        the function for adding a sentence in the repository
        :return:
        """
        sent = str(input("introduce the sentence and press enter: "))
        id = int(len(self._sentence_controller.return_all()))
        sentence = Sentence(id, sent)
        x = []
        ok = 0
        nr = 0
        for l in sent:
            x.append(l)
        for l in x:
            if l == " ":
                ok += 1
            nr += 1
        if nr > 3 and ok >=2:
            self._sentence_controller.add(sentence)
        else:
            print("the sentence is not valid! ")

    def ui_add_sentence_3(self):
        """
        the function for adding a sentence in the repository
        :return:
        """
        sent = str(input("introduce the sentence and press enter: "))
        id = int(len(self._sentence_controller.return_all()))
        sentence = Sentence(id, sent)
        x = []
        ok = 0
        nr = 0
        d = 0
        okk = True
        for l in sent:
            x.append(l)
        for l in x:
            if l == " ":
                ok += 1
            nr += 1
        for l in self._sentence_controller.return_all():
            i = 0
            cuv = []
            j = 0
            for letter in l:
                cuv.append(letter)
            while i < len(cuv) and j < len(x):
                if cuv[i] == x[i]:
                    okk = False
        if nr > 3 and ok >= 2 or okk == False:
            self._sentence_controller.add(sentence)
        else:
            print("the sentence is not valid! ")

    def ui_start(self):
        """
        the function that will start the game when called
        :return:
        """
        self._sentence_controller.play()

    def ui_print_all(self):
        """
        a function that prints all the sentences
        :return:
        """
        sentences = self._sentence_controller.return_all()
        for s in sentences:
            print(str(s))

    def RunMenu(self):
        """
        the funnction to be run in the main module
        :return:
        """
        self.print_commands()
        Commands = {"s": self.ui_start,
                    "p": self.ui_print_all,
                    "a": self.ui_add_sentence_2}

        cmd = input("introduce the command: ")
        try:
            Commands[cmd]()
        except ValueError as ve:
            print(ve)
        except TypeError as te:
            print(te)
        except Exception as exc:
            print(exc)
