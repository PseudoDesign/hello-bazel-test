import sys
import unittest

from proto import greeting_pb2


class TestCase(unittest.TestCase):
    def test_get_greet_encode_and_decode(self):
        my_request = greeting_pb2.GetGreet(
            name="Adam"
        )
        self.assertIsNotNone(my_request)
        serialized = my_request.SerializeToString()
        decoded_request = greeting_pb2.GetGreet()
        decoded_request.ParseFromString(serialized)
        self.assertEqual("Adam", decoded_request.name)




if __name__ == "__main__":
    sys.exit(unittest.main())