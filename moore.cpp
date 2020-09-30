#include <iostream>
#include <string>
using namespace std;

class State
{
private:
    struct item
    {
        int value;
        State* next;
    };
    item Input1;
    item Input2;
    char m_x;
    int m_out;
public:
    State()
    {
        Input1 = {0,nullptr};
        Input2 = {0,nullptr};
        m_x = ' ';
        m_out = 0;
    }
    static State* m_ptr;
    void Initialize(item input1,item input2,char x,int out);
    static void Transition(int x);
    static void Traverse(string &str,int n);
};
State* State::m_ptr{nullptr};
void State::Initialize(item input1,item input2, char x,int out)
{
    Input1 = input1;
    Input2 = input2;
    m_x = x;
    m_out = out;
}
void State::Transition(int x)
{
    if((*m_ptr).Input1.value = x)
    {
        cout << (*m_ptr).m_out;
        m_ptr = (*m_ptr).Input1.next;
    }
    else
    {
        cout << (*m_ptr).m_out;
        m_ptr = (*m_ptr).Input2.next;
    }
}