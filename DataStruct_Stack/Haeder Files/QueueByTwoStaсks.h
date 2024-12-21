#define _H_QUEUEBYTWOSTACKS_C84

#include "Stack.h"

//! \brief Очередь на двух стэках
struct QueueByTwoStacks
{
private:
    //! \brief Стэк для добавления
    Stack* _firstStack = new Stack;

    //! \brief Стэк для удаления
    Stack* _secondStack = new Stack;

public:
    //! \brief Функция инициализации очереди
    void QueueInit();

    //! \brief Добавить элемент в очередь
    //! \param data Значение, которое нужно добавить в очередь
    void PushQueue(int data);

    //! \brief Вытащить элемент из очереди
    //! \return Удалённый элемент
    int PopQueue();

    //! \brief Получить размер заполненной очереди
    //! \return Размер очереди
    int GetLengthQueue();
};
