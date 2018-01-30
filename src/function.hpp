/**
 * A class based on function.
 *
 * @author Olivier Delierre
 * @ version 1.0
 */

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <iostream>

class function {
public:
    /// Default constructor.
    function();

    /// Default destructor.
    ~function();

    /**
     * Returns the value at the specified index.
     *
     * @param index The specified index.
     * @returns the value of the specified index.
     */
    double value_of_index(int index) const;
    
    /**
     * Returns the power at the specified index.
     *
     * @param index The specified index.
     * @returns the power of the specified index.
     */
    int power_of_index(int index) const;

    /**
     * Insert the specified value and the power on the function.
     *
     * @param value The value to insert ;
     * @param power The x-power of the value.
     */
    void insert_value(double value, int power);

    /**
     * Returns the result of the function with a specified x.
     *
     * @param x A specified value.
     * @returns the result of the function with a specified x.
     */
    double resolve(double x) const;

    /**
     * Returns the number of variable of the function.
     *
     * @return the number of variable of the function.
     */
    int value_number() const;
private:
    /**
     * Returns index of the specified power.
     *
     * @returns index of the specified power, -1 if not found.
     */
    int index_of_power(int power) const;

    /**
     * Parameters
     */
    /// Number of values.
    int d_value_number;
    /// Values of each x-power of the function. Order ascendant.
    double *d_variable_values;
    /// Values of power of the function. Order ascendant.
    int *d_powers;
};

std::ostream& operator<<(std::ostream& ost, const function& f);

#endif 
