//
// Created by theow on 26/10/2021.
//

#ifndef PROJET_2_MGL7460_UPTIME_H
#define PROJET_2_MGL7460_UPTIME_H

#include <iostream>
#include <chrono>
#include <ctime>


class uptime {
public:
    static void convert_sec(int sec, int array [3]);

    static std::string format_current_hour();

    static std::string format_day(int number_of_day);

    static std::string format_hours_and_minutes(int hour, int minute);

    static std::string generate_file_content(int up_time, int idle_time);
};


#endif //PROJET_2_MGL7460_UPTIME_H
