//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CUSTOMER_H
#define GA_PRIORITY_DELIVER_CUSTOMER_H
class Customer {
public:
    Customer() {
        lower_weight = upper_weight = cost = 0;
        x = y = 0;
    }
    int lower_weight, upper_weight, cost;
    double x = 0, y = 0;
};
#endif //GA_PRIORITY_DELIVER_CUSTOMER_H
