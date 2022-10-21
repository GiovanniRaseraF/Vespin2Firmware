#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class PID {
private:
    double prev_error{0.0};
    double integral{1.0};
    double setpoint{0.0};
public:
    double Kp{1.0};
    double Ki{1.0};
    double Kd{1.0};
    double dt{1.0};

    PID &setKp(double);
    PID &setKi(double);
    PID &setKd(double);
    PID &setdt(double);

    PID(){};

    double setPoint(double);
    double calculate(double);

   friend std::ostream& operator<<(std::ostream& os, const PID& pid);
};