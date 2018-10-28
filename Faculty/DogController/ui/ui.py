from domain.student import Dog


class UI:
    def __init__(self, controller):
        self.__controller = controller

    def ui_print_menu(self):
        print("\nthese are the available commands: ")
        print("\t 1 - add a dog")
        print("\t 2 - see the dogs")
        print("\t 3 - delete a dog")
        print("\n")

    def ui_add(self):
        name = input("introduce the name: ")
        age = int(input(("introduce the age: ")))
        dog = Dog(name, age)
        self.__controller.c_add(dog)

    def ui_print(self):
        for i in self.__controller.c_return_repo():
            print(str(i))

    def ui_delete(self):
        name = input("introduce the name: ")
        dogo = Dog(name, 0)
        if self.__controller.c_delete(dogo) != -1:
            print("delete successful! ")
            pass
        else:
            print("the entity does not exist")

    def run(self):

        Commands = {"1": self.ui_add, "2": self.ui_print, "3": self.ui_delete}
        while 1:
            self.ui_print_menu()
            command = input("insert your command: ")
            if command == "1":
                Commands["1"]()

            elif command == "2":
                Commands["2"]()

            elif command == "3":
                Commands["3"]()

            elif command == "0":
                break

