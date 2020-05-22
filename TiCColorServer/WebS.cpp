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
	// Parse out the client's request string e.g. GET /index.html HTTP/1.1
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
		std::ifstream f("C:\\Users\\n.poltavskiy\\source\\repos\\TiCColorServer\\TiCColorServer\\" + htmlFile);

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
						content += " ";
						content += base_color[ptr].get_color_all();
					}
				}
				if (content.size() < 5) {
					content += " colour not in base.";
				}
			}
			if (content.size() == 11) {
				replace(content.begin(), content.end(), '+', ' ');
				string r = content.substr(0, 3);
				string g = content.substr(4, 3);
				string b = content.substr(8, 3);
				for (int ptr = 0; ptr < base_color.size(); ptr++) {
					if (stoi(r) == base_color[ptr].get_color_rgb()[0] && stoi(g) == base_color[ptr].get_color_rgb()[1] && stoi(b) == base_color[ptr].get_color_rgb()[2]) {
						content += " - ";
						content += base_color[ptr].get_colour_name();

					}
				}
				if (content.size() < 5) {
					content += " colour not in base.";
				}
			}
			if (content.size() == 9) {
				string r = content.substr(0, 3);
				string g = content.substr(3, 3);
				string b = content.substr(6, 3);
				for (int ptr = 0; ptr < base_color.size(); ptr++) {
					if (stoi(r) == base_color[ptr].get_color_rgb()[0] && stoi(g) == base_color[ptr].get_color_rgb()[1] && stoi(b) == base_color[ptr].get_color_rgb()[2]) {
						content += " - ";
						content += base_color[ptr].get_colour_name();

					}
				}
				if (content.size() < 5) {
					content += " colour not in base.";
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