#pragma once
#define _H_QUEUEBYRINGBUFFER_D005

#include "RingBuffer.h"

//! \brief Структура, представляющая очередь на кольцевом буфере
struct QueueByRingBuffer
{
private:
    // TODO: сделать private или public
    //! \brief Указатель на внутренний кольцевой буфер
    RingBuffer* _queueByRingBuffer;

public:
    //! \brief Конструктор для инициализации кольцевого буфера
    QueueByRingBuffer(): _queueByRingBuffer(new RingBuffer) {}

    //! \brief Деструктор для освобождения памяти
    ~QueueByRingBuffer()
    {
        delete _queueByRingBuffer;
    }

    //! \brief Функция инициализации очереди
    //! \return Указатель на массив данных очереди
    int* InitQueue();

    //! \brief Добавляет значение в очередь
    //! \param data Значение, которое нужно добавить
    void PushInQueue(int data);

    //! \brief Извлекает самый старый элемент из очереди
    //! \return Удалённый элемент
    int PopInQueue();

    //! \brief Вытащить первый элемент (использует RingBuffer)
    //! \param ringBuffer Указатель на буфер, из которого извлекается элемент
    //! \return Удалённый элемент
    int Pop(RingBuffer* ringBuffer);

    //! \brief Увеличивает буфер
    //! \param ringBuffer Указатель на буфер, который нужно увеличить
    void ResizeBuffer(RingBuffer* ringBuffer);

    //! \brief Проверяет, пуста ли очередь
    //! \return true, если очередь пуста, иначе false
    bool IsEmptyQueue();

    //! \brief Возвращает указатель на буфер
    //! \return Указатель на внутренний буфер
    RingBuffer* GetQueueByRingBuffer() const;
};
