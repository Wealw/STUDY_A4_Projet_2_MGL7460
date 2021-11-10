//
// Created by theow on 26/10/2021.
//

#include <iostream>
#include <fstream>
#include "../include/uptime.hpp"

int main() {
    try {
        std::ifstream uptime_file("./uptime_file");
        std::string text;
        std::getline(uptime_file, text);
        if (text != "") {
            int up_time = abs(std::stoi(text.substr(0, text.find(' '))));
            text.erase(0, text.find(' ') + 1);
            int idle_time = abs(std::stoi(text.substr(0, text.find(' '))));
            std::cout << uptime::generate_file_content(up_time, idle_time);
        } else {
            std::cout << "It appear that the uptime_file is either not there or empty";
        }
        uptime_file.close();
    } catch (std::exception &exception) {
        std::cout << "There was an error when reading your update file";
    }
    return 0;
}
