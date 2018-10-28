import unittest

from domain.entities import Sentence
from repo.file_repo import FileRepository


class TestFileRepo(unittest.TestCase):
    """
    unit test for testing the file repository
    """
    def test_repo(self):
        repos = FileRepository('teste')
        s1 = Sentence(1, 'abc abc abc')
        repos.add(s1)
        self.assertEqual(str(repos.return_all()[0]), '1 - abc abc abc')
        x = repos.return_all()
        self.assertEqual(x, repos.return_all())

        s2 = Sentence(1, 'abc abc abc')
        repos.add(s2)
        self.assertEqual(str(repos.return_all()[1]), '1 - abc abc abc')
        x = repos.return_all()
        self.assertEqual(x, repos.return_all())

        s3 = Sentence(1, 'abc abc abc')
        repos.add(s3)
        self.assertEqual(str(repos.return_all()[2]), '1 - abc abc abc')
        x = repos.return_all()
        self.assertEqual(x, repos.return_all())

        s4 = Sentence(1, 'abc abc abc')
        repos.add(s4)
        self.assertEqual(str(repos.return_all()[3]), '1 - abc abc abc')
        x = repos.return_all()
        self.assertEqual(x, repos.return_all())


if __name__ == '__main__':
    unittest.main()
