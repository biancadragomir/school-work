import unittest

from controllers.person_controller import PersonController
from domain.entities import Person
from repository.person_repository import PersonRepository


class TestControllers(unittest.TestCase):
    def test_all(self):
        person_repository = PersonRepository()
        pers_cont = PersonController(person_repository)
        p1 = Person(1,"nonvaccinated","healthy")
        p2 = Person(1,"vaccinated","healthy")
        p3 = Person(1,"nonvaccinated","healthy")
        pers_cont.add(p1)
        pers_cont.add(p2)
        pers_cont.add(p3)
        self.assertEqual(p1,p3)
        self.assertNotEqual(p1,p2)
        self.assertEqual(len(pers_cont.return_all()),3)



if __name__ == '__main__':
    unittest.main()
