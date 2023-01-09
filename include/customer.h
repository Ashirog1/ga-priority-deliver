//
// Created by linux on 1/3/23.
//

#ifndef GA_PRIORITY_DELIVER_CUSTOMER_H
#define GA_PRIORITY_DELIVER_CUSTOMER_H
class Customer {
private:
public:
    int lower_weight, upper_weight, cost, current_weight;
    double x = 0, y = 0;
    int customer_id;
    Customer();
    Customer(const Customer&oth);
    void read_customer();
    void raise_current_weight(int delta);
};
#endif //GA_PRIORITY_DELIVER_CUSTOMER_H
