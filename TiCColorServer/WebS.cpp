#include "WebS.h"
#include "base.h"
#include "Color.h"
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <vector>
#include <iterator>
#include <algorithm>
void WebS::onMessageReceived(int clientSocket, const char* msg, int length){
	//client's request string e.g. GET /index.html HTTP/1.1
	std::istringstream iss(msg);
	std::vector<std::string> parsed((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	// Some defaults for output to the client (404 file not found 'page')
	std::string content = "<h1>404 Not Found</h1>";
	std::string htmlFile = "./index.html";
	int errorCode = 404;

	// If the GET request is valid, try and get the name
	if (parsed.size() >= 3 && parsed[0] == "GET"){
		htmlFile = parsed[1];

		// If the file is just a slash, use index.html. This should really
		// be if it _ends_ in a slash. I'll leave that for you :)
		if (htmlFile == "/"){
			htmlFile = "index.html";
		}
		//REMEMBER TO CHANGE THIS ON DEBUG/RELEASE ON A WAY WITH INDEX.HTML
		std::ifstream f(".\\" + htmlFile);

		// Check if it opened and if it did, grab the entire contents
		if (f.good()) {
			std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
			content = str;
			errorCode = 200;
		}
		f.close();
	}

	if (parsed.size() >= 3 && parsed[0] == "POST") {
		content.clear();
		content = parsed[parsed.size() - 1];
		content.erase(0, 6);
		if (content.size() < 4) {
			content += " - this is not in color database.";
		}
		else {
			if (content.size() == 4) {
				transform(content.begin(), content.end(), content.begin(), std::toupper);
				for (int ptr = 0; ptr < base_color.size(); ptr++) {
					if (content == base_color[ptr].get_colour_name()) {
						content += " - ";
						content += base_color[ptr].get_color_all();
					}
				}
				if (content.size() < 5) {
					content += " colour not in base.";
				}
			}
			else {
				bool found = 0;
				replace(content.begin(), content.end(), '+', ' ');
				if (find(content.begin(), content.end(), ' ') != content.end()) {
					vector <int> rgb;
					istringstream tmppostrgb(content);
					int ptr0 = 0;
					while (tmppostrgb >> ptr0) {
						rgb.push_back(ptr0);
					}
					for (int ptr = 0; ptr < base_color.size(); ptr++) {
						if (rgb[0] == base_color[ptr].get_color_rgb()[0] && rgb[1] == base_color[ptr].get_color_rgb()[1] && rgb[2] == base_color[ptr].get_color_rgb()[2]) {
							content += " - ";
							content += base_color[ptr].get_colour_name();
							found = 1;
						}
					}
					if (!found) {
						content += " colour not in base.";
					}
					
				}
				else {
					content += " - error RGB, please type it correctly with spaces.";
				}
			}
		}
		errorCode = 200;
	}
	// Write the document back to the client
	std::ostringstream oss;
	oss << "HTTP/1.1 " << errorCode << " OK\r\n";
	oss << "Cache-Control: no-cache, private\r\n";
	oss << "Content-Type: text/html\r\n";
	oss << "Content-Length: " << content.size() << "\r\n";
	oss << "\r\n";
	oss << content;

	std::string output = oss.str();
	int size = output.size() + 1;

	sendToClient(clientSocket, output.c_str(), size);
}

// Handler for client connections
void WebS::onClientConnected(int clientSocket){

}

// Handler for client disconnections
void WebS::onClientDisconnected(int clientSocket){

}