import unittest

from domain.entities import Sentence
from repo.repository import Repository


class TestRepo(unittest.TestCase):
    """
    the unit test case for testing the classic memory repository
    """
    def test_repo(self):
        repos = Repository()
        s1 = Sentence(1, 'abc abc abc')
        repos.add(s1)
        self.assertEqual(str(repos.return_all()[0]), '1 - abc abc abc')
        x = repos.return_all()
        self.assertEqual(x, repos.return_all())

if __name__ == '__main__':
    unittest.main()
