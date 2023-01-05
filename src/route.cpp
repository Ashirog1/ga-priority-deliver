//
// Created by linux on 1/3/23.
//
#include "../include/route.h"
#include "../include/utils.h"

Route::Route() {
    total_weight = 0;
    total_time = 0;
    /// make a default vehicle type
    this->vehicle_type = constants::vehicle_types::truck;
    this->route.clear();

    this->route.emplace_back(0, 0);
}

Route::Route(constants::vehicle_types vehicle_type) {
    total_weight = 0;
    total_time = 0;

    this->vehicle_type = vehicle_type;
    this->route.clear();

    this->route.emplace_back(0, 0);
}

/*return remain weight in current route*/
int Route::remain_weight() {
    return limit_weight(this->vehicle_type) - this->total_weight;
}

bool Route::valid_route() {
    return total_time <= limit_time(this->vehicle_type);
}

bool Route::is_good_to_append(CustomerInfo customer) {
    return true;
}

void Route::append(CustomerInfo customer) {
    total_weight += customer.weight;
    total_time += time_travel()
}
