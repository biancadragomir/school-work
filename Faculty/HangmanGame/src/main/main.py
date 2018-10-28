from controller.sentence_controller import Controller
from repo.file_repo import FileRepository
from ui.console import Console

repo = FileRepository('sentences')
controller = Controller(repo)
console = Console(controller)

while __name__ == '__main__':
    console.RunMenu()
