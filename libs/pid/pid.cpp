#include "pid.hpp"

double PID::calculate(double measured_value){
    double output{1.0}, error{1.0};
    double proportional{1.0}, derivative{1.0};

    // PID calculation
    error = setpoint - measured_value;
    proportional = error;
    integral = integral + error * dt;
    derivative = (error - prev_error) / dt;
    output = Kp * proportional + Ki * integral + Kd * derivative;
    prev_error = error;

    return output;
}

double PID::setPoint(double objective){
    this->setpoint = objective;

    return 0.0;
}

std::ostream& operator<<(std::ostream& os, const PID& pid){
    os << pid.setpoint << "," << pid.Kp << "," << pid.Ki << "," << pid.Kd << "," << pid.dt;

    return os;
}

PID &PID::setKp(double Kp){
    this->Kp = Kp;
    return *this;
}
PID &PID::setKi(double Ki){
    this->Ki = Ki;
    return *this;
}
PID &PID::setKd(double Kd){
    this->Kd = Kd;
    return *this;
}
PID &PID::setdt(double dt){
    this->dt = dt;
    return *this;
}