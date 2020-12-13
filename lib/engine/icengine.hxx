//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX
#define ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX

#include <engine/engine.hxx>

#include <vector>
#include <utility>

/// \brief rotation/moment pair
/// first - rotation speed
/// second - moment
using MomentPair = std::pair<double, double>;
/// \brief rotation/moment data for pairwise linear function
using MomentFunction = std::vector<MomentPair>;

/**
 * \brief "internal combustion" engine
 */
class IC_Engine: public Engine
{
public:
    void start() override;

    void step() override;

    void stop() override;

    void reset() override;

    ~IC_Engine() override;

    void setInertia(double value) noexcept;

    double Inertia() const noexcept;

    void setOverheatTemp(double value) noexcept;

    double overheatTemp() const noexcept;

    void setHm(double value) noexcept;

    void setHv(double value) noexcept;

    void setC(double value) noexcept;

    void setEnvT(double value) noexcept;

    void setTargetV(double value) noexcept;

    /// current rotation speed
    double currentV() const noexcept;

    /// current moment
    double currentM() const noexcept;

    /// current temp
    double currentT() const noexcept;

    /// overheat test
    bool isOverheat() const noexcept;
private:
    /// moment of inertia
    double inertia;
    /// overheat temp
    double overheatT;
    /// heating dependency of M
    double Hm;
    /// heating dependency of V
    double Hv;
    /// cooling dependency of environ T
    double C;
    /// environ T
    double envT;

    double targetV; // target rotation speed
    double V; // current rotation speed
    double M; // current Moment
    double T; // current temp

    MomentFunction plfData;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_ICENGINE_HXX
