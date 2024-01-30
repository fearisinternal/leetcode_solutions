class MyQueue
{
private:
    std::stack<int> s, rs;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        if (rs.empty())
        {
            s.push(x);
        }
        else
        {
            while (!rs.empty())
            {
                s.push(rs.top());
                rs.pop();
            }
            s.push(x);
        }
    }

    int pop()
    {
        auto temp = peek();
        rs.pop();
        return temp;
    }

    int peek()
    {
        if (rs.empty())
        {
            while (!s.empty())
            {
                rs.push(s.top());
                s.pop();
            }
        }
        auto temp = rs.top();
        return temp;
    }

    bool empty()
    {
        return s.empty() && rs.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */