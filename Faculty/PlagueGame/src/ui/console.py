from domain.entities import Person
import random


class Console:
    def __init__(self, person_controller):
        self._person_controller = person_controller

    @staticmethod
    def print_commands():
        string = "\n"
        string += "the following commands are available: \n"
        string += "\t1 - add a new person\n"
        string += "\t2 - print all the persons\n"
        string += "\t3 - a new day\n"
        string += "\t4 - kill someone\n"
        string += "\t5 - vaccinate someone\n"

        print(string)

    def ui_add_person(self):
        id = len(self._person_controller.return_all()) + 1
        immunization = "nonvaccinated"
        status = "healthy"
        p = Person(id, immunization, status)
        self._person_controller.add(p)

    def ui_print_persons(self):
        for p in self._person_controller.return_all():
            print(str(p))

    def ui_simulate_day(self):
        self._person_controller.simulate_day()

    def uiKill(self):
        self._person_controller.kill()

    @staticmethod
    def ui_exit():
        print("till next time!")
        raise SystemExit

    def uiVaccinate(self):
        self._person_controller.vaccinate()

    def RunMenu(self):
        self.print_commands()

        Commands = {"x": self.ui_exit,
                    "1": self.ui_add_person,
                    "2": self.ui_print_persons,
                    "3": self.ui_simulate_day,
                    "4": self.uiKill,
                    "5": self.uiVaccinate}

        cmd = input("introduce the command: ")
        if cmd not in Commands:
            print("the command does not exist! ")
        # try:
        Commands[cmd]()
        # except TypeError as te:
        #     print(te)
        # except ValueError as ve:
        #     print(ve)
        # except Exception as exc:
        #     print(exc)
