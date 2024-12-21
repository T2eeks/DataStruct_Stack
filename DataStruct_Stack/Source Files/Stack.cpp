#include "../Haeder Files/Stack.h"

int Stack::GetLength() const
{
    return _length;
}

void Stack::StackInit()
{
    Data = new int[_capacity];
}

void Stack::ResizeArray()
{
    int* newArray = new int[_capacity * GrowthFactor];

    for (int i = 0; i < _capacity; i++)
    {
        newArray[i] = Data[i];
    }

    _capacity *= GrowthFactor;
    delete[] Data;
    Data = newArray;
}

void Stack::Push(int element)
{
    if (_length >= _capacity)
    {
        ResizeArray();
    }

    Data[_length] = element;
    _length++;
}

int Stack::Pop()
{
    --_length;
    return Data[_length];
}

bool Stack::IsEmpty() const
{
    return (_length == 0);
}
