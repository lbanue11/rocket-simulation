#include <iostream>
#include "rocket.h"



int main() {

    int rocketMass;
    std::cout << "Enter the mass of the rocket in kg: ";
    std::cin >> rocketMass;
    Rocket myRocket(rocketMass);

    double time = 0.00; // Time interval in seconds
    int simulationDuration = 3; // Total simulation time in seconds
    double timeStep = 0.01; // Time step for simulation

    while ((time <= simulationDuration)) {

        const double currentVelocity = myRocket.nextVelocity(timeStep);
        const double currentAltitude = myRocket.nextAltitude(timeStep);

        std::cout << "Time: " << time << " s, "
                  << "Velocity: " << currentVelocity << " m/s, "
                  << "Altitude: " << currentAltitude << " m" << std::endl;

        time += timeStep; // Increment time
    }


}