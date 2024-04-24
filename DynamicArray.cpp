#include <iostream>
#include <cassert>
#include <exception>
#include "DynamicArray.h"

//инициализирую пустой массив длины по умолчанию (1)
DynamicIntArray::DynamicIntArray(){
    try {
        size=1;
        capacity= size * 2;
        arr = new int[size + capacity];
        arr[0] = 1;
    } catch (const std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

//массив длины s, все элементы инициализируются 0
DynamicIntArray::DynamicIntArray(int s) {
    assert(s > 0 && "Size must be positive");
    try {
        size = s;
        capacity = s * 2;
        arr = new int[size + capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

//массив длины s, все элементы инициализируются n
DynamicIntArray::DynamicIntArray(int s, int n) {
    assert(s > 0 && "Size must be positive");
    try {
        size = s;
        capacity = s * 2;
        arr = new int[size + capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

// Конструктор копирования
DynamicIntArray::DynamicIntArray(const DynamicIntArray &other) {

    assert(&other != nullptr && "Other array must exist");
    try {
        size = other.size;
        capacity = other.capacity;
        arr = new int[size + capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}


// Конструктор перемещения
DynamicIntArray::DynamicIntArray(DynamicIntArray &&other) {
    assert(&other != nullptr && "Other array must exist");
    size = other.size;
    arr = other.arr;
    capacity = other.capacity;
    other.arr = nullptr;
}


// Деструктор
DynamicIntArray::~DynamicIntArray() {
    delete[] arr;
}

//Возвращает размер резерва
int DynamicIntArray::getCapacity() const {
    return capacity;
}


// Оператор присваивания
DynamicIntArray &DynamicIntArray::operator=(const DynamicIntArray &other) {
    assert(&other != nullptr && "Array to move must exist");
    try {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new int[size + capacity];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
    return *this; //указатель на текущий объект данного класса (присвоенный)
}

DynamicIntArray &DynamicIntArray::operator=(DynamicIntArray &&other) {
    assert(&other != nullptr && "Array to move must exist");
    try {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new int[size + capacity];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
            size = other.size;
            arr = other.arr;
            capacity = other.capacity;
            other.arr = nullptr;
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
    return *this; //указатель на текущий объект данного класса (присвоенный)
}


// Оператор ==
bool DynamicIntArray::operator==(const DynamicIntArray &other) const {
    if (&other == nullptr) return false;
    if (size != other.size) {
        throw std::invalid_argument("Arrays must have equal lengths");
    }
    for (int i = 0; i < size; ++i) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
}

// Оператор !=
bool DynamicIntArray::operator!=(const DynamicIntArray &other) const {
    assert(&other != nullptr && "Other array should exist");
    return !(*this == other);
}

// Оператор <
bool DynamicIntArray::operator<(const DynamicIntArray &other) const {
    assert(&other != nullptr && "Other array should exist");
    for (int i = 0; i < std::min(size,other.size); ++i) {
        if (arr[i] < other.arr[i]) {
            return true;
        } else if (arr[i] >= other.arr[i]) {
            return false;
        }
    }
}

// Оператор <=
bool DynamicIntArray::operator<=(const DynamicIntArray &other) const {
    assert(&other != nullptr && "Other array should exist");
    if (size!=other.size){ return size<other.size;
    }else return (*this==other||*this<other);
}

// Оператор >
bool DynamicIntArray::operator>(const DynamicIntArray &other) const {
    assert(&other != nullptr && "Other array should exist");
    return !(*this < other);

}

// Оператор >=
bool DynamicIntArray::operator>=(const DynamicIntArray &other) const {
    assert(&other == nullptr && "Other array should exist");
    return !(*this < other) || (*this == other);
}

// Оператор +
DynamicIntArray DynamicIntArray::operator+(const DynamicIntArray &other) const {
    assert(&other != nullptr && "Other array should exist");
    try {
        DynamicIntArray result(size + other.size);

        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i];
        }

        for (int i = 0; i < other.size; ++i) {
            result.arr[size + i] = other.arr[i];
        }

        return result;
    }
    catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

//резервирование памяти
void DynamicIntArray::reserve(int n) {
    assert(n > 0 && "Size of reserve must be positive");
    if (n == capacity) {
        return;
    }
    try {
        const int newCapacity = n;
        int *new_arr = new int[size + newCapacity];
        std::copy(arr, arr + size, new_arr);
        delete[] arr;
        arr = new_arr;
        capacity = newCapacity;
    }
    catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw e;
    }
}


// Изменение размера массива
void DynamicIntArray::resize(int newSize) {
    assert(newSize > 0 && "Size should be positive");
    try {
        if (newSize == size) {
            return;
        }
        if (newSize > capacity + size) {
            reserve(2 * newSize);
            for (int i = size; i < newSize; i++) {
                arr[i] = 0;
            }
            size = newSize;
        } else {
            size = newSize;
        }
    } catch (std::bad_alloc &e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw std::bad_alloc();
    }
}


// Добавление элемента в конец массива
void DynamicIntArray::pushBack(int x) {
    if (capacity == 0) {
        reserve(size * 2);
    }
    arr[size] = x;
    size++;
    capacity--;

}

// Удаление элемента с конца массива
void DynamicIntArray::popBack() {
    if (size > 0) {
        size--;
    }
}


// Доступ к элементу по индексу
int &DynamicIntArray::operator[](int index) {
    assert(size >= index && "Index must be less than size");
    assert(index >= 0 && "Index must be positive");
    return arr[index];
}

// Оператор константного доступа к элементу массива
int DynamicIntArray::operator[](int index) const {
    assert(size >= index && "Index must be less than size");
    assert(index >= 0 && "Index must be positive");
    return arr[index];
}

int *DynamicIntArray::getArr() {
    assert(arr != nullptr && "Array must exist");
    return arr;
}

int DynamicIntArray::getSize() const {
    return size;
}


std::ostream &operator<<(std::ostream &os, DynamicIntArray &array) {
    for (int i = 0; i < array.getSize(); i++) {
        os << array[i] << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, DynamicIntArray &arr) {
    assert(&arr != nullptr && "Array must exist");
    for (int i = 0; i < arr.getSize(); i++) {
        int v = arr[i];
        is >> v;
    }
    return is;
}

