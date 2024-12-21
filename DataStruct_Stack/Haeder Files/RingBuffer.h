#pragma once
#define __H_RINGBUFFER__F64

//! \brief Кольцевой буфер
struct RingBuffer
{
    //! \brief Указатель на массив
    int* _data;

    //! \brief Индекс добавляемого элемента
    int _indexIn = 0;

    //! \brief Индекс удаляемого элемента
    int _indexOut = 0;

    //! \brief Длина буфера
    int _lenght = 8;

    //! \brief Занятое пространство 
    int _ocupiedSpace = 0;

    //! \brief Полный размер
    int _fullSize = 0;

    //! \brief Функция инициализации кольцевого буфера
    //! \return Указатель на массив данных буфера
    int* InitBuffer();

    //! \brief Положить значение в буфер
    //! \param data Значение, которое нужно добавить в буфер
    void Push(int data);

    //! \brief Вытащить самый старый элемент из буфера
    //! \return Удалённый элемент
    int Pop();

    //! \brief Получить длину буфера
    //! \return Длина буфера
    int GetLength() const;

    //! \brief Получить занятое пространство буфера
    //! \return Занятое пространство буфера
    int GetOccupiedSpace() const;

    //! \brief Положить значение в буфер
    //! \param data Значение, которое нужно добавить в буфер
    void PushToRingBuffer(int data);

    //! \brief Вытащить самый старый элемент из буфера
    //! \return Удалённый элемент
    int PopFromRingBuffer();
};
