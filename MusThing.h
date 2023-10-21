#pragma once
#include <iostream>
#include <string>

class MusThing {
protected:
	string name;
	int length;

public:
	MusThing(string name = "0", int length = 0) :
		name(name),
		length(length) {}

	string Get_name() {
		return this->name;
	}

	int Get_length() {
		return this->length;
	}
};