//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CONSTANTS_H
#define GA_PRIORITY_DELIVER_CONSTANTS_H
namespace constants {
    enum vehicle_types {truck, drone};
    /// @brief default constraint parameter
    int num_customer, num_truck, num_drone, time_limit;
    double speed_truck, speed_drone;
    int capacity_truck, capacity_drone, duration_drone;
}
#endif //GA_PRIORITY_DELIVER_CONSTANTS_H
