#include "../Haeder Files/Stack.h"
#include "../Haeder Files/QueueByTwoStañks.h"

void QueueByTwoStacks::QueueInit()
{
    _firstStack->StackInit();  
    _secondStack->StackInit();
}

void QueueByTwoStacks::PushQueue(int data)
{
    _firstStack->Push(data);  
}

int QueueByTwoStacks::PopQueue()
{
    if (_secondStack->IsEmpty() && _firstStack->IsEmpty())  
    {
        while (!_firstStack->IsEmpty())
        {
            _secondStack->Push(_firstStack->Pop());
        }
    }

    return _secondStack->Pop();  
}

int QueueByTwoStacks::GetLengthQueue()
{
    if (_firstStack->IsEmpty() && _secondStack->IsEmpty())
    {
        return 0;
    }

    return (_firstStack->GetLength() + _secondStack->GetLength());  
}
