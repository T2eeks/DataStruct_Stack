#pragma once
#define __H_RINGBUFFER__F64

//! \brief Кольцевой буфер
struct RingBuffer
{
private:
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
public:

    //! \brief Конструктор для инициализации кольцевого буфера
    RingBuffer(): _data(new int[_lenght]) {}

    //! \brief Деструктор для освобождения памяти
    ~RingBuffer()
    {
        delete[] _data;
    }

    //! \brief Функция инициализации кольцевого буфера
    //! \return Указатель на массив данных буфера
    int* InitBuffer();

    //! \brief Положить значение в буфер
    //! \param data Значение, которое нужно добавить в буфер
    void Push(int data);

    //! \brief Вытащить самый старый элемент из буфера
    //! \return Удалённый элемент
    int Pop();

    //! \brief Получить указатель на массив данных
    //! \return Указатель на массив данных
    int* GetData() const;

    //! \brief Установить указатель на массив данных
    //! \param data Указатель на новый массив данных
    void SetData(int* data);

    //! \brief Получить значение индекса удаляемого элемента
    //! \return Значение _indexOut
    int GetIndexOut() const;

    //! \brief Установить индекс удаляемого элемента
    //! \param value Новое значение для _indexOut
    void SetIndexOut(int value);

    //! \brief Получить длину буфера
    //! \return Длина буфера
    int GetLength() const;

    //! \brief Получить занятое пространство буфера
    //! \return Занятое пространство буфера
    int GetOccupiedSpace() const;

    //! \brief Получить значение индекса добавляемого элемента
    //! \return Значение _indexIn
    int GetIndexIn() const;

    //! \brief Установить индекс добавляемого элемента
    //! \param value Новое значение для _indexIn
    void SetIndexIn(int value);

    //! \brief Установить занятое пространство буфера
    //! \param value Новое значение для _ocupiedSpace
    void SetOccupiedSpace(int value);

    //! \brief Получить полный размер
    //! \return Значение _fullSize
    int GetFullSize() const;

    //! \brief Установить полный размер
    //! \param value Новое значение для _fullSize
    void SetFullSize(int value);

    //! \brief Установить длину буфера
    //! \param value Новое значение для _lenght
    void SetLength(int value);

    //! \brief Положить значение в буфер
    //! \param data Значение, которое нужно добавить в буфер
    void PushToRingBuffer(int data);

    //! \brief Вытащить самый старый элемент из буфера
    //! \return Удалённый элемент
    int PopFromRingBuffer();
};
