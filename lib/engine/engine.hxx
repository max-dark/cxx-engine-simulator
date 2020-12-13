//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_ENGINE_HXX
#define ENGINESIMULATOR_LIB_ENGINE_ENGINE_HXX

/**
 * \brief Engine interface
 */
class Engine
{
public:
    /// \brief start engine
    virtual void start() = 0;

    /// \brief simulation step
    /// \param dt simulation time step
    virtual void step(double dt) = 0;

    /// \brief stop engine
    virtual void stop() = 0;

    /// \brief reset engine state
    virtual void reset() = 0;

    /// \brief Destructor
    virtual ~Engine();
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ENGINE_HXX
