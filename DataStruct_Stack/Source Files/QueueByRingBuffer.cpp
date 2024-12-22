#include "../Haeder Files/QueueByRingBuffer.h"

int* QueueByRingBuffer::InitQueue()
{
    int lenght = _queueByRingBuffer->GetLength();

    int* newData = new int[lenght];
    _queueByRingBuffer->SetData(newData);

    return _queueByRingBuffer->GetData();
}

void PushInRingBuffer(int data, RingBuffer* ringBuffer)
{
    if (ringBuffer->GetOccupiedSpace() == ringBuffer->GetLength())
    {
        ResizeBuffer(ringBuffer);
    }

    int* dataArray = ringBuffer->GetData();
    int indexIn = ringBuffer->GetIndexIn();

    dataArray[indexIn] = data;
    ringBuffer->SetIndexIn((indexIn + 1) % ringBuffer->GetLength());
    ringBuffer->SetOccupiedSpace(ringBuffer->GetOccupiedSpace() + 1);
}

void QueueByRingBuffer::PushInQueue(int data)
{
    PushInRingBuffer(data, _queueByRingBuffer);
}

void ResizeBuffer(RingBuffer* ringBuffer)
{
    int newCapacity = ringBuffer->GetLength() * 2;
    int* newData = new int[newCapacity];

    int currentIndex = ringBuffer->GetIndexOut();
    for (int i = 0; i < ringBuffer->GetOccupiedSpace(); ++i)
    {
        newData[i] = ringBuffer->GetData()[currentIndex];
        currentIndex = (currentIndex + 1) % ringBuffer->GetLength();
    }

    delete[] ringBuffer->GetData();
    ringBuffer->SetData(newData);
    ringBuffer->SetLength(newCapacity);
    ringBuffer->SetIndexOut(0);
    ringBuffer->SetIndexIn(ringBuffer->GetOccupiedSpace());
}

int QueueByRingBuffer::PopInQueue()
{
    return Pop(_queueByRingBuffer);
}

RingBuffer* QueueByRingBuffer::GetQueueByRingBuffer() const
{
    return _queueByRingBuffer;
}


bool QueueByRingBuffer::IsEmptyQueue()
{
    return _queueByRingBuffer->GetOccupiedSpace() == 0;
}

int Pop(RingBuffer* ringBuffer)
{

    int* dataArray = ringBuffer->GetData();
    int indexOut = ringBuffer->GetIndexOut();

    int data = dataArray[indexOut];
    ringBuffer->SetIndexOut((indexOut + 1) % ringBuffer->GetLength());
    ringBuffer->SetOccupiedSpace(ringBuffer->GetOccupiedSpace() - 1);

    return data;
}
