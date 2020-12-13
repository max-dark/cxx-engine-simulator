//
// Created by max on 13.12.2020.
//

#include "overheattest.hxx"

OverheatTest::~OverheatTest() = default;

void OverheatTest::beforeStart()
{
    engine()->reset();
    run_time = 0.0;
}

void OverheatTest::start()
{
    engine()->start();
}

bool OverheatTest::stop()
{
    return engine()->isOverheat();
}

void OverheatTest::step()
{
    engine()->step(timeStep());
    run_time += timeStep();
}

void OverheatTest::afterStop()
{
    engine()->stop();
}

void OverheatTest::setTimeStep(double timeStep) noexcept
{
    dt = timeStep;
}

double OverheatTest::timeStep() const noexcept
{
    return dt;
}

double OverheatTest::runTime() const noexcept
{
    return run_time;
}
