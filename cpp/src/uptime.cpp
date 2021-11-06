//
// Created by theow on 26/10/2021.
//

#include "../include/uptime.hpp"

void uptime::convert_sec(int sec, int array[3]) {
    int number_of_day = sec / 86400;
    int number_of_hour = (sec - number_of_day * 86400) / 3600;
    int number_of_min = (sec - number_of_day * 86400 - number_of_hour * 3600) / 60;
    array[0] = number_of_day;
    array[1] = number_of_hour;
    array[2] = number_of_min;
}

std::string uptime::format_current_hour() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string hour = (ltm->tm_hour < 10 ? "0" : "") + std::to_string(ltm->tm_hour);
    std::string min = (ltm->tm_min < 10 ? "0" : "") + std::to_string(ltm->tm_min);
    std::string sec = (ltm->tm_sec < 10 ? "0" : "") + std::to_string(ltm->tm_sec);
    return hour + ":" + min + ":" + sec;
}

std::string uptime::format_day(int number_of_day) {
    if (number_of_day == 0) {
        return "";
    } else if (number_of_day == 1) {
        return "1 day, ";
    } else {
        return std::to_string(number_of_day) + " days, ";
    }
}

std::string uptime::format_hours_and_minutes(int hour, int minute) {
    if (hour == 0) {
        return std::to_string(minute) + " min";
    } else if (minute < 10) {
        return std::to_string(hour) + ":0" + std::to_string(minute);
    } else {
        return std::to_string(hour) + ":" + std::to_string(minute);
    }
}

std::string uptime::generate_file_content(int up_time, int idle_time) {
    std::string current_hour = uptime::format_current_hour();

    int converted_uptime[3];
    uptime::convert_sec(up_time, converted_uptime);
    int converted_idle_time[3];
    uptime::convert_sec(idle_time, converted_idle_time);

    std::string up_days = uptime::format_day(converted_uptime[0]);
    std::string idle_days = uptime::format_day(converted_idle_time[0]);

    std::string up_hours_and_minutes = uptime::format_hours_and_minutes(converted_uptime[1], converted_uptime[2]);
    std::string idle_hours_and_minutes = uptime::format_hours_and_minutes(converted_idle_time[1],
                                                                          converted_idle_time[2]);

    return current_hour + " up " + up_days + up_hours_and_minutes + "\n" + current_hour + " idle " + idle_days +
           idle_hours_and_minutes;
}