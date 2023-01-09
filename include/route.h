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
    Route(constants::vehicle_types vehicle_type);
    bool valid_route();
    void append(Customer customer);
    bool is_good_to_append(Customer customer);
    int remain_weight();
    void pop();
};
#endif //GA_PRIORITY_DELIVER_ROUTE_H
