//
// Created by leoba on 12/15/2025.
//

#include <iostream>
#ifndef ROCKET_H
#define ROCKET_H


class Rocket {

private:
    const double gravity = 9.81;
    double mass;
    double thrust = 30000.0; // Example thrust value in Newtons Can be modified as needed
    double velocity = 0.0; // Current velocity of the rocket
    double dragCoefficient = 50.0; // Example drag coefficient
    double altitude = 0.0; // Current altitude of the rocket


public:
    explicit Rocket(const double m) : mass(m) {}

    [[nodiscard]] double weight() const {
        return mass * gravity;
    }

    [[nodiscard]] double dragForce() const {
        return dragCoefficient * velocity; // change this once you add current velocity
    }

    [[nodiscard]] double netForce() const {
        return thrust - weight() - dragForce();
    }

    [[nodiscard]] double acceleration() const {
        return netForce() / mass;
    }

    double nextVelocity(const double timeInterval) {

        if (timeInterval <= 0) {
            return velocity; // No change in velocity for non-positive time intervals
        }
        velocity += acceleration() * timeInterval;
        return velocity;
    }

    double nextAltitude(const double timeInterval) {

        if (timeInterval <= 0) {
            return altitude; // No change in altitude for non-positive time intervals
        }
        altitude += velocity * timeInterval;
        return altitude;
    }


};

#endif