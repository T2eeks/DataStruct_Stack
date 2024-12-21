#include "../Haeder Files/Menu.h"
#include "../Haeder Files/QueueByRingBuffer.h"
#include <iostream>

using namespace std;

void InvalidInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Unknown command.\n";
}

int ChooseStruct()
{
    int input;
    cout << "Choose one of the structures: " << endl;
    cout << "1. Stack\n"
        << "2. Ring buffer\n"
        << "3. Queue by ring buffer\n"
        << "4. Queue by two stacks\n";

    cin >> input;
    if (cin.fail())
    {
        InvalidInput();
        return ChooseStruct();
    }

    const int maxOperationInput = 4;
    const int minOperationInput = 0;

    if (input >= minOperationInput && input <= maxOperationInput)
    {
        return input;
    }

    cout << "Please choose a correct structure." << endl;
    return ChooseStruct();
}

void StackMenu(Stack& stack)
{
    while (true)
    {
        cout << "Stack:\n"
            << "Size: " << stack.GetLength() << "\n"
            << "1. Push\n"
            << "2. Pop\n"
            << "Back 0" << endl;

        int choose;
        cin >> choose;
        if (cin.fail())
        {
            InvalidInput();
            continue;
        }

        switch (choose)
        {
        case 1:
            stack.Push(Common::GetValue());
            break;

        case 2:
            if (!stack.IsEmpty())
            {
                cout << "Deleted element - " << stack.Pop() << endl;
            }
            else
            {
                cout << "Empty stack." << endl;
            }
            break;

        case 0:
            return;

        default:
            cout << "There is no such command. Choose another." << endl;
            break;
        }
    }
}

void RingBufferMenu(RingBuffer& ringBuffer)
{
    while (true)
    {
        std::cout << "Ring buffer:\n"
            << "Size: " << ringBuffer.GetLength() << "\n" << std::endl;

        Common::ShowSpace(ringBuffer);

        std::cout << "1. Push\n"
            << "2. Pop\n"
            << "3. Display buffer\n"
            << "Back 0" << std::endl;

        int choose;
        std::cin >> choose;
        if (std::cin.fail())
        {
            InvalidInput();
            continue;
        }

        switch (choose)
        {
        case 1:
            ringBuffer.Push(Common::GetValue());
            break;

        case 2:
            if (ringBuffer.GetOccupiedSpace() == 0)
            {
                std::cout << "Buffer is empty." << std::endl;
            }
            else
            {
                std::cout << "Popped element - " << ringBuffer.Pop() << std::endl;
            }
            break;

        case 3:
            Common::PrintBuffer(ringBuffer);
            break;

        case 0:
            return;

        default:
            std::cout << "There is no such command. Choose another." << std::endl;
            break;
        }
    }
}

void QueueRingBufferMenu(QueueByRingBuffer& queueByRingBuffer)
{
    while (true)
    {
        std::cout << "Queue by ring buffer:\n"
            << "Size: " << queueByRingBuffer.GetQueueByRingBuffer()->GetLength() << "\n" << std::endl;

        Common::ShowSpaceQueue(queueByRingBuffer);

        std::cout << "1. Enqueue\n"
            << "2. Dequeue\n"
            << "3. Display queue\n"
            << "Back 0" << std::endl;

        int choose;
        std::cin >> choose;
        if (std::cin.fail())
        {
            InvalidInput();
            continue;
        }

        switch (choose)
        {
        case 1:
            queueByRingBuffer.PushInQueue(Common::GetValue());
            break;

        case 2:
            if (queueByRingBuffer.IsEmptyQueue())
            {
                std::cout << "Queue is empty." << std::endl;
            }
            else
            {
                std::cout << "Dequeued element - " << queueByRingBuffer.PopInQueue() << std::endl;
            }
            break;

        case 3:
            Common::PrintQueue(queueByRingBuffer);
            break;

        case 0:
            return;

        default:
            std::cout << "There is no such command. Choose another." << std::endl;
            break;
        }
    }
}

void TwoStacksQueueMenu(QueueByTwoStacks& TwoStacksQueue)
{
    while (true)
    {
        cout << "Queue by two stacks:\n"
            << "Size: " << TwoStacksQueue.GetLengthQueue() << "\n"
            << "1. Enqueue\n"
            << "2. Dequeue\n"
            << "Back 0" << endl;

        int choose;
        cin >> choose;
        if (cin.fail())
        {
            InvalidInput();
            continue;
        }

        switch (choose)
        {
        case 1:
            TwoStacksQueue.PushQueue(Common::GetValue());
            break;

        case 2:
            if (TwoStacksQueue.GetLengthQueue() == 0)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Dequeued element - " << TwoStacksQueue.PopQueue() << endl;
            }
            break;

        case 0:
            return;

        default:
            cout << "There is no such command. Choose another." << endl;
            break;
        }
    }
}
