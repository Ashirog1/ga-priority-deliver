//
// Created by linux on 1/15/23.
//

#ifndef GA_PRIORITY_DELIVER_ROUTE_SET_H
#define GA_PRIORITY_DELIVER_ROUTE_SET_H

#include "route.h"

class RouteSet : std::vector<Route>{
private:
    double total_time = 0;
public:
    void append(Route route);
    bool valid_route_set();
};
#endif //GA_PRIORITY_DELIVER_ROUTE_SET_H
