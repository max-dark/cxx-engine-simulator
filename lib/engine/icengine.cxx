//
// Created by max on 13.12.2020.
//

#include "icengine.hxx"

#include <algorithm>

void IC_Engine::start()
{

}

void IC_Engine::step()
{

}

void IC_Engine::stop()
{

}

void IC_Engine::reset()
{

}

double IC_Engine::currentV() const noexcept
{
    return V;
}

double IC_Engine::currentM() const noexcept
{
    return M;
}

double IC_Engine::currentT() const noexcept
{
    return T;
}

bool IC_Engine::isOverheat() const noexcept
{
    return currentT() >= overheatTemp();
}

void IC_Engine::setInertia(double value) noexcept
{
    inertia = value;
}

double IC_Engine::Inertia() const noexcept
{
    return inertia;
}

void IC_Engine::setOverheatTemp(double value) noexcept
{
    overheatT = value;
}

double IC_Engine::overheatTemp() const noexcept
{
    return overheatT;
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

void IC_Engine::setEnvT(double value) noexcept
{
    envT = value;
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

IC_Engine::~IC_Engine() = default;
