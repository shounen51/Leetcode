import unittest
import main

class testCase(unittest.TestCase):
    def setUp(self):
        self.main = main.Solution()

    def tearDown(self):
        self.args = None

    def test_1(self):
        expected = [1331]
        result = self.main.minOperations([47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38], [3])
        self.assertEqual(expected, result)

    def test_2(self):
        expected = []
        result = self.main.minOperations([], [])
        self.assertEqual(expected, result)
        
if __name__ == "__main__":
    unittest.main()