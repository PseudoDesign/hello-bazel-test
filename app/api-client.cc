#include <string>
#include <iostream>

#include "zmq.hpp"
#include "api/greeting.pb.h"

int main()
{
    greeting::GetGreet greeting_request;


    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a REQ (request) socket and connect to interface
    zmq::socket_t socket{context, zmq::socket_type::req};
    socket.connect("tcp://localhost:5555");

    // Set Up our greeting request
    greeting_request.set_name("Adam");

    for (auto request_num = 0; request_num < 10; ++request_num) 
    {
        // send the request message
        std::string serialized;
        greeting_request.SerializeToString(&serialized);
        std::cout << "Sending GetGreet Request " << request_num << "..." << std::endl;
        std::cout << "Serialized to: '" << serialized << "'" << std::endl;
        socket.send(zmq::buffer(serialized), zmq::send_flags::none);
        
        // wait for reply from server
        zmq::message_t reply{};
        socket.recv(reply, zmq::recv_flags::none);

        std::cout << "Received " << reply.to_string(); 
        std::cout << " (" << request_num << ")";
        std::cout << std::endl;
    }

    return 0;
}
