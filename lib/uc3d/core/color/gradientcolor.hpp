#pragma once

#include "rgbcolor.hpp"
#include "../math/mathematics.hpp"
#include <cstddef>

/**
 * @file GradientColor.hpp
 * @brief A utility class to calculate a color from a multi-stop gradient.
 * @date 29/06/2025
 * @author Coela Can't
 */

/**
 * @class GradientColor
 * @brief Represents a color gradient and calculates interpolated colors.
 *
 * This class stores a fixed number of color stops and can compute the
 * color at any given ratio (0.0 to 1.0) along the gradient. It supports
 * both smooth linear interpolation and stepped (solid color) transitions.
 *
 * @tparam colorCount The number of color stops in the gradient.
 */
template<size_t colorCount>
class GradientColor {
private:
    RGBColor colors[colorCount]; ///< The color stops of the gradient.
    bool isStepped;              ///< If true, transitions are hard steps instead of smooth.

public:
    /**
     * @brief Constructs a GradientColor object.
     * @param colorStops A pointer to an array of RGBColor objects.
     * @param stepped If true, the gradient will have hard steps.
     */
    GradientColor(const RGBColor* colorStops, bool stepped = false);

    /**
     * @brief Default constructor for empty initialization.
     */
    GradientColor();

    /**
     * @brief Calculates the color at a specific point along the gradient.
     * @param ratio A normalized value from 0.0 (start) to 1.0 (end) of the gradient.
     * @return The calculated RGBColor at that point.
     */
    RGBColor GetColorAt(float ratio) const;
    
    /**
     * @brief Updates the colors in the gradient.
     * @param newColorStops A pointer to the new array of RGBColor objects.
     */
    void SetColors(const RGBColor* newColorStops);
};

#include "gradientcolor.tpp"