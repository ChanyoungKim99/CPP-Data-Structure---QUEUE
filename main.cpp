#include <iostream>

const int QUEUE_SIZE{ 10 };

enum Command
{
	PUSH = 1,
	POP = 2
};

struct Queue
{
	int container[QUEUE_SIZE];
	int topIndex{ -1 };
};

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "--------" << std::endl;
}

void PrintQueue(Queue& queue)
{
	std::cout << "---- queue ----" << std::endl;

	if (queue.topIndex < 0)
	{
		std::cout << "EMPTY" << std::endl;
		return;
	}

	for (int i = 0; i <= queue.topIndex; i++)
	{
		std::cout << queue.container[i] << " ";
	}
	std::cout << "---------------" << std::endl;
}

void Push(Queue& queue, int value)
{
	if (queue.topIndex >= QUEUE_SIZE - 1)
	{
		std::cout << "QUEUE IS FULL !!!" << std::endl;
		return;
	}
	queue.container[++queue.topIndex] = value;
}

void Pop(Queue& queue)
{
	int temp[QUEUE_SIZE]{};

	if (queue.topIndex < 0)
	{
		return;
	}

	std::cout << "pop : " << queue.container[0] << std::endl;
	--queue.topIndex;

	for (int i = 0; i <= queue.topIndex; i++)
	{
		temp[i] = queue.container[i + 1];
		queue.container[i] = temp[i];
	}
}

int main()
{
	Queue myQueue;
	PrintInfo();

	while (true)
	{
		PrintQueue(myQueue);
		int command;

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{
				int value;
				std::cout << "\tpush value >> ";
				std::cin >> value;
				Push(myQueue, value);
				break;
			}

			case POP:
				Pop(myQueue);
				break;

			default:
				std::cout << "잘못된 명령어입니다." << std::endl;
				break;
		}
	}
}