//This is a programmic approach to Finite Automata with Output
//The given code represents a Moore Machine that prints 2's complement of a given binary number 
//The states in the automata are represented as objects of the type class State

#include <bits/stdc++.h> 
using namespace std; 
  
// Define a class named State 
class State { 
private: 
    struct item { 
        char value; 
        State* next; 
    }; 
    item Input1; 
    item Input2; 
    char m_out; 
  
public: 
    // Constructors 
    State() 
        : Input1{ ' ', nullptr }, 
          Input2{ ' ', nullptr }, 
          m_out{ ' ' } 
    { 
    } 
    static State* m_ptr; 
  
    // Member Functions 
    void Initialize(item input1, 
                    item input2, 
                    char out); 
    static char Transition(char x); 
    static string Traverse(string& str, 
                           int n); 
}; 
  
// Global object pointer points to 
// current state 
State* State::m_ptr{ nullptr }; 
  
// Function that initializes the states 
// with appropriate values 
void State::Initialize(item input1, 
                       item input2, 
                       char out) 
{ 
    Input1 = input1; 
    Input2 = input2; 
    m_out = out; 
} 
  
// Transition function takes each 
// character of string 
char State::Transition(char x) 
{ 
    char ch{}; 
  
    // Prints the output 
    if ((*m_ptr).Input1.value == x) { 
  
        // Output the current state 
        cout << (*m_ptr).m_out; 
        ch = (*m_ptr).m_out; 
  
        // Next input state 
        m_ptr = (*m_ptr).Input1.next; 
    } 
    else { 
  
        // Output the current state 
        cout << (*m_ptr).m_out; 
        ch = (*m_ptr).m_out; 
  
        // Next input state 
        m_ptr = (*m_ptr).Input2.next; 
    } 
  
    // Return ch 
    return ch; 
} 
  
// Takes the whole string and passes 
// through machine 
string State::Traverse(string& str, int n) 
{ 
    string str1{}; 
  
    // Add all the transition state to 
    // the string str1 
    for (int i = n - 1; i >= 0; i--) { 
        str1 += Transition(str[i]); 
    } 
  
    // To read the characters from end 
    // therefore we need to reverse 
    reverse(str1.begin(), str1.end()); 
  
    return str1; 
} 
  
// Function to create states and 
// produce output 
string mooreOut(string str, int n) 
{ 
    State q1, q2, q3; 
  
    // Initializing the states 
    q1.Initialize({ '0', &q1 }, 
                  { '1', &q2 }, '0'); 
    q2.Initialize({ '0', &q2 }, 
                  { '1', &q3 }, '1'); 
    q3.Initialize({ '0', &q2 }, 
                  { '1', &q3 }, '0'); 
    State::m_ptr = &q1; 
    return State::Traverse(str, n); 
} 
  
// Driver Code 
int main() 
{ 
    // Given string 
    string str{ "111010000" }; 
    int n{ static_cast<int>(str.length()) }; 
  
    // Function Call 
    string str1{ mooreOut(str, n) }; 
  
    // Print the output 
    cout << "2's complement: " << str1; 
    return 0; 
} 
