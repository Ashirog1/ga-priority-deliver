//
// Created by linux on 1/3/23.
//
#include "../include/constants.h"

#include "iostream"
#include "cmath"

void GlobalSettings::read_global_settings() {
    std::cin >> num_customer >> num_truck >> num_drone;
    std::cin >> truck_speed >> drone_speed >> truck_capacity >> drone_capacity >> drone_duration;
}

int limit_weight(constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return global_settings.truck_capacity;
    else
        return global_settings.drone_capacity;
}

double speed_of_vehicle(constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return global_settings.truck_speed;
    else
        return global_settings.drone_speed;
}

double limit_time(constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return global_settings.time_limit;
    else
        return std::min(global_settings.time_limit, global_settings.drone_duration);
}

double euclid_distance(const Customer&a, const Customer&b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double time_travel(const Customer&a, const Customer&b, constants::vehicle_types vehicle_type) {
    return (double)euclid_distance(a, b) / speed_of_vehicle(vehicle_type);
}
