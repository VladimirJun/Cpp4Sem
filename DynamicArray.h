#include <iosfwd>
#ifndef LAB1CPP_DYNAMICARRAY_H
#define LAB1CPP_DYNAMICARRAY_H

#endif //LAB1CPP_DYNAMICARRAY_H
class DynamicIntArray {
private:
    int *arr;
    int size;
    int capacity;

public:
    // Конструктор по умолчанию
    DynamicIntArray();

    // Конструктор по размеру(все элементы инициализируются 0)
    explicit DynamicIntArray(int size);

    DynamicIntArray(int size, int n);

    // Конструктор копирования
    DynamicIntArray(const DynamicIntArray &other);


    // Конструктор перемещения
    DynamicIntArray(DynamicIntArray &&other)  ;


    // Деструктор
    ~DynamicIntArray();

    //геттеры и сеттеры
    int * getArr();

    int getSize() const;

    //Возвращает размер резерва
    int getCapacity() const;

    // Оператор присваивания
    DynamicIntArray& operator=(const DynamicIntArray &other);
    DynamicIntArray& operator=(DynamicIntArray &&other);

    // Оператор ==
    bool operator==(const DynamicIntArray &other) const;

    // Оператор !=
    bool operator!=(const DynamicIntArray &other) const;

    // Оператор <
    bool operator<(const DynamicIntArray &other) const;

    // Оператор <=
    bool operator<=(const DynamicIntArray &other) const;

    // Оператор >
    bool operator>(const DynamicIntArray &other) const;
    // Оператор >=
    bool operator>=(const DynamicIntArray &other) const;

    // Оператор +
    DynamicIntArray operator+(const DynamicIntArray &other) const;

    //резервирование памяти
    void reserve(int n);


    // Изменение размера массива
    void resize(int newSize);

    // Добавление элемента в конец массива
    void pushBack(int x);

    // Удаление элемента с конца массива
    void popBack();

    // Доступ к элементу по индексу
    int& operator[](int index);
    // Оператор константного доступа к элементу массива
    int operator[](int index) const;

};

std::ostream &operator<<(std::ostream &os, DynamicIntArray &array);

std::istream &operator>>(std::istream &is, DynamicIntArray &arr);
