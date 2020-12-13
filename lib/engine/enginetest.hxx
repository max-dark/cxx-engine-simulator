//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX
#define ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX

#include <engine/engine.hxx>

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

protected:
    /// \brief test init
    /// do nothing by default
    virtual void beforeStart();

    /// \brief start test
    virtual void start() = 0;

    /// \brief stop condition
    virtual bool stop() = 0;

    /// \brief one test step
    virtual void step() = 0;

    /// \brief test stop
    /// do nothing by default
    virtual void afterStop();

private:
    Engine* motor = nullptr;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ENGINETEST_HXX
