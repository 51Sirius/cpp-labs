#ifndef CPP_SEVENTH_LAB_51SIRIUS_BUFFER_H
#define CPP_SEVENTH_LAB_51SIRIUS_BUFFER_H

#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
class Buffer {
public:
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        Iterator(T *ptr, size_t size, size_t ind) : ptr(ptr), scale(size), ind(ind) {}

        Iterator(const Iterator &other) : ptr(other.ptr), scale(other.scale), ind(other.ind) {}

        bool operator==(const Iterator &other) const {
            return ind == other.ind;
        }

        bool operator!=(const Iterator &other) const {
            return ind != other.ind;;
        }

        T &operator*() {
            return ptr[ind];
        }

        const T &operator*() const {
            return ptr[ind];
        }

        T *operator->() {
            return &ptr[ind];
        }

        Iterator &operator++() {
            ++ind;
            if (ind == scale) {
                ind = 0;
            }
            return *this;
        }

        Iterator &operator--() {
            if (ind == 0) {
                ind = scale - 1;
            } else {
                --ind;
            }
            return *this;
        }


        Iterator operator+(size_t n) {
            Iterator it(*this);
            it.ind = (it.ind + n) % it.scale;
            return it;
        }

        Iterator operator-(size_t n) {
            Iterator it(*this);
            it.ind = (it.ind + it.scale - n) % it.scale;
            return it;
        }

        size_t operator-(const Iterator &other) const {
            if (ind >= other.ind) {
                return ind - other.ind;
            } else {
                return scale - other.ind + ind;
            }
        }

        bool operator<(const Iterator &other) const {
            return *this < other;
        }

        bool operator>(const Iterator &other) const {
            return *this > other;
        }

        bool operator<=(const Iterator &other) const {
            return *this <= other;
        }

        bool operator>=(const Iterator &other) const {
            return *this >= other;
        }

        Iterator operator++(int) {
            Iterator it(*this);
            ++(*this);
            return it;
        }

        Iterator operator--(int) {
            Iterator it(*this);
            --(*this);
            return it;
        }

    private:
        T *ptr;
        size_t scale;
        size_t ind;
    };

    explicit Buffer(size_t capacity = 0) : capacite(capacity), count(0), head(0) {
        buff = new T[capacite];
    }

    Buffer(const Buffer &other) : capacite(other.capacite), count(other.count), head(other.head) {
        buff = new T[capacite];
        for (size_t i = 0; i < count; ++i) {
            buff[(head + i) % capacite] = other.buff[(other.head + i) % other.capacite];
        }
    }

    Buffer &operator=(const Buffer &other) {
        if (&other == this) return *this;
        if (capacite != other.capacite) {
            delete[] buff;
            buff = new T[other.capacite];
            capacite = other.capacite;
        }
        count = other.count;
        head = other.head;
        for (size_t i = 0; i < count; ++i) {
            buff[(head + i) % capacite] = other.buff[(other.head + i) % other.capacite];
        }
        return *this;
    }

    ~Buffer() {
        delete[] buff;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == capacite;
    }

    size_t size() const {
        return count;
    }

    size_t capacity() const {
        return capacite;
    }


    void resize(size_t new_capacity) {
        if (new_capacity == capacite) return;
        size_t new_size = (new_capacity < count) ? new_capacity : count;
        T *new_buffer = new T[new_capacity];
        for (size_t i = 0; i < new_size; ++i) {
            new_buffer[i] = buff[(head + i) % capacite];
        }
        delete[] buff;
        buff = new_buffer;
        head = 0;
        count = new_size;
        capacite = new_capacity;
    }

    const T &front() const {
        return buff[head];
    }

    const T &back() const {
        return buff[(head + count - 1) % capacite];
    }

    void push_back(const T &value) {
        if (full()) pop_front();
        buff[(head + count) % capacite] = value;
        ++count;
    }

    void pop_back() {
        if (!empty()) {
            --count;
        }
    }

    void push_front(const T &value) {
        if (full()) pop_back();
        head = (head + capacite - 1) % capacite;
        buff[head] = value;
        ++count;
    }

    void pop_front() {
        if (!empty()) {
            buff[head] = 0;
            head = (head + 1) % capacite;
            --count;
        }
    }

    Iterator insert(Iterator it, const T &value) {
        size_t offset = (it - begin()) % capacite;
        Iterator it_s = begin() + offset;
        size_t back_index = (head + count - 1) % capacite;
        while (it_s != it) {
            buff[(back_index + 1) % capacite] = buff[back_index];
            back_index = (back_index + capacite - 1) % capacite;
            --it_s;
        }
        buff[(head + offset) % capacite] = value;
        ++count;
        return Iterator(buff, capacite, (head + offset) % capacite);
    }


    Iterator erase(Iterator it) {
        size_t offset = (it - begin()) % capacite;
        Iterator it_s = begin() + offset;
        Iterator next = it_s + 1;
        while (next != end()) {
            *it_s = *next;
            ++it_s;
            ++next;
        }
        pop_back();
        return Iterator(buff, capacite, (head + offset) % capacite);
    }


    T &operator[](size_t index) {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return buff[(head + index) % capacite];
    }

    Iterator begin() {
        return Iterator(buff, capacite, head);
    }

    Iterator end() {
        return Iterator(buff, capacite, (head + count - 1) % capacite);
    }

private:
    T *buff;
    size_t capacite;
    size_t count;
    size_t head;
};


#endif