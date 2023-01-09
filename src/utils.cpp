//
// Created by linux on 1/3/23.
//

#include "../include/constants.h"
#include "../include/utils.h"
#include "cmath"

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

template<class T_Customer>
double euclid_distance(const T_Customer &a, const T_Customer &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

template<class T_Customer>
double time_travel(const T_Customer&a, const T_Customer&b, constants::vehicle_types vehicle_type) {
    return (double)euclid_distance<T_Customer>(a, b) / speed_of_vehicle(vehicle_type);
}
