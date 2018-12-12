#include <iostream>
#include <vector>
#include <boost/interprocess/ipc/message_queue.hpp>

using namespace boost::interprocess;

int main(void) {
	try {
		message_queue mq(open_only, "message_queue");

		unsigned int priority;
		message_queue::size_type recvSize;
		//Receive 100 numbers
		for (int i = 0; i < 100; ++i) {
			int number;
			mq.receive(&number, sizeof(number), recvSize, priority);
			std::cout << number << " " << recvSize << " " << priority << std::endl;
		}
	}
	catch (interprocess_exception &ex) {
		message_queue::remove("message_queue");
		std::cout << ex.what() << std::endl;
		return 1;
	}
	message_queue::remove("message_queue");
	return 0;
}