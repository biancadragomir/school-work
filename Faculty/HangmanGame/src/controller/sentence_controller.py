import random


class Controller:
    """
    the controller class for our game
    """
    def __init__(self, repo):
        self.__repo = repo

    def add(self, sentence):
        """
        function for adding a new sentence
        :param sentence: the sentence to be added
        :return:
        """
        fr = sentence.fraza
        ok = True
        if fr.find(" ") == -1:
            ok = False
        if len(fr) < 4:
            ok = False
        if ok == True:
            self.__repo.add(sentence)
        else:
            print("your sentence is not ok! ")

    def return_all(self):
        """
        the function that returns all the sentences from the repository
        :return:
        """
        return self.__repo.return_all()

    def play(self):
        """
        the function for playing the game
        :return:
        """
        l = int(len(self.return_all()))
        nr = random.randint(0, int(l))
        sent = self.return_all()
        for i in range(len(self.__repo.return_all())):
            if int(nr) == int(self.__repo.return_all()[i].id()):
                sentence = self.__repo.return_all()[i].fraza

        lista = []
        for s in sentence:
            lista.append(s)
        # print(sentence)
        l1 = lista[0]
        ln = lista[len(lista) - 1]

        # for letter in lista:
        #     if letter == l1 or letter == ln:
        #         print(letter)
        #     else:
        #         print("_")

        ok = []
        tries = 0
        str_off = ""
        for lx in lista:
            str_off += lx
        for letter in lista:
            if letter == l1:
                ok.append(l1)
            elif letter == ln:
                ok.append(ln)
            elif letter == " ":
                ok.append(" ")
            else:
                ok.append("_")
                tries += 1

        string6 = ""
        for l in ok:
            string6 += l
        print(str(string6))
        print("number of letters to complete: ", tries)

        dead = 0
        won = False
        while dead < 7 and won == False:
            verifica = 0
            litera = input("introduce a new letter: ")
            apare = False
            p = 0
            px = 0
            for l in ok:
                if apare == False and l == litera:
                    p = 1
            if p ==1:
                print("the letter is already there! ")
            else:
                for j in range(len(lista)):
                    if litera == lista[j]: #the letter is in the sentence
                        ok[j] = litera
                        apare = True

                if apare == False:
                    dead += 1
                    print("the letter is not ok! ")
                    print(7-int(dead), 'tries left')

                    lista22 = ['h', 'a', 'n', 'g', 'm', 'a', 'n']
                    hng = ""
                    for ps in range(0, dead):
                        hng += lista22[ps]

                    print(hng)
            if apare == True:
                string1 = ""
                for l in ok:
                    string1 += l
                print(string1)
                print(7 - int(dead), 'tries left')
            for z in range(len(ok)):
                if ok[z] == "_":
                    px += 1
            if dead < 7 and px == 0:
                won = True
        if dead == 7:
            print("you lost! ")
            print("\n")
            print("HANGMAN")
            print("\n")
            print("the sentence was: ", str_off)
        elif won == True:
            print("congratulations! you won! ")

                    # for j in lista:
                    #     if str(j) == str(litera):
                    #         verifica += 1
                    #         for k in range(len(ok)):
                    #             if ok[k] == litera:
                    #                 lista[k] = litera
