//
// Created by max on 13.12.2020.
//

#include <algorithm>
#include "engine.hxx"
#include "icengine.hxx"
#include <engine/engine.hxx>

Engine::~Engine() = default;

double Engine::currentV() const noexcept
{
    return V;
}

double Engine::currentM() const noexcept
{
    return M;
}

double Engine::currentT() const noexcept
{
    return T;
}

bool Engine::isOverheat() const noexcept
{
    return currentT() > overheatTemp() || (0.0001 > std::abs(currentT() - overheatTemp()));
}

void Engine::setOverheatTemp(double value) noexcept
{
    overheatT = value;
}

double Engine::overheatTemp() const noexcept
{
    return overheatT;
}

void Engine::setEnvT(double value) noexcept
{
    envT = value;
}

void Engine::setM(double value) noexcept
{
    M = value;
}

void Engine::setT(double value) noexcept
{
    T = value;
}

void Engine::setV(double value) noexcept
{
    V = value;
}

double Engine::environT() const noexcept
{
    return envT;
}
