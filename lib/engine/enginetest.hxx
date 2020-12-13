//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX
#define ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX

#include <engine/engine.hxx>

#include <functional>

using TestCallback = std::function<void(const Engine*)>;

/**
 * \brief Engine Test Interface
 */
class EngineTest
{
public:
    /// \brief set engine for test
    void setEngine(Engine* engine);

    /// \brief current engine
    [[nodiscard]] Engine* engine() const noexcept;

    /// \brief run test
    void run();

    /// \brief destructor
    virtual ~EngineTest();

    void setStartCallback(TestCallback callback);
    void setStepCallback(TestCallback callback);
    void setStopCallback(TestCallback callback);

protected:
    /// \brief test init
    virtual void beforeStart();

    /// \brief start test
    virtual void start() = 0;

    /// \brief stop condition
    virtual bool stop() = 0;

    /// \brief one test step
    virtual void step() = 0;

    /// \brief test stop
    virtual void afterStop();

private:
    Engine* motor = nullptr;

    TestCallback on_start, on_step, on_stop;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX
