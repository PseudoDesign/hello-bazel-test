#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include "zmq.hpp"
#include "proto/greeting.pb.h"
#include "lib/greeting.h"

int main() 
{
    using namespace std::chrono_literals;

    std::cout << "Started" << std::endl;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a REP (reply) socket and bind to interface
    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:5555");


    for (;;) 
    {
        zmq::message_t request;

        // receive a request from client
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received " << request.to_string() << std::endl;

        // Decode the GetGreet request
        greeting::GetGreet parsed_greeting;
        parsed_greeting.ParseFromString(request.to_string());

        // Create the GetGreetResponse from the API call
        greeting::GetGreetResponse response;
        std::string greeting_reply = get_greet(parsed_greeting.name());
        std::cout << "Request name: " << parsed_greeting.name() << std::endl;
        std::cout << "Greeting Response: " << greeting_reply << std::endl;
        response.set_greeting(greeting_reply);
        
        // Serialize the response
        std::string serialized_response;
        response.SerializeToString(&serialized_response);

        std::cout << "Sending response " << serialized_response << std::endl;

        // simulate work
        std::this_thread::sleep_for(.05s);

        // send the reply to the client
        socket.send(zmq::buffer(serialized_response), zmq::send_flags::none);
    }

    return 0;
}