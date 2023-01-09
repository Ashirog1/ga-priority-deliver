//
// Created by linux on 1/3/23.
//
#include "../include/route.h"
#include "../include/utils.h"
#include "../include/customer.h"

Route::Route() {
    total_weight = 0;
    total_time = 0;
    /// make a default vehicle type
    this->vehicle_type = constants::vehicle_types::truck;
    this->route.clear();

    this->route.emplace_back(Customer());
}

Route::Route(constants::vehicle_types vehicle_type) {
    total_weight = 0;
    total_time = 0;

    this->vehicle_type = vehicle_type;
    this->route.clear();

    this->route.emplace_back(Customer());
}

/*return remain weight in current route*/
int Route::remain_weight() {
    return limit_weight(this->vehicle_type) - this->total_weight;
}

bool Route::valid_route() {
    return this->total_time <= limit_time(this->vehicle_type);
}

bool Route::is_good_to_append(Customer customer) {
    return true;
}

void Route::pop() {

}

void Route::append(Customer customer) {
    this->total_weight += customer.current_weight;
    this->total_time += time_travel<Customer>(route.back(), customer, this->vehicle_type);

    route.emplace_back(customer);
}
