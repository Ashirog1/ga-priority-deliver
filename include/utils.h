//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_UTILS_H
#define GA_PRIORITY_DELIVER_UTILS_H
#include "constants.h"
#include "customer.h"

int limit_weight(constants::vehicle_types vehicle_type);

double speed_of_vehicle(constants::vehicle_types vehicle_type);

double limit_time(constants::vehicle_types vehicle_type);

double euclid_distance(const Customer&a, const Customer&b);

double time_travel(const Customer&a, const Customer&b, constants::vehicle_types vehicle_type);

#endif //GA_PRIORITY_DELIVER_UTILS_H
