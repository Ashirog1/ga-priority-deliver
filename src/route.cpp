//
// Created by linux on 1/3/23.
//
#include <algorithm>
#include "../include/route.h"
#include "../include/utils.h"

Route::Route() {
    total_weight = 0;
    total_time = 0;
    /// make a default vehicle type
    this->vehicle_type = constants::vehicle_types::truck;
    this->route.clear();
    /// create depot as a first customer
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
    if (this->total_time > limit_time(this->vehicle_type))
        return false;
    if (this->total_weight > limit_weight(this->vehicle_type))
        return false;
    return true;
}

bool Route::is_good_to_append(const Customer&customer) {
    this->append(customer);
    bool good = true;
    if (not this->valid_route()) {
        good = false;
    }
    this->pop();
    return good;
}

void Route::pop() {
    const Customer customer = route.back();
    route.pop_back();

    this->total_time -= customer.current_weight;
    this->total_weight -= time_travel(route.back(), customer, this->vehicle_type);
}

void Route::append(const Customer&customer) {
    this->total_weight += customer.current_weight;
    this->total_time += time_travel(route.back(), customer, this->vehicle_type);
    route.emplace_back(customer);
}

bool Route::is_appear(const Customer &customer) {
    const auto is_same_customer_id = [&](const Customer&other) {
       return other.customer_id == customer.customer_id;
    };
    if (std::any_of(route.begin(), route.end(), is_same_customer_id)) {
        return true;
    }
    return false;
}

int Route::get_total_weight() {
    return this->total_weight;
}

double Route::get_total_time() {
    return this->total_time;
}
