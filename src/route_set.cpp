//
// Created by linux on 1/15/23.
//

#include "../include/route_set.h"

#include "cassert"

void RouteSet::append(Route route) {
    assert(route.valid_route());
    this->emplace_back(route);
    this->total_time += route.get_total_time();
}

bool RouteSet::valid_route_set() {
    return this->total_time <= global_settings.time_limit;
}
