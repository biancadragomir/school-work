from domain.address import Address


class Console:
    def __init__(self, address_controller):
        self._address_controller = address_controller

    @staticmethod
    def print_commands():
        string = "\n"
        string += "\tx - exit\n"
        string += "\t1 - add a new address\n"
        string += "\t2 - print all the addresses\n"
        string += "\t3 - print the addresses whose names contain the given string\n"
        string += "\t4 - print the address at maximum distance\n"

        print(string)

    @staticmethod
    def ui_exit():
        print("goodbye! ")
        raise SystemExit

    def ui_print_all(self):
        for i in self._address_controller.return_all():
            print(str(i))

    def ui_add(self):
        address_id = int(input("introduce the id: "))
        name = input("introduce the name: ")
        number = int(input("introduce the number: "))
        x = int(input("introduce x: "))
        y = int(input("introduce y: "))
        address = Address(address_id, name, number, x, y)
        self._address_controller.add(address)

    def ui_display_string(self):
        sir = input("introduce the string you want to search: ")
        lista = self._address_controller.display_string(sir)
        for i in list(lista):
            print(str(i))

    def ui_distance(self):
        ids = int(input("introduce the id of the address: "))
        dist = int(input("introduce the maximum distance: "))
        adresa = self._address_controller.return_by_id(ids)
        for i in self._address_controller.distance(adresa, dist):
            print(str(i))

    def RunMenu(self):
        self.print_commands()

        Commands = {"1": self.ui_add,
                    "2": self.ui_print_all,
                    "3": self.ui_display_string,
                    "4": self.ui_distance}

        cmd = input("introduce the command: ")

        if cmd not in Commands:
            print("the command does not exist: ")
        try:
            Commands[cmd]()
        except TypeError as te:
            print("te: ", te)

        except ValueError as ve:
            print("ve", ve)

        except Exception as exc:
            print("exc", exc)