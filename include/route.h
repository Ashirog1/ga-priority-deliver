//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_ROUTE_H
#define GA_PRIORITY_DELIVER_ROUTE_H

#include "customer.h"
#include "constants.h"

#include "vector"

class Route {
private:
    int total_weight = 0;
    double total_time = 0;
    std::vector<Customer> route;
    constants::vehicle_types vehicle_type;
public:
    Route();
    /// init route with vehicle type
    explicit Route(constants::vehicle_types vehicle_type);
    bool valid_route();
    void append(const Customer&customer);
    bool is_good_to_append(const Customer&customer);
    int remain_weight();
    bool is_appear(const Customer&customer);
    void pop();
    int get_total_weight();
    double get_total_time();
};
#endif //GA_PRIORITY_DELIVER_ROUTE_H
