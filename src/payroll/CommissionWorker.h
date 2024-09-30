#ifndef COMMISSION_WORKER_H
#define COMMISSION_WORKER_H

#include "Employee.h"  // Include base class

class CommissionWorker : public Employee {
public:
    // Constructor to initialize the base class and CommissionWorker-specific members
    CommissionWorker(const std::string& first_name, const std::string& surname,
                     double base_salary = 0.0, double commission_per_item = 0.0, int items_sold = 0);

    // Setters for the CommissionWorker-specific members
    void set_base_salary(double base_salary);
    void set_commission(double commission_per_item);
    void set_items_sold(int items_sold);

    // Override the earnings function to compute total earnings
    virtual double earnings() const override;

    // Override the print function to print CommissionWorker details
    virtual void print() const override;

private:
    double base_salary_;           // Base salary for the worker
    double commission_per_item_;   // Commission earned per item sold
    int items_sold_;               // Number of items sold in the week
};

#endif
