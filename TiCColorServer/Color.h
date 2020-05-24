#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Color{
private:
	int R;
	int G;
	int B;
	int O;
	string NAMED;

public:
	Color() {
		this->R = 0;
		this->G = 0;
		this->B = 0;
		this->O = 0;
		this->NAMED = "";
	}
	Color(int r, int g, int b, string n):R(r), G(g), B(b), O(0), NAMED(n){}
	Color(int r, int g, int b, string n, int o) :R(r), G(g), B(b), O(o), NAMED(n) {}
	~Color(){}

	void set_color(int r, int g, int b, string n);
	void set_color(int r, int g, int b, string n, int o);
	void cout_colour();
	string get_colour_name();
	string get_color_all();
	string get_color_h2();
	vector <int> get_color_rgb();
};

