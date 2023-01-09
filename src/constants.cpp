//
// Created by linux on 1/3/23.
//
#include "../include/constants.h"
#include "iostream"

void GlobalSettings::read_global_settings() {
    std::cin >> num_customer >> num_truck >> num_drone;
    std::cin >> truck_speed >> drone_speed >> truck_capacity >> drone_capacity >> drone_duration;
}