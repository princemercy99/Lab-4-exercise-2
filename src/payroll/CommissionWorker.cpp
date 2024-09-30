#include "CommissionWorker.h"
#include <iostream>

// Constructor definition
CommissionWorker::CommissionWorker(const std::string& first_name, const std::string& surname,
                                   double base_salary, double commission_per_item, int items_sold)
    : Employee(first_name, surname),  // Call to the base class constructor
      base_salary_(base_salary),
      commission_per_item_(commission_per_item),
      items_sold_(items_sold) {}

// Setters
void CommissionWorker::set_base_salary(double base_salary) {
    base_salary_ = base_salary;
}

void CommissionWorker::set_commission(double commission_per_item) {
    commission_per_item_ = commission_per_item;
}

void CommissionWorker::set_items_sold(int items_sold) {
    items_sold_ = items_sold;
}

// Override earnings function
double CommissionWorker::earnings() const {
    return base_salary_ + (commission_per_item_ * items_sold_);
}

// Override print function
void CommissionWorker::print() const {
    std::cout << "CommissionWorker: ";
    Employee::print();  // Reuse the base class's print to print the name
}
