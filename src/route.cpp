//
// Created by linux on 1/3/23.
//
#include "../include/route.h"
#include "../include/constants.h"

Route::Route() {
    total_weight = 0;
    total_time = 0;
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

bool Route::valid_route() {
    if (this->total_weight > )
}
