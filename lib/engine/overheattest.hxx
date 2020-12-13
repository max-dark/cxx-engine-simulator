//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_OVERHEATTEST_HXX
#define ENGINESIMULATOR_LIB_ENGINE_OVERHEATTEST_HXX

#include <engine/enginetest.hxx>

class OverheatTest: public EngineTest
{
public:
    ~OverheatTest() override;

    void setTimeStep(double timeStep) noexcept;

    double timeStep() const noexcept;

    double runTime() const noexcept;
protected:
    void beforeStart() override;

    void start() override;

    bool stop() override;

    void step() override;

    void afterStop() override;

private:
    double run_time = 0.0;
    double dt = 1.0;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_OVERHEATTEST_HXX
