#pragma once
#include <iostream>
#include <string>
#include "MusThing.h"
using namespace std;

class Podcast : public MusThing {
protected:
	string author;

public:
	Podcast(string name = "0", string author = "0", int length = 0) :
		author(author) {
		this->name = name;
		this->length = length;
	}

	string Get_author() {
		return this->author;
	}
};