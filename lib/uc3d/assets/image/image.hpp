/**
 * @file Image.h
 * @brief Defines an `Image` material for rendering images as textures in 3D rendering.
 *
 * The `Image` class is used to represent and manipulate image-based materials,
 * allowing for dynamic transformations such as resizing, positioning, and rotating
 * an image, as well as applying hue shifts.
 *
 * @date 22/12/2024
 * @author Coela Can't
 */

#pragma once

#include "../../core/math/vector2d.hpp" // 2D vector operations.
#include "../../core/math/mathematics.hpp" // Mathematical utilities.
#include "../../core/color/rgbcolor.hpp"

/**
 * @class Image
 * @brief Represents an image-based material with support for transformations and palette adjustments.
 */
class Image {
public:
    Vector2D size; ///< The size of the image.
    Vector2D offset; ///< The offset position of the image.
    float angle = 0.0f; ///< The rotation angle of the image in degrees.
    unsigned int xPixels = 0; ///< The width of the image in pixels.
    unsigned int yPixels = 0; ///< The height of the image in pixels.
    const uint8_t* data; ///< Pointer to the image data.
    const uint8_t* rgbColors; ///< Pointer to the color palette.
    uint8_t colors; ///< The number of colors in the palette.

    /**
     * @brief Constructs an `Image` material.
     *
     * @param data Pointer to the image data.
     * @param rgbColors Pointer to the color palette.
     * @param xPixels Width of the image in pixels.
     * @param yPixels Height of the image in pixels.
     * @param colors Number of colors in the palette.
     */
    Image(const uint8_t* data, const uint8_t* rgbColors, unsigned int xPixels, unsigned int yPixels, uint8_t colors);

    /**
     * @brief Destructor for `Image`.
     */
    ~Image() {}

    /**
     * @brief Sets the image data.
     *
     * @param data Pointer to the new image data.
     */
    void SetData(const uint8_t* data);

    /**
     * @brief Sets the color palette.
     *
     * @param rgbColors Pointer to the new color palette.
     */
    void SetColorPalette(const uint8_t* rgbColors);

    /**
     * @brief Sets the size of the image.
     *
     * @param size The new size as a `Vector2D`.
     */
    void SetSize(Vector2D size);

    /**
     * @brief Sets the position offset of the image.
     *
     * @param offset The new offset as a `Vector2D`.
     */
    void SetPosition(Vector2D offset);

    /**
     * @brief Sets the rotation angle of the image.
     *
     * @param angle The new rotation angle in degrees.
     */
    void SetRotation(float angle);

    /**
     * @brief Gets the color at an xy coordinate
     *
     * @param point the point in space to retrieve the color
     */
    RGBColor GetColorAtCoordinate(Vector2D point);
};
