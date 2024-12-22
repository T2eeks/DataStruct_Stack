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

int* RingBuffer::GetData() const 
{
    return _data;
}

int RingBuffer:: GetIndexOut() const
{
    return _indexOut;
}

void RingBuffer::SetIndexOut(int value)
{
    _indexOut = value;
}

int RingBuffer::GetIndexIn() const
{
    return _indexIn;
}

void RingBuffer::SetIndexIn(int value)
{
    _indexIn = value;
}

void RingBuffer::SetOccupiedSpace(int value)
{
    _ocupiedSpace = value;
}

int RingBuffer::GetFullSize() const
{
    return _fullSize;
}

void RingBuffer::SetFullSize(int value)
{
    _fullSize = value;
}

void RingBuffer::SetLength(int value)
{
    _lenght = value;
}

int RingBuffer::GetLength() const
{
    return _lenght;
}

int RingBuffer::GetOccupiedSpace() const
{
    return _ocupiedSpace;
}

void RingBuffer::SetData(int* newData)
{
    _data = newData;
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
