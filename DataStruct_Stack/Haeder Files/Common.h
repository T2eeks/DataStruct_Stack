#pragma once
#ifndef _H_COMMON_E88
#define _H_COMMON_E88

#include "RingBuffer.h"
#include "QueueByRingBuffer.h"

//! \brief Класс, содержащий общие функции
class Common
{
public:
    //! \brief Функция для получения корректного значения от пользователя
    //! \return Корректное значение, введенное пользователем
    static int GetValue();

    //! \brief Отображает свободное место в кольцевом буфере
    //! \param ringBuffer Ссылка на кольцевой буфер, в котором отображается свободное место
    static void ShowSpace(const RingBuffer& ringBuffer);

    //! \brief Отображает свободное место в очереди на кольцевом буфере
    //! \param queueByRingBuffer Ссылка на очередь на кольцевом буфере, в которой отображается свободное место
    static void ShowSpaceQueue(const QueueByRingBuffer& queueByRingBuffer);

    //! \brief Выводит содержимое кольцевого буфера
    //! \param ringBuffer Ссылка на кольцевой буфер для вывода
    static void PrintBuffer(const RingBuffer& ringBuffer);

    //! \brief Выводит содержимое очереди на кольцевом буфере
    //! \param queueByRingBuffer Ссылка на очередь для вывода
    static void PrintQueue(const QueueByRingBuffer& queueByRingBuffer);
};

#endif
