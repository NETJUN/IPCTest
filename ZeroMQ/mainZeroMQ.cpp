//  Hello World server

#include <zmq.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <assert.h>
#include <algorithm>


int compare(const void* a, const void* b) {
	return *((int*)(a)) > *((int*)(b));
}

int main(void)
{
	//  Socket to talk to clients
	void *context = zmq_ctx_new();
	void *responder = zmq_socket(context, ZMQ_REP);
	int rc = zmq_bind(responder, "tcp://*:5555");
	assert(rc == 0);
	int data[10000];
	while (1) {
		zmq_recv(responder, data, 10000, 0);
		//printf("Received Hello\n");
		//Sleep(3000);          //  Do some 'work'
		
		//qsort(data, 100, sizeof(int), compare);
		zmq_send(responder, data, 10000, 0);
	}
	return 0;
}