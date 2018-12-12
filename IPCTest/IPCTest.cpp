// IPCTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>
#include <vector>

using namespace boost::interprocess;

int main(void) {
	try {
		message_queue::remove("message_queue");

		// create a message_queue
		message_queue mq(create_only, "message_queue", 300, sizeof(int));

		for (int i = 0; i < 300; ++i) {
			mq.send(&i, sizeof(int), 0);
		}
	} catch(interprocess_exception &ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}