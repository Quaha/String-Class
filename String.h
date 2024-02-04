#pragma once

#include "stdafx.h"

class String {

protected:
	/*
	string_ptr contains a pointer to char*. After using the class constructor,
	the last char* character is always '\0'. This character is not taken into
	account in the size_of_string.
	*/
	char* string_ptr = nullptr;
	int size_of_string = 0;

	// ----- Constructors -----
public:
	String();
	String(int N);
	String(int N, char C);
	String(int N, const String& S);
	String(const char* S);

	String(const String& S);

	~String();


	// ----- Operators -----
public:
	String operator =(const String& S);

	void operator +=(const String& S);
	String operator +(const String& S1) const;

	void operator *=(int N);
	String operator *(int N) const;
	friend String operator*(int N, const String& S);

	friend bool operator ==(const String& S1, const String& S2);
	friend bool operator !=(const String& S1, const String& S2);
	friend bool operator <(const String& S1, const String& S2);
	friend bool operator >(const String& S1, const String& S2);
	friend bool operator <=(const String& S1, const String& S2);
	friend bool operator >=(const String& S1, const String& S2);

	friend std::ostream& operator<<(std::ostream& out, const String& S);
	friend std::istream& operator>>(std::istream& in, String& S);

	char& operator[](int i);
	char& operator[](int i) const;


	// ----- Methods -----
public:
	String reverse();
	void clear();
	unsigned int size() const;
	bool empty() const;
	String substr(int index, int N) const;
	String insert(int index, const String& S);

protected:
	int* get_Z_array(const String &S) const;

public:
	int lfind(const String& S) const;
	int rfind(const String& S) const;
	int find(const String& S, int start_index = 0, int entry_number = 1) const;
	int count(const String& S) const;
};
