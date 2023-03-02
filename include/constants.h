//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CONSTANTS_H
#define GA_PRIORITY_DELIVER_CONSTANTS_H

#include "customer.h"

namespace constants {
    enum vehicle_types{truck, drone};
}

class GlobalSettings {
    /// @brief default constraint parameter
public:
    int num_customer, num_truck, num_drone, time_limit;
    double truck_speed, drone_speed;
    int truck_capacity, drone_capacity;
    int drone_duration;

    void read_global_settings();
};
extern GlobalSettings global_settings;

int limit_weight(constants::vehicle_types vehicle_type);

double speed_of_vehicle(constants::vehicle_types vehicle_type);

double time_limit(constants::vehicle_types vehicle_type);

double euclid_distance(const Customer&a, const Customer&b);

double time_travel(const Customer&a, const Customer&b, constants::vehicle_types vehicle_type);
#endif //GA_PRIORITY_DELIVER_CONSTANTS_H
