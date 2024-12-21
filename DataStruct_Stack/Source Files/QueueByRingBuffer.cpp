#include "../Haeder Files/QueueByRingBuffer.h"

int* QueueByRingBuffer::InitQueue()
{
    int lenght = _queueByRingBuffer->_lenght;

    _queueByRingBuffer->_data = new int[lenght];

    return _queueByRingBuffer->_data;
}

void PushInRingBuffer(int data, RingBuffer* ringBuffer)
{
    if (ringBuffer->_ocupiedSpace == ringBuffer->_lenght)
    {
        ResizeBuffer(ringBuffer);
    }

    ringBuffer->_data[ringBuffer->_indexIn] = data;
    ringBuffer->_indexIn = (ringBuffer->_indexIn + 1) % ringBuffer->_lenght;
    ++ringBuffer->_ocupiedSpace;
}

void QueueByRingBuffer::PushInQueue(int data)
{
    PushInRingBuffer(data, _queueByRingBuffer);
}

void ResizeBuffer(RingBuffer* ringBuffer)
{
    int newCapacity = ringBuffer->_lenght * 2;
    int* newData = new int[newCapacity];

    int currentIndex = ringBuffer->_indexOut;
    for (int i = 0; i < ringBuffer->_ocupiedSpace; ++i)
    {
        newData[i] = ringBuffer->_data[currentIndex];
        currentIndex = (currentIndex + 1) % ringBuffer->_lenght;
    }

    delete[] ringBuffer->_data;
    ringBuffer->_data = newData;
    ringBuffer->_lenght = newCapacity;
    ringBuffer->_indexOut = 0;
    ringBuffer->_indexIn = ringBuffer->_ocupiedSpace;
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
    return _queueByRingBuffer->_ocupiedSpace == 0;
}

int Pop(RingBuffer* ringBuffer)
{
    int data = ringBuffer->_data[ringBuffer->_indexOut];
    ringBuffer->_indexOut = (ringBuffer->_indexOut + 1) % ringBuffer->_lenght;
    --ringBuffer->_ocupiedSpace;

    return data;
}
