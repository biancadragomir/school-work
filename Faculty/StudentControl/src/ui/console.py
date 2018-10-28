from entities.student import Student


class Console:
    def __init__(self, student_controller):
        self._student_controller = student_controller

    def ui_add_student(self):
        id = int(input("introduce the id: "))
        name = input("introduce the name: ")
        group = int(input("introduce the group number: "))
        student = Student(id, name, group)
        self._student_controller.add(student)

    def ui_print_students(self):
        if len(self._student_controller.return_all()) is 0:
            print("there are no students! ")
        for i in self._student_controller.return_all():
            print(str(i))

    @staticmethod
    def print_commands():
        string = "These are the available commands: "
        string += "\n \t 1 - add a student\n"
        string += "\t 2 - print students"
        print(string)

    def run_menu(self):
        self.print_commands()
        Commands = {"1": self.ui_add_student,
                    "2": self.ui_print_students}
        cmd = input("introduce the command: ")
        try:
            Commands[cmd]()
        except ValueError as ve:
            print(ve)
        except TypeError as te:
            print(te)
        except Exception as exc:
            print(exc)
