#ifndef _CIRCULARBUFFER_H_
#define _CIRCULARBUFFER_H_

#include <vector>

template <typename T>
class CircularBuffer
{
    size_t m_head, m_tail, sz;
    std::vector<T> m_buf;
public:
    CircularBuffer(int bufsz)
        : m_head(0), m_tail(0), sz(0), m_buf(std::vector<int>(bufsz))
    {
    }
    int Enqueue(T val);
    int Dequeue(T &val);
    size_t Size() const { return sz; }
    template <typename U>
    void friend Print(const CircularBuffer<U> &cb);
};

template <typename T>
int CircularBuffer<T>::Enqueue(T val)
{
    if (m_buf.size() > sz) {
        m_buf[m_head++] = val;
        m_head %= m_buf.size();
        sz++;
        return 0;
    }
    return -1;
}

template <typename T>
int CircularBuffer<T>::Dequeue(T &val)
{
    if (sz > 0) {
        val = m_buf[m_tail++];
        m_tail %= m_buf.size();
        sz--;
        return 0;
    }
    return -1;
}

template <typename T>
void Print(const CircularBuffer<T> &cb)
{
    std::cout << "size: " << cb.Size() << "\n";
    std::cout << "head: " << cb.m_head << ", tail: " << cb.m_tail << "\n";
    std::cout << "capacity: " << cb.m_buf.size() << "\n{ ";
    for (size_t i = cb.m_tail, c = 0; c < cb.Size(); i++, c++)
        std::cout << cb.m_buf[i%cb.m_buf.size()] << " ";
    printf("}\n");
}

#endif //_CIRCULARBUFFER_H_