//
// Created by max on 13.12.2020.
//

#include <engine/icengine.hxx>
#include <engine/overheattest.hxx>

#include <iostream>

void setUp(IC_Engine& engine)
{
    engine.setInertia(10);
    engine.setOverheatTemp(110);
    engine.setHm(0.01);
    engine.setHv(0.0001);
    engine.setC(0.1);

    PiecewiseLinearFunction plf{};
    plf.addPoint(0, 20);
    plf.addPoint(75, 75);
    plf.addPoint(150, 100);
    plf.addPoint(200, 105);
    plf.addPoint(250, 75);
    plf.addPoint(300, 0);
    plf.sortPoints();

    engine.setPoints(std::move(plf));
}

int main(int argc, char** argv)
{
    auto test = OverheatTest{};
    auto engine = IC_Engine{};

    setUp(engine);

    engine.setEnvT(20);

    test.setEngine(&engine);
    test.setTimeStep(1);

    test.run();

    std::cout << "time: " << test.runTime();

    return 0;
}