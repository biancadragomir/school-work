import unittest

from controller.sentence_controller import Controller
from domain.entities import Sentence
from repo.file_repo import FileRepository


class ControllersTest(unittest.TestCase):
    """
    unit case for testing the controllers
    """
    def test_add(self):
        rep = FileRepository('file')
        cont = Controller(rep)
        s1 = Sentence(0, 'abc abc')
        cont.add(s1)

        self.assertEqual(str(s1), '0 - abc abc')

        self.assertEqual(str(s1), str(cont.return_all()[0]))

        s2 = Sentence(1, 'abcd abcd')
        cont.add(s2)
        self.assertEqual(str(s2), str(cont.return_all()[1]))

        self.assertNotEqual(s1, s2)
        self.assertNotEqual(s1, cont.return_all()[1])

        s3 = Sentence(2, 'abcd abcd')
        cont.add(s3)
        self.assertEqual(str(s3), str(cont.return_all()[2]))

        self.assertNotEqual(s1, s3)
        self.assertNotEqual(s1, cont.return_all()[2])

if __name__ == '__main__':
    unittest.main()
