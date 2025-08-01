/**
 * @file triangle3d.hpp
 * @brief A self-contained, value-based 3D triangle for pure geometric queries.
 * @date  26/06/2025
 * @author Coela Can't
 */
#pragma once

#include "../../math/vector3d.hpp"

/**
 * @class Triangle3D
 * @brief Represents a triangle in 3D space by storing its vertices by value.
 *
 * This class is designed for pure geometric calculations and is independent of any
 * rendering pipeline or ray intersection logic. It is immutable once created.
 */
class Triangle3D {
public:
    Vector3D p1; ///< First vertex.
    Vector3D p2; ///< Second vertex.
    Vector3D p3; ///< Third vertex.

    /** @brief Default constructor creates a degenerate triangle at the origin. */
    Triangle3D();

    /** @brief Constructs a triangle from three vertices. */
    Triangle3D(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3);

    /** @brief Calculates the surface area of the triangle. */
    float GetArea() const;

    /** @brief Calculates the normalized surface normal of the triangle. */
    Vector3D GetNormal() const;

    /** @brief Calculates the geometric center (centroid) of the triangle. */
    Vector3D GetCentroid() const;

    /**
     * @brief Finds the closest point on the surface of the triangle to a given point p.
     * @param p The point to test against.
     * @return The point on the triangle's surface closest to p.
     */
    Vector3D ClosestPoint(const Vector3D& p) const;
};