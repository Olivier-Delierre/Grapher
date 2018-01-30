#include "function.hpp"

#include <cmath>

function::function() :
    d_value_number{ 0 }
{ 
    d_variable_values = new double[d_value_number]; 
    d_powers = new int[d_value_number];
} 

function::~function() 
{ 
    delete[] d_variable_values; 
    delete[] d_powers;
}

double function::value_of_index(int index) const
{ return d_variable_values[index]; }

int function::power_of_index(int index) const
{ return d_powers[index]; }

void function::insert_value(double value, int power) {
    int *new_powers = new int[d_value_number + 1];
    double *new_variable_values = new double[d_value_number + 1];

    int i{ 0 };

    while (i < d_value_number && d_powers[i] < power) {
        new_powers[i] = d_powers[i];
        new_variable_values[i] = d_variable_values[i];

        i++;
    }

    new_powers[i] = power;
    new_variable_values[i] = value;

    while (i < d_value_number) {
        new_powers[i + 1] = d_powers[i];
        new_variable_values[i + 1] = d_variable_values[i];

        i++;
    }

    delete[] d_powers;
    delete[] d_variable_values;

    d_value_number++;

    d_powers = new_powers;
    d_variable_values = new_variable_values;
}

double function::resolve(double x) const {
    double sum{ 0 };

    for (int i = 0; i < d_value_number; i++) {
        sum += d_variable_values[i] * pow(x, d_powers[i]);
    }

    return sum;
}

int function::value_number() const
{ return d_value_number; }

std::ostream& operator<<(std::ostream& ost, const function& f) {
    ost << "f(x) = "; 

    for (int i = f.value_number() - 1; i > 1; i--) {
        if (f.value_of_index(i) == 1)
            ost << "x^" << f.power_of_index(i) << " + ";
        else
            ost << f.value_of_index(i) << "x^" << f.power_of_index(i) << " + ";
    }

    if (f.value_number() >= 2) 
    {
        if (f.value_of_index(1) != 1)
           ost << f.value_of_index(1); 
        
        if (f.power_of_index(1) == 1) 
            ost << "x + " << f.value_of_index(0);
        else {
            ost << "x^" << f.power_of_index(1) << " + ";
            if (f.value_of_index(0) != 1) 
                ost << f.value_of_index(0);

            if (f.power_of_index(0) == 1)
                ost << "x";
        }
    }

    else
    {
        if (f.value_of_index(0) != 1)
            ost << f.value_of_index(0);

        if (f.power_of_index(0) == 1)
            ost << "x";
        else if (f.power_of_index(0) != 0)
            ost << "x^" << f.power_of_index(0);
    }

    return ost;
}
