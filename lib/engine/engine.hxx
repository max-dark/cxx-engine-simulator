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

    /// current rotation speed
    double currentV() const noexcept;

    /// current moment
    double currentM() const noexcept;

    /// current temp
    double currentT() const noexcept;

    /// overheat test
    bool isOverheat() const noexcept;

    void setOverheatTemp(double value) noexcept;

    double overheatTemp() const noexcept;

    void setEnvT(double value) noexcept;

    double environT() const noexcept;

protected:
    void setM(double value) noexcept;
    void setV(double value) noexcept;
    void setT(double value) noexcept;

private:
    /// overheat temp
    double overheatT = 0;
    /// environ T
    double envT = 0;

    /// current rotation speed
    double V = 0;
    /// current rotation moment
    double M = 0;
    /// current engine temp
    double T = 0;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ENGINE_HXX
