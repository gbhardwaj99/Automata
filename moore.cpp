// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Define a class named State 
class State { 
private: 
	// Item 
	struct item { 
		char value; 
		State* next; 
	}; 

	// Three states 
	item Input1; 
	item Input2; 
	char m_out; 

public: 
	// Constructor 
	State() 
		: Input1{ ' ', nullptr }, 
		Input2{ ' ', nullptr }, 
		m_out{ ' ' } 
	{ 
	} 

	// Member functions 
	static State* m_ptr; 
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

// Transition function that takes each 
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

// Takes the whole string and pass 
// it through machine 
string State::Traverse(string& str, 
					int n) 
{ 
	string str1{}; 

	// Add all the transition state to 
	// the string str1 
	for (int i = 0; i < n; i++) 
		str1 += Transition(str[i]); 

	// Append output 
	str1 += (*m_ptr).m_out; 
	cout << (*m_ptr).m_out << endl; 

	// Return str1 
	return str1; 
} 

// Function that create states and 
// produce output 
string mooreOut(string str, int n) 
{ 
	State q1, q2, q3, q4; 

	// Initializing the states 
	q1.Initialize({ 'a', &q2 }, 
				{ 'b', &q1 }, '0'); 
	q2.Initialize({ 'a', &q2 }, 
				{ 'b', &q3 }, '0'); 
	q3.Initialize({ 'a', &q2 }, 
				{ 'b', &q4 }, '0'); 
	q4.Initialize({ 'a', &q2 }, 
				{ 'b', &q1 }, '1'); 
	State::m_ptr = &q1; 

	// Traverse the string str1 
	string str1{ State::Traverse(str, n) }; 
	return str1; 
} 

// Function that counts the occurences 
// of 1 in the output string 
int countStr(string& str, int n) 
{ 
	int count{}; 

	// Count the 1s in str 
	for (int i = 0; i < n; i++) { 
		if (str[i] == '1') 
			count++; 
	} 

	// Return count 
	return count; 
} 

// Driver Code 
int main() 
{ 

	// Given string 
	string str{ "babbabbabbb" }; 

	int n{ static_cast<int>(str.length()) }; 

	// Function Call 
	string str1{ mooreOut(str, n) }; 
	int n1{ static_cast<int>(str.length()) }; 

	// Print the count of substring 
	cout << "abb occurs " << countStr(str1, n1) 
		<< " times\n"; 
	return 0; 
} 
