#ifndef __H_MENU_A42
#define __H_MENU_A42
#include "Common.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "QueueByRingBuffer.h"
#include "QueueByTwoSta�ks.h"

//! \brief ������� ��������� ����
//! \return ����� ��������� ���������
int ChooseStruct();

//! \brief ���� ��� ������ �� ������
//! \param stack ��������� �� ����
void StackMenu(Stack& stack);

//! \brief ���� ��� ������ � ��������� �������
//! \param ringBuffer ��������� �� ��������� �����
void RingBufferMenu(RingBuffer& ringBuffer);

//! \brief ���� ��� ������ � �������� �� ��������� ������
//! \param queueByRingBuffer ��������� �� �������
void QueueRingBufferMenu(QueueByRingBuffer& queueByRingBuffer);

//! \brief ���� ��� ������ � �������� �� ���� ������
//! \param TwoStacksQueue ��������� �� �������
void TwoStacksQueueMenu(QueueByTwoStacks& TwoStacksQueue);

#endif
