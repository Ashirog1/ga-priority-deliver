//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_ROUTE_H
#define GA_PRIORITY_DELIVER_ROUTE_H
#include "vector"
#include "constants.h"
class CustomerInfo {
public:
    int customer_id;
    CustomerInfo() {
        weight = 0;
        customer_id = -1;
    }
    CustomerInfo(int customer_id, int weight) {
        this->customer_id = customer_id;
        this->weight = weight;
    }
};

class Route {
private:
    int total_weight = 0;
    double total_time = 0;
    std::vector<CustomerInfo> route;
    constants::vehicle_types vehicle_type;
public:
    Route();
    /// init route with vehicle type
    Route(constants::vehicle_types vehicle_type);
    bool valid_route();
    void append(CustomerInfo customer);
    bool is_good_to_append(CustomerInfo customer);
    int remain_weight();
};
#endif //GA_PRIORITY_DELIVER_ROUTE_H
