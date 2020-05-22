#include "Color.h"
#include <iostream>
#include <string>
#include <vector>


void Color::set_color(int r, int g, int b, string n, int o) {
	this->R = r;
	this->G = g;
	this->B = b;
	this->O = o;
	this->NAMED = n;
}
void Color::set_color(int r, int g, int b, string n) {
	this->R = r;
	this->G = g;
	this->B = b;
	this->O = 0;
	this->NAMED = n;
}

void Color::cout_colour() {
	cout << this->R << ":" << this->G << ":" << this->B << this->NAMED << endl;
}
string Color::get_colour_name() {
	return this->NAMED;
}
string  Color::get_color_all() {
	return to_string(this->R) + " " + to_string(this->G) + " " + to_string(this->B);
}
vector <int> Color::get_color_rgb() {
	vector <int> res;
	res.push_back(this->R);
	res.push_back(this->G);
	res.push_back(this->B);
	return res;
}