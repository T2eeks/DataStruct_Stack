#include "../Haeder Files/Common.h"
#include <iostream>
#include <limits>

using namespace std;

int Common::GetValue()
{
    int value;
    cout << "Enter value:" << endl;
    cin >> value;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid number." << endl;
        return GetValue();
    }

    return value;
}

void Common::ShowSpace(const RingBuffer& ringBuffer)
{
    int space = ringBuffer.GetLength() - ringBuffer.GetOccupiedSpace();

    if (space < 0)
    {
        space = 0;
    }

    cout << "Free space: " << space << endl;
    if (space == 0)
    {
        cout << "When new data is added, old entries will be replaced." << endl;
    }
}

void Common::ShowSpaceQueue(const QueueByRingBuffer& queueByRingBuffer)
{
    const RingBuffer* ringBuffer = queueByRingBuffer.GetQueueByRingBuffer();
    int space = ringBuffer->GetLength() - ringBuffer->GetOccupiedSpace();

    if (space < 0)
    {
        space = 0;
    }

    cout << "Free space: " << space << endl;
    if (space == 0)
    {
        cout << "When new data is added, old entries will be replaced." << endl;
    }
}

void Common::PrintBuffer(const RingBuffer& ringBuffer)
{
    if (ringBuffer.GetOccupiedSpace() == 0)
    {
        cout << "Buffer is empty." << endl;
        return;
    }

    cout << "Buffer contents: ";

    int index = ringBuffer.GetIndexOut();
    for (int i = 0; i < ringBuffer.GetOccupiedSpace(); ++i)
    {
        cout << ringBuffer.GetData()[index] << " ";
        index = (index + 1) % ringBuffer.GetLength();
    }
    cout << endl;
}

void Common::PrintQueue(const QueueByRingBuffer& queueByRingBuffer)
{
    const RingBuffer* ringBuffer = queueByRingBuffer.GetQueueByRingBuffer();
    if (ringBuffer->GetOccupiedSpace() == 0)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue contents: ";

    int index = ringBuffer->GetIndexOut();
    for (int i = 0; i < ringBuffer->GetOccupiedSpace(); ++i)
    {
        cout << ringBuffer->GetData()[index] << " ";
        index = (index + 1) % ringBuffer->GetLength();
    }
    cout << endl;
}
