#pragma once
#ifndef H_STACK_B71
#define H_STACK_B71

//! \brief Стек
struct Stack
{
    //! \brief Указатель на массив
    int* Data;

    //! \brief Фактор роста для стека
    const int GrowthFactor = 2;

    //! \brief Длина стека
    int _length = 0;

    //! \brief Вместимость стека
    int _capacity = 4;

    //! \brief Увеличивает стек
    void ResizeArray();

    //! \brief Инициализация стека
    void StackInit();

    //! \brief Проверка на пустоту
    //! \return true, если стек пуст, иначе false
    bool IsEmpty() const;

    //! \brief Положить элемент в стек
    //! \param data Значение, которое нужно добавить в стек
    void Push(int data);

    //! \brief Вытащить первый элемент
    //! \return Удалённый элемент
    int Pop();

    //! \brief Получить размер заполненного стека
    //! \return Размер стека
    int GetLength() const;
};

#endif
