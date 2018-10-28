import unittest

from domain.entities import Sentence


class TestEntities(unittest.TestCase):
    """
    test case for testing the entities from domain
    """
    def test1(self):
        s1 = Sentence(1, 'abc abc')
        s2 = Sentence(1, 'abc abc')
        self.assertEqual(s1, s2)

    def test2(self):
        s1 = Sentence(1, 'abcd abc')
        s2 = Sentence(1, 'abc abc')
        self.assertNotEqual(s1, s2)

    def test3(self):
        s1 = Sentence(1, 'abc abc')
        s2 = Sentence(2, 'abc abc')
        self.assertNotEqual(s1, s2)

    def test4(self):
        s1 = Sentence(1, 'abcd abcd')
        self.assertEqual(s1, Sentence(1, 'abcd abcd'))

if __name__ == '__main__':
    unittest.main()
