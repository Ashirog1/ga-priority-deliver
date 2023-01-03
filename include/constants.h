//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CONSTANTS_H
#define GA_PRIORITY_DELIVER_CONSTANTS_H
namespace constants {
    const enum vehicle_types{truck, drone};
    /// @brief default constraint parameter
    extern int num_customer, num_truck, num_drone, time_limit;
    extern double truck_speed, drone_speed;
    extern int truck_capacity, drone_capacity;
    extern int drone_duration;
}
#endif //GA_PRIORITY_DELIVER_CONSTANTS_H
