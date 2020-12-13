//
// Created by max on 13.12.2020.
//

#include "icengine.hxx"

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

IC_Engine::~IC_Engine() = default;
