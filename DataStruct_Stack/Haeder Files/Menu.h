#ifndef __H_MENU_A42
#define __H_MENU_A42
#include "Common.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueByRingBuffer.h"
#include "QueueByTwoStaсks.h"

//! \brief Функция основного меню
//! \return Номер выбранной структуры
int ChooseStruct();

//! \brief Меню для работы со стеком
//! \param stack Указатель на стек
void StackMenu(Stack& stack);

//! \brief Меню для работы с очередью на кольцевом буфере
//! \param queueByRingBuffer Указатель на очередь
void RingBufferMenu(RingBuffer& ringBuffer);

//! \brief Меню для работы с очередью на кольцевом буфере
//! \param queueByRingBuffer указатель на очередь
void QueueRingBufferMenu(QueueByRingBuffer& queueByRingBuffer);

//! \brief Меню для работы с очередью на двух стеках
//! \param TwoStacksQueue Указатель на очередь
void TwoStacksQueueMenu(QueueByTwoStacks& TwoStacksQueue);

#endif
