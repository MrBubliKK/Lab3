#pragma once
#include <iostream>
#include <string>
#include "Music.h"

class RockMusic : public Music {
private:
	string style = "Rock";

public:
	RockMusic(string name, string lable, int length) {
		this->name = name;
		this->lable = lable;
		this->length = length;
	}
	
	string Get_style() {
		return this->style;
	}

};