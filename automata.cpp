
//This is a programmic approach to Finite Automatas
//The given code represents a DFA that accepts all string ending with '01'
//The states in the automata are representd as objects of the type class State

#include <iostream>
#include <string>
using namespace std;

// This class provides the functionality for automata
class State
{
private:
    pair<int,State*> Pair1;
    pair<int,State*> Pair2;
    char m_x;
public:
    static State *m_ptr;
    State()
    {
        Pair1.first = 0;
        Pair1.second = nullptr;
        Pair2.first = 0;
        Pair2.second = nullptr;
        m_x = ' ';
   }
   void initialize(pair<int,State*> pair1,pair<int,State*> pair2,char x)
   {
       Pair1 = pair1;
       Pair2 = pair2;
       m_x = x;
   }
   static void transition(int input);
   static void traverse(string &str,int n);
   static void check();
};
// This pointer points to the current state of the automata
State* State::m_ptr{nullptr};
// This function provided state transition of automata
void State::transition(int input)
{
    if((*m_ptr).Pair1.first == input)
        m_ptr = (*m_ptr).Pair1.second;
    else
        m_ptr = (*m_ptr).Pair2.second;
}
// Checks if the last state is final state or not
void State::check()
{
    if ((*m_ptr).m_x == 'f')
        cout << "String Accepted\n" << endl;
    else
        cout << "String Rejected\n" << endl;
}
void State::traverse(string &str,int n)
{
    for(int i=0;i<n;i++)
    {
        int x{(int)str[i] - (int)'0'};
        transition(x);
    }
}
int main()
{
    string str{"00111111"};
    State one,two,three;
    // A Transition table of sorts for the required automata
    one.initialize({0,&two},{1,&one},'i');
    two.initialize({0,&two},{1,&three},'i');
    three.initialize({0,&two},{1,&one},'f');
    int length{static_cast<int>(str.length())};
    State::m_ptr = &one;
    State::traverse(str,length);
    State::check();
}
