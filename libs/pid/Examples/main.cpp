#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "../pid.hpp"

const unsigned int microsecond = 1000000;

int main(){
    double setpoint{0.0};
    double result{0.8};

    // Pid init
    PID pid;
    pid.setKp(5).setKi(3).setKd(0).setdt(1);

    std::cout << "SP:"; std::cin >> setpoint;
    pid.setPoint(setpoint);
    
    std::cout << pid << std::endl;

    while(true){
        double measured_value{0.0};
        std::cout << "Measured:"; std::cin >> measured_value;

        result = pid.calculate(measured_value);
        
        std::cout << pid << ";result:" << result << ";measured:" << measured_value << std::endl;
    }

    return 0;
}