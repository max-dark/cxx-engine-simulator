//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX
#define ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX

#include <engine/engine.hxx>

#include <utility/piecewiselinearfunction.hxx>

/**
 * \brief "internal combustion" engine
 */
class IC_Engine: public Engine
{
public:
    void start() override;

    void step(double dt) override;

    void stop() override;

    void reset() override;

    ~IC_Engine() override;

    void setPoints(PiecewiseLinearFunction data);

    void setInertia(double value) noexcept;

    double Inertia() const noexcept;

    void setHm(double value) noexcept;

    void setHv(double value) noexcept;

    void setC(double value) noexcept;

    void setTargetV(double value) noexcept;

private:
    /// moment of inertia
    double inertia = 0;
    /// heating dependency of M
    double Hm = 0;
    /// heating dependency of V
    double Hv = 0;
    /// cooling dependency of environ T
    double C = 0;

    double targetV = 0; // target rotation speed

    double getMomentByRotation(double rotV) const;

    double rotationAccel() const;

    double dV(double dt) const;

    double heatingV() const;

    double dHeat(double dt) const;

    double coolingV() const;

    double dCool(double dt) const;

    double newTemp(double dt) const;

    double newV(double dt) const;

    PiecewiseLinearFunction plf;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX
