#include "../Haeder Files/Menu.h"
#include <iostream>

int main()
{
    int numberOfStruct;

    while (true)
    {
        numberOfStruct = ChooseStruct();
        if (numberOfStruct == 1)
        {
            Stack stack;
            stack.StackInit();
            StackMenu(stack);
        }

        if (numberOfStruct == 2)
        {
            RingBuffer ringbuffer;
            ringbuffer.InitBuffer();
            RingBufferMenu(ringbuffer);
        }

        if (numberOfStruct == 3)
        {
            QueueByRingBuffer queueByRingBuffer;
            queueByRingBuffer.InitQueue();
            QueueRingBufferMenu(queueByRingBuffer);
        }

        if (numberOfStruct == 4)
        {
            QueueByTwoStacks TwoStacksQueue;
            TwoStacksQueue.QueueInit();
            TwoStacksQueueMenu(TwoStacksQueue);
        }
    }
    return 0;
}
