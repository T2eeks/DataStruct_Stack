#pragma once
#define _H_QUEUEBYRINGBUFFER_D005

#include "RingBuffer.h"

//! \brief ���������, �������������� ������� �� ��������� ������
struct QueueByRingBuffer
{
private:
    // TODO: ������� private ��� public
    //! \brief ��������� �� ���������� ��������� �����
    RingBuffer* _queueByRingBuffer = new RingBuffer;

public:
    //! \brief ������� ������������� �������
    //! \return ��������� �� ������ ������ �������
    int* InitQueue();

    //! \brief ��������� �������� � �������
    //! \param data ��������, ������� ����� ��������
    void PushInQueue(int data);

    //! \brief ��������� ����� ������ ������� �� �������
    //! \return �������� �������
    int PopInQueue();

    //! \brief �������� ������ ������� (���������� RingBuffer)
    //! \param ringBuffer ��������� �� �����, �� �������� ����������� �������
    //! \return �������� �������
    int Pop(RingBuffer* ringBuffer);

    //! \brief ����������� �����
    //! \param ringBuffer ��������� �� �����, ������� ����� ���������
    void ResizeBuffer(RingBuffer* ringBuffer);

    //! \brief ���������, ����� �� �������
    //! \return true, ���� ������� �����, ����� false
    bool IsEmptyQueue();

    //! \brief ���������� ��������� �� �����
    //! \return ��������� �� ���������� �����
    RingBuffer* GetQueueByRingBuffer() const;
    ;
};
