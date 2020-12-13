//
// Created by max on 13.12.2020.
//

#include <engine/enginetest.hxx>

EngineTest::~EngineTest() = default;

void EngineTest::beforeStart()
{
    if (on_start)
        on_start(engine());
}

void EngineTest::afterStop()
{
    if (on_stop)
        on_stop(engine());
}

void EngineTest::run()
{
    beforeStart();
    start();

    while (! stop())
    {
        step();
        if (on_step)
            on_step(engine());
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

void EngineTest::setStartCallback(TestCallback callback)
{
    on_start = std::move(callback);
}

void EngineTest::setStepCallback(TestCallback callback)
{
    on_step = std::move(callback);
}

void EngineTest::setStopCallback(TestCallback callback)
{
    on_stop = std::move(callback);
}
