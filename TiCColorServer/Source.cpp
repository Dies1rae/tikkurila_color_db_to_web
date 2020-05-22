#include <string>
#include <iostream>
#include <vector>
#include "Color.h"
//#include "base.h"
#include "WebS.h"
#include <algorithm>
using namespace std;



int main(int argc, char* argv[]) {
	if (argc > 1 && argv[1][0] == '/') {
		if (argv[1][1] == 's') {
			WebS testserver("192.168.21.85", 8080);
			if (testserver.init() != 0) {
				return 0;
			}
			cout << "Server started" << endl;
			testserver.run();
			system("pause");
		}
		/*
		if (argv[1][1] == 'f') {
			if (argc == 3) {
				string tmp_colourname =  argv[2];
				transform(tmp_colourname.begin(), tmp_colourname.end(), tmp_colourname.begin(), std::toupper);
				for (int ptr = 0; ptr < base_color.size(); ptr++) {
					if (tmp_colourname == base_color[ptr].get_colour_name()) {
						cout << base_color[ptr].get_color_all() << endl;
						return 0;
					}
				}
			}
			if (argc == 5) {
				string r = argv[2];
				string g = argv[3];
				string b = argv[4];
				for (int ptr = 0; ptr < base_color.size(); ptr++) {
					if (stoi(r) == base_color[ptr].get_color_rgb()[0] && stoi(g) == base_color[ptr].get_color_rgb()[1] && stoi(b) == base_color[ptr].get_color_rgb()[2]) {
						cout << base_color[ptr].get_colour_name() << endl;
						return 0;
					}
				}
			}
			else {
				cerr << "Error RTFM!" << endl;
				return 0;
			}
		}
		*/
		else {
			cerr << "Error RTFM!" << endl;
			return 0;
		}
	}
	else {
		cerr << "Error RTFM!" << endl;
		return 0;
	}
	return 0;
}