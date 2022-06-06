#include <iostream>

template<typename T, int size>
class Stack
{
    T m_Buffer[size];
    int m_Top{-1};
    public:
        Stack() = default;
        Stack(const Stack &obj) // copy constructor
        {
            m_Top = obj.m_Top;
            for(int i = 0; i <= m_Top; ++i)
            {
                m_Buffer[i] = obj.m_Buffer[i];
            }
        }
        void Push(const T &elem)
        {
            m_Buffer[++m_Top] = elem;
        }
        const T& Top()const
        {
            return m_Buffer[m_Top];
        }
        bool IsEmpty()
        {
            return m_Top == -1;
        }
        static Stack Create()
        {
            return Stack<T, size>();
        }

        void Pop();
};

template<typename T, int size>
void Stack<T, size>::Pop()
{
    --m_Top;
}

int main()
{
    Stack<int, 512> s;
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