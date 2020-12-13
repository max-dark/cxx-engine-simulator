//
// Created by max on 13.12.2020.
//

#ifndef ENGINESIMULATOR_LIB_ENGINE_POINTWISELINEARFUNCTION_HXX
#define ENGINESIMULATOR_LIB_ENGINE_POINTWISELINEARFUNCTION_HXX


#include <vector>
#include <utility>

/// \brief X/Y pair
/// first - X
/// second - Y
using XYPair = std::pair<double, double>;

/// \brief X/Y data for piecewise linear function
using XYData = std::vector<XYPair>;

class PiecewiseLinearFunction
{
public:
    void addPoint(double x, double y);
    void setPoints(XYData points);
    void clear();
    void sortPoints();

    [[nodiscard]] const XYPair &first() const;
    [[nodiscard]] const XYPair &last() const;


    [[nodiscard]] double calculate(double X) const;
private:
    XYData data;
};


#endif //ENGINESIMULATOR_LIB_ENGINE_POINTWISELINEARFUNCTION_HXX
