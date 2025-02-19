import sys
import unittest

import greeting_pb2
import zmq


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

    def test_get_greet_response_encode_and_decode(self):
        my_response = greeting_pb2.GetGreetResponse(
            greeting="Hello Adam"
        )
        self.assertIsNotNone(my_response)
        serialized = my_response.SerializeToString()
        decoded_response = greeting_pb2.GetGreetResponse()
        decoded_response.ParseFromString(serialized)
        self.assertEqual("Hello Adam", decoded_response.greeting)

    def test_get_from_api_service(self):
        context = zmq.Context()

        #  Socket to talk to server
        print("Connecting to hello world server…")
        socket = context.socket(zmq.REQ)
        socket.connect("tcp://localhost:5555")
        #  Do 10 requests, waiting each time for a response
        for request in range(10):
            my_request = greeting_pb2.GetGreet(
                name="Adam"
            )
            self.assertIsNotNone(my_request)
            serialized = my_request.SerializeToString()
            socket.send(serialized)

            #  Get the reply.
            message = socket.recv()
            decoded_response = greeting_pb2.GetGreetResponse()
            decoded_response.ParseFromString(message)
            self.assertEqual("Hello Adam", decoded_response.greeting)

if __name__ == "__main__":
    sys.exit(unittest.main())