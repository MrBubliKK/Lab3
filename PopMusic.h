#pragma once
#include <iostream>
#include <string>
#include "Music.h"

class PopMusic : public Music {
private:
	string style = "Pop";

public:
	PopMusic(string name, string lable, int length) {
		this->name = name;
		this->lable = lable;
		this->length = length;
	}

	string Get_style() {
		return this->style;
	}
};