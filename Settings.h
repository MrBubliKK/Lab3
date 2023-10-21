#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using namespace std;

class Settings {
private:
	int volume = 30;
	int temp_volume = 0;
	int access = 1;
	string password = "laboratornaya";
	string username = "User";

public:
	void Increase_volume(int val) {
		volume += val;
	}

	void Reduce_volume(int val) {
		this->volume -= val;
	}

	void Set_volume(int volume) {
		this->volume = volume;
	}

	int Get_volume() {
		return this->volume;
	}

	int Get_access() {
		return this->access;
	}

	void Set_shared_access() {
		this->access = 1;
	}

	void Set_group_access() {
		this->access = 2;
	}

	void Set_admin_access() {
		this->access = 3;
	}

	string Get_password() {
		return this->password;
	}

	void Set_password(string password) {
		this->password = password;
	}

	int Get_temp_volume() {
		return this->temp_volume;
	}

	void Set_temp_volume(int temp_volume) {
		this->temp_volume = temp_volume;
	}

	string Get_username() {
		return this->username;
	}

	void Set_username(string name) {
		this->username = name;
	}
};