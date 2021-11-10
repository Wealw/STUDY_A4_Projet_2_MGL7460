//
// Created by theow on 26/10/2021.
//

#include "../include/uptime.hpp"
#include "doctest.h"
#include <unistd.h>
#include <regex>

TEST_CASE ("convert_sec()") {
    {
        int array[3];
        int sec = 777600;
        uptime::convert_sec(sec, array);
        int expected[3] = {9, 0, 0};
        bool result = (array[0] == expected[0] && array[1] == expected[1] && array[2] == expected[2]);
                CHECK(result);
    }
    {
        int array[3];
        int sec = 7200;
        uptime::convert_sec(sec, array);
        int expected[3] = {0, 2, 0};
        bool result = (array[0] == expected[0] && array[1] == expected[1] && array[2] == expected[2]);
                CHECK(result);
    }
    {
        int array[3];
        int sec = 120;
        uptime::convert_sec(sec, array);
        int expected[3] = {0, 0, 2};
        bool result = (array[0] == expected[0] && array[1] == expected[1] && array[2] == expected[2]);
                CHECK(result);
    }
}


TEST_CASE ("format_day") {
    {
        int number_of_day = 0;
        std::string result = uptime::format_day(number_of_day);
                CHECK(result == "");
    }
    {
        int number_of_day = 1;
        std::string result = uptime::format_day(number_of_day);
                CHECK(result == "1 day, ");
    }
    {
        int number_of_day = 20;
        std::string result = uptime::format_day(number_of_day);
                CHECK(result == "20 days, ");
    }
}

TEST_CASE ("format_hours_and_minutes") {
    {
        int number_of_hour = 0;
        int number_of_minute = 0;
        std::string result = uptime::format_hours_and_minutes(number_of_hour, number_of_minute);
                CHECK(result == "0 min");
    }
    {
        int number_of_hour = 7;
        int number_of_minute = 5;
        std::string result = uptime::format_hours_and_minutes(number_of_hour, number_of_minute);
                CHECK(result == "7:05");
    }
    {
        int number_of_hour = 17;
        int number_of_minute = 20;
        std::string result = uptime::format_hours_and_minutes(number_of_hour, number_of_minute);
                CHECK(result == "17:20");
    }
}
/*
 * Way too hard to implement without a proper regex support, yes, i'm talking about you c++ 11...
TEST_CASE ("generate_file_content") {
    {

        int up_sec = 86461;
        int idle_sec = 23456789;
        std::string result = uptime::generate_file_content(up_sec, idle_sec);
        CHECK(result == " up 1 day, 1 min idle 271 days, 11:46");
    }

    {
        int up_sec = 4567;
        int idle_sec = 4056;
        std::string result = uptime::generate_file_content(up_sec, idle_sec);
        std::cout << result;
        std::regex e("[0-9]{2}:[0-9]{2}:[0-9]{2} up 1:16\n[0-9]{2}:[0-9]{2}:[0-9]{2} idle 1:07");
        bool value = std::regex_match(result, e);
                CHECK(value);
    }
}
 */