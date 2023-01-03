//
// Created by linux on 1/3/23.
//

#include "../include/utils.h"
#include "../include/constants.h"
#include "../include/customer.h"

int limit_weight(constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return constants::truck_capacity;
    else
        return constants::drone_capacity;
}

double speed_of_vehicle(constants::vehicle_types vehicle_type) {
    if (vehicle_type == constants::truck)
        return constants::truck_speed;
    else
        return constants::drone_speed;
}

double euclid_distance(const Customer &a, const Customer &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double time_travel(const Customer &a, const Customer &b, constants::vehicle_types vehicle_type) {
    return euclid_distance(a, b) / speed_of_vehicle(vehicle_type);
}
