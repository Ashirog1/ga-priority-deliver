//
// Created by linux on 1/5/23.
//

#include "../include/customer.h"
#include "iostream"
#include "cassert"

Customer::Customer() {
    this->current_weight = this->lower_weight = this->upper_weight = 0;
    this->x = this->y = 0;
    this->customer_id = 0;
    this->cost = 0;
}

Customer::Customer(const Customer&oth) {
   x = oth.x; y = oth.y;
   lower_weight = oth.lower_weight;
   upper_weight = oth.upper_weight;
   current_weight = oth.current_weight;
   customer_id = oth.customer_id;
   cost = oth.cost;
}

void Customer::raise_current_weight(int delta) {
    this->current_weight += delta;
}

void Customer::read_customer() {
    std::cin >> x >> y >> lower_weight >> upper_weight >> cost;
}