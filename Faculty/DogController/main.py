from controller.controller import Controller
from domain.student import Dog
from repo.repo import Repository
from ui.ui import UI

repo = Repository()
controller = Controller(repo)
ui = UI(controller)

d1 = Dog("edgar", 10)
d2 = Dog("allan", 12)
d3 = Dog("silvester", 3)
d4 = Dog("mojo", 5)
d5 = Dog("rhino", 8)
d6 = Dog("jerry", 9)

controller.c_add(d1)
controller.c_add(d2)
controller.c_add(d3)
controller.c_add(d4)
controller.c_add(d5)
controller.c_add(d6)

ui.run()