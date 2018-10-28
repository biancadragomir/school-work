import unittest

from controllers.address_controller import AddressController
from domain.address import Address
from repo.repository import Repository


class ControllerTest(unittest.TestCase):
    def test_all(self):
        address_repo = Repository()
        address_c = AddressController(address_repo)
        a1 = Address(1, "ghdoja", 10, 18, 20)
        a2 = Address(2, "rovine", 16, 20, 19)
        address_c.add(a1)
        self.assertEqual(len(address_repo.return_all()), 1)
        self.assertEqual(a1.id, 1)
        self.assertEqual(a1.name, "ghdoja")
        self.assertEqual(a1.number, 10)
        self.assertEqual(a1.x, 18)
        self.assertEqual(a1.y, 20)
        address_c.add(a2)
        self.assertNotEqual(len(address_repo.return_all()), 1)
        self.assertEqual(len(address_repo.return_all()), 2)
        self.assertNotEqual(a1, a2)
        lista1 = []
        for i in address_c.display_string("gh"):
            lista1.append(i)
        self.assertEqual((address_c.display_string("gh")), lista1)
        lista = []
        for i in address_c.distance(a1, 10):
            lista.append(i)
        self.assertEqual(lista, address_c.distance(a1, 10))




if __name__ == '__main__':
    unittest.main()
