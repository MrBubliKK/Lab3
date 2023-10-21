#pragma once
#include <iostream>
#include <string>
#include "MusThing.h"

class Music : public MusThing {
protected:
	string lable;

public:
	Music(string name = "0", string lable = "0", int length = 0) :
		lable(lable) {
		this->name = name;
		this->length = length;
	}

	string Get_lable() {
		return this->lable;
	}

};