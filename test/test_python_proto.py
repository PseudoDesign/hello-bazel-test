import sys
import unittest

from proto import greeting_pb2


class TestCase(unittest.TestCase):
    def test_get_greet_encode_and_Decode(self):
        my_request = greeting_pb2.GetGreet(
            name="Adam"
        )
        self.assertIsNotNone(my_request)



if __name__ == "__main__":
    sys.exit(unittest.main())