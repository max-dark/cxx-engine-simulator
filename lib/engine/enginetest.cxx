//
// Created by max on 13.12.2020.
//

#include <engine/enginetest.hxx>

EngineTest::~EngineTest() = default;

void EngineTest::beforeStart()
{}

void EngineTest::afterStop()
{}

void EngineTest::run()
{
    beforeStart();
    start();

    while (! stop())
    {
        step();
    }

    afterStop();
}

void EngineTest::setEngine(Engine *engine)
{
    motor = engine;
}

Engine *EngineTest::engine() const noexcept
{
    return motor;
}
