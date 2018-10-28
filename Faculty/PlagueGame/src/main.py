from controllers.person_controller import PersonController
from repository.file_repository import FileRepo
from ui.console import Console

person_repo = FileRepo('persons')

person_controller = PersonController(person_repo)

console = Console(person_controller)
ok = True
while __name__ == '__main__':
    if ok is True:
        print("You control these people! As a day passes, one more gets infected.\n")
        print("Also, one more (if they're vaccinated and ill) gets healthy.\n")
        print("Vaccinate them, kill them, make one more person appear. It's up to you!\n")
        print("\tHave fun!\n\n")
        ok = False
    console.RunMenu()