from controllers.address_controller import AddressController
from repo.file_repo import FileRepository
from ui.console import Console

address_repo = FileRepository('address')
address_controller = AddressController(address_repo)

console = Console(address_controller)

while __name__ == '__main__':
    console.RunMenu()