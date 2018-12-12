//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	printf("Connecting to hello world server¡­\n");
	void *context = zmq_ctx_new();
	void *requester = zmq_socket(context, ZMQ_REQ);
	zmq_connect(requester, "tcp://localhost:5555");

	srand((unsigned)time(NULL));
	int randNum[10000];

	for (int i = 0; i < 10000; ++i) {
		randNum[i] = rand() % 1000;
	}

	clock_t start = clock();
	clock_t end;
	int cnt = 0;
	while (1) {
		end = clock();
		if (end - start == CLOCKS_PER_SEC) {
			break;
		}
		zmq_send(requester, randNum, 10000, 0);
		zmq_recv(requester, randNum, 10000, 0);
		cnt++;
	}
	zmq_close(requester);
	zmq_ctx_destroy(context);

	cout << cnt;
	system("pause");
}