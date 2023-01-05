//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CONSTANTS_H
#define GA_PRIORITY_DELIVER_CONSTANTS_H
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

    void read();
};

extern GlobalSettings global_settings;
#endif //GA_PRIORITY_DELIVER_CONSTANTS_H
