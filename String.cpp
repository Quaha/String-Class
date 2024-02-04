#include "stdafx.h"
#include "String.h"

// --------------- Constructors ---------------

// Constructor of an empty String object.
String::String() {
	size_of_string = 0;
	string_ptr = new char[1];
	string_ptr[0] = '\n';
}

// Constructor of an empty String object of length N.
String::String(int N) {
	size_of_string = N;
	string_ptr = new char[N + 1];
	string_ptr[N] = '\0';
}

// Constructor of a String object of length N filled with the char C.
String::String(int N, char C) {
	size_of_string = N;
	string_ptr = new char[N + 1];
	for (int i = 0; i < N; i++) {
		string_ptr[i] = C;
	}
	string_ptr[N] = '\0';
}

// Constructor of a String object of length N the beginning of which is the String S.
// The end of a String object can be empty (filled with uninitialized elements).
String::String(int N, const String& S) {
	size_of_string = N;
	string_ptr = new char[size_of_string + 1];
	for (int i = 0; i < size_of_string && i < S.size(); i++) {
		string_ptr[i] = S[i];
	}
	string_ptr[size_of_string] = '\0';
}

// A String object which created based on the String S.
String::String(const char* S) {
	size_of_string = 0;
	while (S[size_of_string] != '\0') {
		size_of_string++;
	}
	string_ptr = new char[size_of_string + 1];
	for (int i = 0; i < size_of_string; i++) {
		string_ptr[i] = S[i];
	}
	string_ptr[size_of_string] = '\0';
}

// --------------- Copy Constructor ---------------

String::String(const String& S) {
	delete[] string_ptr;
	size_of_string = S.size();
	string_ptr = new char[size_of_string + 1];
	for (int i = 0; i < size_of_string; i++) {
		string_ptr[i] = S[i];
	}
	string_ptr[size_of_string] = '\0';
}

// --------------- Destructor ---------------

String::~String() {
	delete[] string_ptr;
}

// --------------- Conversion operators ---------------

String String::operator =(const String& S) {
	delete[] string_ptr;
	size_of_string = S.size();
	string_ptr = new char[size_of_string + 1];
	for (int i = 0; i < size_of_string; i++) {
		string_ptr[i] = S[i];
	}
	string_ptr[size_of_string] = '\0';
	return S;
}

// String concatenation operator #1:
// This operator creates a char* of length |S1| + |S2|,
// copies Strings S1 and S2 there, then clears String S1
// and writes char* and the new length to it.
void String::operator +=(const String& S) {
	int new_size = size_of_string + S.size();
	char* temp = new char[new_size + 1];
	for (int i = 0; i < size_of_string; i++) {
		temp[i] = string_ptr[i];
	}
	for (int i = size_of_string; i < new_size; i++) {
		temp[i] = S[i - size_of_string];
	}
	temp[new_size] = '\0';
	delete[] string_ptr;
	string_ptr = temp;
	size_of_string = new_size;
}

// String concatenation operator #2:
// This operator creates a new String object of length |S1| + |S2|,
// copies Strings S1 and S2 there, then returns the String object.
String String::operator +(const String& S) const {
	int new_size = size_of_string + S.size_of_string;
	String temp(new_size);
	for (int i = 0; i < size_of_string; i++) {
		temp[i] = string_ptr[i];
	}
	for (int i = size_of_string; i < new_size; i++) {
		temp[i] = S[i - size_of_string];
	}
	return temp;
}

// String operator #1 for multiplying a String by a number:
// This operator creates a char* of length |S1| * N,
// copies Strings S there N times, then clears String S1
void String::operator *=(int N) {
	int new_size = size_of_string * N;
	char* temp = new char[new_size + 1];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size_of_string; j++) {
			temp[i * size_of_string + j] = string_ptr[j];
		}
	}
	temp[new_size] = '\0';
	delete[] string_ptr;
	string_ptr = temp;
	size_of_string = new_size;
}


// String operator #2 for multiplying a String by a number:
// This operator creates a new String object of length |S1| * N,
// copies Strings S1 there N times, then returns the String object.
String String::operator*(int N) const {
	String temp(size_of_string * N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size_of_string; j++) {
			temp[i * size_of_string + j] = string_ptr[j];
		}
	}
	return temp;
}

// String operator #3 for multiplying a number by a String:
// This operator creates a new String object of length |S1| * N,
// copies strings S1 there N times, then returns the String object.
String operator*(int N, const String& S) {
	String temp(S.size() * N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < S.size(); j++) {
			temp[i * S.size() + j] = S.string_ptr[j];
		}
	}
	return temp;
}

// --------------- Conversion operators ---------------

// String comparison operators are implemented in this code block. 
// All operators except < and == are implemented based on them, 
// so you can change the comparator by changing the overload of the < operator.

