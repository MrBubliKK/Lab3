#pragma once
#include <iostream>
#include <string>
#include "Podcast.h"
using namespace std;

class FinePodcast : public Podcast {
private:
	string style = "Fine";

public:
	FinePodcast(string name, string author, int length) {
		this->name = name;
		this->author = author;
		this->length = length;
	}

	string Get_style() {
		return this->style;
	}

};