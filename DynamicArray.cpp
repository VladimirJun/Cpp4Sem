#include <iostream>
#include <cassert>

class DynamicIntArray {
private:
    int *arr;
    int size;
    int reserveSize{};


public:
    // Конструктор по умолчанию
    DynamicIntArray() : arr(nullptr), size(0), reserveSize(0) {}

    // Конструктор по размеру(все элементы инициализируются 0)
    explicit DynamicIntArray(int size) : size(size) {
        assert(size > 0 && "Size must be positive");
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    DynamicIntArray(int size, int n) {
        assert(size > 0 && "Size must be positive");
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }

    //Конструктор по размеру, позволяющий задать размер резерва массива, все элементы инициализируются значением value
    DynamicIntArray(int n, int value, int reserveSize) : size(n), reserveSize(reserveSize) {
        arr = new int[size + reserveSize];
        for (int i = 0; i < size + reserveSize; i++) {
            arr[i] = value;
        }
    }

    // Конструктор копирования
    DynamicIntArray(const DynamicIntArray &other) : size(other.size), reserveSize(other.reserveSize) {
        arr = new int[size + reserveSize];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }


    // Конструктор перемещения
    DynamicIntArray(DynamicIntArray &&other) noexcept: arr(other.arr), size(other.size),
                                                       reserveSize(other.reserveSize) {
        other.arr = nullptr;
        other.size = 0;
        other.reserveSize = 0;
    }

    // Деструктор
    ~DynamicIntArray() {
        delete[] arr;
    }

    //геттеры и сеттеры
    int *getArr() const {
        return arr;
    }

    int getSize() const {
        return size;
    }

    //Возвращает размер резерва
    int capacity() const {
        return reserveSize;
    }

    // Возвращает общий размер памяти
    int getReservedMemory() const {
        return size + reserveSize;
    }


    // Доступ к элементу по индексу
    int &operator[](int index) {
        assert(index <= size);
        return arr[index];
    }

    // Оператор присваивания
    DynamicIntArray &operator=(const DynamicIntArray &other) {
        assert(&other != nullptr && "Array to move must exist");
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new int[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this; //указатель на текущий объект данного класса (присвоенный)
    }

    // Оператор ==
    bool operator==(const DynamicIntArray &other) const {
        assert(size == other.size && "Arrays must have equal lengths");
        for (int i = 0; i < size; ++i) {
            if (arr[i] != other.arr[i]) {
                return false;
            }
        }
        return true;
    }

    // Оператор !=
    bool operator!=(const DynamicIntArray &other) const {
        assert(&other == nullptr && "Other array should exist");
        return !(*this == other);
    }

    // Оператор <
    bool operator<(const DynamicIntArray &other) const {
        assert(&other == nullptr && "Other array should exist");
        return std::lexicographical_compare(arr, arr + size, other.arr, other.arr + other.size);

    }

    // Оператор <=
    bool operator<=(const DynamicIntArray &other) const {
        assert(&other != nullptr && "Other array should exist");
        return *this < other || *this == other;
    }

    // Оператор >
    bool operator>(const DynamicIntArray &other) const {
        assert(&other != nullptr && "Other array should exist");
        return !(*this > other);
    }

    // Оператор >=
    bool operator>=(const DynamicIntArray &other) const {
        assert(&other == nullptr && "Other array should exist");
        return !(*this >= other);
    }

    // Оператор +
    DynamicIntArray operator+(const DynamicIntArray &other) const {
        assert(&other != nullptr && "Other array should exist");
        DynamicIntArray result(size + other.size);

        for (int i = 0; i < size; ++i) {
            result.arr[i] = arr[i];
        }

        for (int i = 0; i < other.size; ++i) {
            result.arr[size + i] = other.arr[i];
        }

        return result;
    }

    //резервирование памяти
    void reserve(int n) {
        int *newArr = new int[size + n];
        for (int i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        reserveSize = n;
    }


    // Изменение размера массива
    void resize(int newSize) {
        if (newSize <= size) {
            size = newSize;
        } else {
            reserve(newSize - size);
            for (int i = size; i < newSize; ++i) {
                arr[i] = 0;
            }
            size = newSize;
        }
    }

    // Добавление элемента в конец массива
    void pushBack(int x) {
        resize(size + 1);
        arr[size - 1] = x;
    }

    // Удаление элемента с конца массива
    void popBack() {
        if (size > 0) {
            arr[size - 1];
            size--;
        }
    }

    // Оператор доступа к элементу массива
    int &getElemFromIndex(int index) {
        return arr[index];
    }

    // Оператор константного доступа к элементу массива
    const int &operator[](int index) const {
        return arr[index];
    }

};

inline std::ostream &operator<<(std::ostream &os, const DynamicIntArray &array) {
    return os << "arr: " << array.getArr() << " size: " << array.getSize() << " reserveSize: "
              << array.getReservedMemory();
}

inline std::istream &operator>>(std::istream &in, DynamicIntArray &arr) {
    for (int i = 0; i < arr.getSize(); ++i) {
        in >> arr.getElemFromIndex(i);
    }
    return in;
}