bool operator==(const String& S1, const String& S2){
	if (S1.size() != S2.size()) {
		return false;
	}
	for (int i = 0; i < S1.size(); i++) {
		if (S1[i] != S2[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const String& S1, const String& S2) {
	return !(S1 == S2);
}

bool operator <(const String& S1, const String& S2) {
	int i = 0;
	for (i; i < S1.size() && i < S2.size(); i++) {
		if (S1[i] < S2[i]) {
			return true;
		}
		if (S1[i] > S2[i]) {
			return false;
		}
	}
	return S1.size() < S2.size();
}

bool operator >(const String& S1, const String& S2) {
	return S2 < S1;
}

bool operator <=(const String& S1, const String& S2) {
	return (S1 < S2 || S1 == S2);
}

bool operator >=(const String& S1, const String& S2) {
	return S2 <= S1;
}

// --------------- Input, output and conversion operators ---------------

std::ostream& operator<< (std::ostream& out, const String &S) {
	for (int i = 0; i < S.size_of_string; i++) {
		out << S[i];
	}
	return out;
}

std::istream& operator>> (std::istream& in, String& S) {
	S.clear();
	int gsize = 1;
	int i = 0;
	S = String(gsize);
	while (in.get(S[i])) {
		i++;
		if (i == gsize) {
			gsize *= 2;
			String temp(gsize, S);
			S = temp;
		}
		if (S[i - 1] == '\n') {
			break;
		}
	}
	S[i - 1] = '\0';
	S.size_of_string = i;
	return in;
}

// String assignment operator by index:
// This operator allows you to change the value of the i-th character of the String.
// The operator also supports negative indexes, as in python. 
// If an invalid index is specified, an error is caused.
char& String::operator[](int i){
	if (i < -size_of_string || i >= size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	if (i >= 0) {
		return string_ptr[i];
	}
	return string_ptr[size_of_string + i];
}

// String operator for reading a string by index:
// This operator allows you to read the value of the ith character of the String.
// This operator also supports negative indexes, as in python.
// If an invalid index is specified, an error occurs.
char& String::operator[](int index) const {
	if (index < -size_of_string || index >= size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	if (index >= 0) {
		return string_ptr[index];
	}
	return string_ptr[size_of_string + index];
}

// --------------- Methods ---------------

String String::reverse() {
	for (int i = 0, j = size_of_string - 1; i < j; i++, j--) {
		std::swap(string_ptr[i], string_ptr[j]);
	}
	return *this;
}

void String::clear() {
	delete[] string_ptr;
	string_ptr = new char[1];
	string_ptr[0] = '\0';
	size_of_string = 0;
}

unsigned int String::size() const {
	return (unsigned int)size_of_string;
}

bool String::empty() const {
	return (size_of_string == 0);
}

String String::substr(int index, int N) const {
	if (index < 0 || index >= size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	if (N < 0 || index + N > size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	String temp(N);
	for (int i = 0; i < N; i++) {
		temp[i] = string_ptr[i + index];
	}
	return temp;
}

//This method inserts another one into this String so that it starts with the i-th index.
String String::insert(int index, const String &S) {
	if (index < 0 || index > size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	int new_size = size_of_string + S.size();
	char* temp = new char[new_size + 1];
	for (int i = 0; i < index; i++) {
		temp[i] = string_ptr[i];
	}
	for (int i = 0; i < S.size(); i++) {
		temp[i + index] = S[i];
	}
	for (int i = index; i < size_of_string; i++) {
		temp[i + S.size()] = string_ptr[i];
	}
	temp[new_size] = '\0';
	delete[] string_ptr;
	string_ptr = temp;
	size_of_string = new_size;
	return *this;
}

// This method returns a Z-array for a string of the form:
// (S) + '\a' + (*this)
int* String::get_Z_array(const String &S) const {
	if (S.size() == 0) {
		throw std::runtime_error("Error of trying to find an empty string");
	}

	String temp = S + "\a" + string_ptr;
	int* Z = new int[temp.size()];
	for (int i = 0; i < temp.size(); i++) {
		Z[i] = 0;
	}

	for (int i = 1, l = 0, r = 1; i < temp.size(); i++) {
		if (i < r) {
			if (Z[i - l] < r - i) {
				Z[i] = Z[i - l];
			}
			else {
				Z[i] = r - i;
			}
		}
		while (Z[i] + i < temp.size() && temp[Z[i] + i] == temp[Z[i]]) {
			Z[i]++;
		}
		if (r < i + Z[i]) r = i + Z[i], l = i;
	}

	return Z;
}

// This method returns the index of the first occurrence of a substring in a given string.
int String::lfind(const String& S) const {
	int* Z_arr = (*this).get_Z_array(S);
	for (int i = S.size() + 1; i < size_of_string + S.size() + 1; i++) {
		if (Z_arr[i] == S.size()) {
			delete[] Z_arr;
			return i - S.size() - 1;
		}
	}

	delete[] Z_arr;
	return -1;
}

// This method returns the index of the last occurrence of a substring in a given string.
int String::rfind(const String& S) const {
	int* Z_arr = (*this).get_Z_array(S);
	for (int i = size_of_string + S.size(); i >= S.size() + 1; i--) {
		if (Z_arr[i] == S.size()) {
			delete[] Z_arr;
			return i - S.size() - 1;
		}
	}

	delete[] Z_arr;
	return -1;
}

// This method returns the index of the entry_number occurrence
// of the substring in the given string after the start_index
int String::find(const String& S, int start_index, int entry_number) const {

	if (start_index < 0 || start_index > size_of_string) {
		throw std::out_of_range("Index out of range");
	}
	if (entry_number <= 0) {
		throw std::runtime_error("Wrong entry number");
	}

	int* Z_arr = (*this).get_Z_array(S);
	int cnt = 0;
	for (int i = S.size() + 1 + start_index; i < size_of_string + S.size() + 1; i++) {
		if (Z_arr[i] == S.size()) {
			cnt++;
			if (cnt == entry_number) {
				delete[] Z_arr;
				return i - S.size() - 1;
			}
		}
	}

	delete[] Z_arr;
	return -1;
}

int String::count(const String& S) const {
	int* Z_arr = (*this).get_Z_array(S);
	int cnt = 0;
	for (int i = S.size() + 1; i < size_of_string + S.size() + 1; i++) {
		if (Z_arr[i] == S.size()) {
			cnt++;
		}
	}

	delete[] Z_arr;
	return cnt;
}
