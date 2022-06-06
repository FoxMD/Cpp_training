#include <iostream>

template<typename T>
class Stack
{
    T m_Buffer[512];
    int m_Top{-1};
    public:
        void Push(const T &elem)
        {
            m_Buffer[++m_Top] = elem;
        }
        void Pop()
        {
            --m_Top;
        }
        const T& Top()const
        {
            return m_Buffer[m_Top];
        }
        bool IsEmpty()
        {
            return m_Top == -1;
        }
};

int main()
{
    Stack<int> s;
    s.Push(3);
    s.Push(6);
    s.Push(9);

    while (!s.IsEmpty())
    {
        std::cout << s.Top() << " ";
        s.Pop();
    }
    
    return 0;
}