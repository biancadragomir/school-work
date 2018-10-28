from controller.sentence_controller import Controller
from domain.entities import Sentence
from repo.repository import Repository
from ui.console import Console

repo = Repository()
controller = Controller(repo)
console = Console(controller)

controller.add(Sentence(1, 'the fox is ok'))
controller.add(Sentence(2, 'the kid is ok'))

while __name__ == '__main__':
    console.RunMenu()
