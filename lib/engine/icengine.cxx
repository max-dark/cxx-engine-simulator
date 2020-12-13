//
// Created by max on 13.12.2020.
//

#include <engine/icengine.hxx>

#include <utility>
#include <algorithm>

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

void IC_Engine::addPoint(double rotV, double rotM)
{
    plfData.emplace_back(rotV, rotM);
}

void IC_Engine::setPoints(MomentFunction data)
{
    plfData = std::move(data);
}

void IC_Engine::clearPoints()
{
    plfData = {};
}

double IC_Engine::getMomentByRotation(double rotV) const
{
    auto first = plfData.front();
    auto last = plfData.back();

    // out of range
    if (rotV <= first.first)
    {
        return first.second;
    }

    // out of range
    if (rotV >= last.first)
    {
        return last.second;
    }

    // here rotV in range(first..last)

    // find right bound of rotV
    auto right = std::lower_bound(std::begin(plfData), std::end(plfData), rotV,
                                  [](const MomentPair& a, double value)
    {
        return a.first <= value;
    });

    // approximate rotM by PLF range [left..right]

    auto left = right - 1;

    auto [lowV, lowM] = *left;
    auto [higV, higM] = *right;

    auto dV = higV - lowV;
    auto dM = higM - lowM;

    auto dX = rotV - lowV;
    auto kX = dX / dV;
    auto dY = dM * kX;

    return lowM + dY;
}

void IC_Engine::sortPoints()
{
    std::sort(std::begin(plfData), std::end(plfData),
              [](const MomentPair& a, const MomentPair& b)
    {
        return a.first < b.first;
    });
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
    auto maxV = plfData.back().first;
    auto nV = currentV() + dV(dt);
    return std::min(maxV, nV);
}

IC_Engine::~IC_Engine() = default;
