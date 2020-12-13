//
// Created by max on 13.12.2020.
//

#include "piecewiselinearfunction.hxx"

#include <algorithm>

void PiecewiseLinearFunction::addPoint(double x, double y)
{
    data.emplace_back(x, y);
}

void PiecewiseLinearFunction::setPoints(XYData points)
{
    data = std::move(points);
}

void PiecewiseLinearFunction::clear()
{
    data = {};
}

void PiecewiseLinearFunction::sortPoints()
{
    std::sort(std::begin(data), std::end(data),
              [](const XYPair& a, const XYPair& b)
              {
                  return a.first < b.first;
              });
}

double PiecewiseLinearFunction::calculate(double X) const
{
    auto first = data.front();
    auto last = data.back();

    // out of range
    if (X <= first.first)
    {
        return first.second;
    }

    // out of range
    if (X >= last.first)
    {
        return last.second;
    }

    // here X in range(first..last)

    // find right bound of X
    auto right = std::lower_bound(std::begin(data), std::end(data), X,
                                  [](const XYPair& a, double value)
                                  {
                                      return a.first <= value;
                                  });

    // interpolate Y by PLF range [left..right]

    auto left = right - 1;

    auto [leftX, leftY] = *left;
    auto [rightX, rightY] = *right;

    auto Xrange = rightX - leftX;
    auto Yrange = rightY - leftY;

    auto Xdelta = X - leftX;
    auto kX = Xdelta / Xrange;
    auto Ydelta = Yrange * kX;

    return leftY + Ydelta;
}
