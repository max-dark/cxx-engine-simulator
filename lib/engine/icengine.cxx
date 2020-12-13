//
// Created by max on 13.12.2020.
//

#include <engine/icengine.hxx>

#include <algorithm>
#include <utility>

void IC_Engine::start()
{
    setV(0);
    setM(getMomentByRotation(currentV()));
}

void IC_Engine::step(double dt)
{
    auto nV = newV(dt);
    auto nM = getMomentByRotation(nV);
    auto nT = newTemp(dt);

    setV(nV);
    setM(nM);
    setT(nT);
}

void IC_Engine::stop()
{
    setTargetV(0);
}

void IC_Engine::reset()
{
    setV(0);
    setM(0);
    setT(environT());
}

void IC_Engine::setInertia(double value) noexcept
{
    inertia = value;
}

double IC_Engine::Inertia() const noexcept
{
    return inertia;
}

void IC_Engine::setHm(double value) noexcept
{
    Hm = value;
}

void IC_Engine::setHv(double value) noexcept
{
    Hv = value;
}

void IC_Engine::setC(double value) noexcept
{
    C = value;
}

void IC_Engine::setTargetV(double value) noexcept
{
    targetV = value;
}

double IC_Engine::getMomentByRotation(double rotV) const
{
    return plf.calculate(rotV);
}

double IC_Engine::rotationAccel() const
{
    return currentM() / Inertia();
}

double IC_Engine::heatingV() const
{
    return currentM() * Hm + currentV() * currentV() * Hv;
}

double IC_Engine::coolingV() const
{
    return C * (environT() - currentT());
}

double IC_Engine::dV(double dt) const
{
    return dt * rotationAccel();
}

double IC_Engine::dHeat(double dt) const
{
    return dt * heatingV();
}

double IC_Engine::dCool(double dt) const
{
    return dt * coolingV();
}

double IC_Engine::newTemp(double dt) const
{
    return currentT() + dHeat(dt) + dCool(dt);
}

double IC_Engine::newV(double dt) const
{
    auto maxV = plf.last().first;
    auto nV = currentV() + dV(dt);
    return std::min(maxV, nV);
}

void IC_Engine::setPoints(PiecewiseLinearFunction data)
{
    plf = std::move(data);
}

IC_Engine::~IC_Engine() = default;
