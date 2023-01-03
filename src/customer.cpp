//
// Created by linux on 1/3/23.
//
#include "../include/customer.h"
#include "../include/constants.h"
#include <cmath>

double euclid_distance(const Customer &a, const Customer &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double time_travel(const Customer &a, const Customer &b, constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return euclid_distance(a, b) / constants::speed_truck;
    else
        return euclid_distance(a, b) / constants::speed_drone;
}