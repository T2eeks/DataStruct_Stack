#include "../Haeder Files/QueueByRingBuffer.h"

int* RingBuffer::InitBuffer()
{
    _data = new int[_lenght];
    return _data;
}

void RingBuffer::Push(int data)
{
    _data[_indexIn] = data;
    _indexIn = (_indexIn + 1) % _lenght;
    ++_fullSize;

    if (_ocupiedSpace < _lenght)
    {
        ++_ocupiedSpace;
    }
    if (_fullSize > _lenght)
    {
        _indexOut = (_indexOut + 1) % _lenght;
    }
}

int RingBuffer::Pop()
{
    --_ocupiedSpace;
    int temp = _indexOut;
    _indexOut = (_indexOut + 1) % _lenght;

    return _data[temp];
}

int RingBuffer::GetLength() const
{
    return _lenght;
}

int RingBuffer::GetOccupiedSpace() const
{
    return _ocupiedSpace;
}

void RingBuffer::PushToRingBuffer(int data)
{
    _data[_indexIn] = data;
    _indexIn = (_indexIn + 1) % _lenght;
    ++_fullSize;

    if (_ocupiedSpace < _lenght)
    {
        ++_ocupiedSpace;
    }
    if (_fullSize > _lenght)
    {
        _indexOut = (_indexOut + 1) % _lenght;
    }
}

int RingBuffer::PopFromRingBuffer()
{
    --_ocupiedSpace;
    int temp = _indexOut;
    _indexOut = (_indexOut + 1) % _lenght;

    return _data[temp];
}
