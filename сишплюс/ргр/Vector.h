#pragma once

template<typename T>

class Vector 
{
private: 
    T* m_arr;
    int m_size;
    int m_capacity;

    void AddMemory();
    int Find(const T& value);
public:

    Vector();
    Vector(Vector& other);
    Vector& operator=(Vector& other);
    Vector& operator=(Vector&& other);
    ~Vector() { delete[] m_arr; }
    bool isEmpty() const { return m_size == 0; }
    int size() const { return m_size; }
    int capacity() const { return m_capacity; }
    void pushBack(const T& value);
    bool remove(const T& value);
    T& operator[](int index) { return m_arr[index];}
    const T& operator[](int index) const { return m_arr[index]; }
};

template<typename T>
int Vector<T>::Find(const T& value)
{
    int index = -1;
    for (int i = 0; i < m_size; i++)
        if (m_arr[i] == value)
            index = i;
    return index;
}

template<typename T>
void Vector<T>::AddMemory()
{
    m_capacity *= 2;
    T* tmp = m_arr;
    m_arr = new T[m_capacity];
    for (int i = 0; i < m_size; ++i)
        m_arr[i] = tmp[i];
    delete[] tmp;
}

template<typename T>
Vector<T>::Vector()
{
    m_arr = new T[1];
    m_capacity = 1;
}

template<typename T>
Vector<T>::Vector(Vector& other)
{
    if (this != &other)
    {
        delete[] m_arr;
        m_arr = other.m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_arr = nullptr;
        other.m_size = other.m_capacity = 0;
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>& other)
{
    if (this != &other)
    {
        delete[] m_arr;
        m_arr = other.m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_arr = nullptr;
        other.m_size = other.m_capacity = 0;
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
    if (this != &other)
    {
        delete[] m_arr;
        m_arr = other.m_arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_arr = nullptr;
        other.m_size = other.m_capacity = 0;
    }
    return *this;
}

template<typename T>
void Vector<T>:: pushBack(const T& value)
{
    if (m_size >= m_capacity)
        AddMemory();
    m_arr[m_size++] = value;
}

template<typename T>
bool Vector<T>::remove(const T& value)
{
    int index = Find(value);
    if (index != 1)
    {
        for (int i = index + 1; i < m_size; ++i)
            m_arr[i - 1] = m_arr[i];
        --m_size;
        return 1;
    }
    
    return 0;   
}