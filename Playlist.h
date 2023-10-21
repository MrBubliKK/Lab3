#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Search.h"

class Playlist {
private:
	int cursor = 0;
	vector <Search> list_searchs;

public:
	int Get_cursor() {
		return this->cursor;
	}

	bool Increase_cursor() {
		this->cursor++;
		return true;
	}

	bool Reduce_cursor() {
		this->cursor--;
		return true;
	}

	void Set_cursor(int cursor) {
		this->cursor = cursor;
	}

	//Находит позицию определенного элемента
	int Get_number_search(string name, string author = "0", string lable = "0", string style = "0") {
		for (int i = 0; i < list_searchs.size(); i++) {
			if ((list_searchs[i].Get_author() == author)
				&& (list_searchs[i].Get_lable() == lable)
				&& (list_searchs[i].Get_name() == name)
				&& (list_searchs[i].get_style() == style)) {
				return i;
			}
		}
		return -1;
	}

	//Добавляет элемент в плейлист
	bool Add_thing_in_list(string name, string author = "0", string lable = "0", string style = "0") {
		list_searchs.push_back(Search(name, author, lable, style));
		return true;
	}

	//Удаляет элемент из плейлиста
	bool Del_thing_in_list(string name, string author = "0", string lable = "0", string style = "0") {
		list_searchs.erase(list_searchs.begin() + Get_number_search(name, author, lable, style));
		return true;
	}

	bool Check_thing(string name, string author = "0", string lable = "0", string style = "0") {
		for (int i = 0; i < list_searchs.size(); i++) {
			if ((list_searchs[i].Get_author() == author)
				&& (list_searchs[i].Get_lable() == lable)
				&& (list_searchs[i].Get_name() == name)
				&& (list_searchs[i].get_style() == style)) {
				return true;
			}
		}
		return false;
	}

	vector <Search> Get_list_searchs() {
		return list_searchs;
	}
};