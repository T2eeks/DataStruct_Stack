#define _H_QUEUEBYTWOSTACKS_C84

#include "Stack.h"

//! \brief Очередь на двух стэках
struct QueueByTwoStacks
{
private:
    //! \brief Стэк для добавления
    Stack* _firstStack;

    //! \brief Стэк для удаления
    Stack* _secondStack;

public:

    //! \brief Конструктор для инициализации стэков
    QueueByTwoStacks() : _firstStack(new Stack), _secondStack(new Stack) {}

    //! \brief Деструктор для освобождения памяти
    ~QueueByTwoStacks()
    {
        delete _firstStack;
        delete _secondStack;
    }

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
