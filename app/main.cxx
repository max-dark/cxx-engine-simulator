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

struct ConsoleCallback
{
    void on_start(const Engine* e)
    {
        std::cout << "Test started" << std::endl;
        steps = 0;
    }
    void on_step(const Engine* e)
    {
        ++steps;
        if (steps % 10 == 0)
        {
            std::cout << "T = " << e->currentT() << std::endl;
            std::cout << "M = " << e->currentM() << std::endl;
            std::cout << "V = " << e->currentV() << std::endl;
        }
    }
    void on_stop(const Engine* e)
    {
        std::cout << "Test stop: " << steps << " simulation steps" << std::endl;
    }
private:
    int steps = 0;
};

int main(int argc, char** argv)
{
    auto test = OverheatTest{};
    auto engine = IC_Engine{};
    auto console = ConsoleCallback{};

    setUp(engine);

    engine.setEnvT(20);

    test.setEngine(&engine);
    test.setTimeStep(1);

    // set test callbacks
    {
        using namespace std::placeholders;
        test.setStartCallback(std::bind(&ConsoleCallback::on_start, &console, _1));
        test.setStepCallback(std::bind(&ConsoleCallback::on_step, &console, _1));
        test.setStopCallback(std::bind(&ConsoleCallback::on_stop, &console, _1));
    }
    test.run();

    std::cout << "time: " << test.runTime();

    return 0;
}