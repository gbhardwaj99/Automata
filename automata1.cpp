//DFA to accept strings ending with the string 'aabb'
#include <iostream>
#include <string>
using namespace std;

// This class provides the functionality for automata
class State
{
private:
    pair<char,State*> Pair1;
    pair<char,State*> Pair2;
    char m_x;
public:
    State()
    {
        Pair1 = {' ',nullptr};
        Pair2 = {' ',nullptr};
        m_x = ' ';
    }
    void initialize(pair<char, State*> pair1, pair<char, State*> pair2, char x)
    {
        Pair1 = pair1;
        Pair2 = pair2;
        m_x = x;
    }
    static State *m_ptr;
    static void transition(char input);
    static bool check();
};
// This pointer points to the current state of the automata
State* State::m_ptr{nullptr};
// This function provided state transition of automata
void State::transition(char input)
{
    if((*m_ptr).Pair1.first == input)
        m_ptr = (*m_ptr).Pair1.second;
    else
        m_ptr = (*m_ptr).Pair2.second;
}
// Checks if the last state if final state or not
bool State::check()
{
    if((*m_ptr).m_x == 'f')
        return true;
    else 
        return false;
}
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin,str);
    State one,two,three,four,five;
    // A Transition table of sorts for the required automata
    one.initialize({'a',&two},{'b',&one},'i');
    two.initialize({'a',&three},{'b',&one},'i');
    three.initialize({'a',&three},{'b',&four},'i');
    four.initialize({'a',&two},{'b',&five},'i');
    five.initialize({'a',&two},{'b',&one},'f');
    State::m_ptr = &one;
    int length{static_cast<int>(str.length())};
    for(int i=0;i<length;i++)
    {
        char ch = str[i];
        State::transition(ch);
    }
    if(State::check())
        cout << "String Accepted!" << endl;
    else
        cout << "String Rejected" << endl;
    return 0;
}