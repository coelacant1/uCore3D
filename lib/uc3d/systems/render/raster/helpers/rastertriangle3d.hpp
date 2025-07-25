/**
 * @file rastertriangle3d.hpp
 * @brief A lightweight, pointer-based 3D triangle for rendering pipelines.
 * @date  26/06/2025
 * @author Coela Can't
 */
#pragma once

#include "../../../../core/math/vector3d.hpp"
#include "../../../../core/math/vector2d.hpp"

/**
 * @class RasterTriangle3D
 * @brief Represents a triangle by holding pointers to vertex data in a mesh.
 *
 * This class is designed for efficiency in rendering. It does not own the
 * vertex or UV data, but rather points to it. It also holds rendering-specific
 * data like material pointers and pre-calculated edges and normal.
 */
class RasterTriangle3D {
public:
    // --- Pointers to mesh data ---
    const Vector3D* p1;
    const Vector3D* p2;
    const Vector3D* p3;
    const Vector2D* uv1;
    const Vector2D* uv2;
    const Vector2D* uv3;

    // --- Pre-calculated data for performance ---
    Vector3D edge1;
    Vector3D edge2;
    Vector3D normal;
    bool hasUV;

    /** @brief Default constructor. Initializes all pointers to nullptr. */
    RasterTriangle3D();

    /**
     * @brief Constructs a raster triangle from pointers to mesh data.
     * @param v1 Pointer to the first vertex.
     * @param v2 Pointer to the second vertex.
     * @param v3 Pointer to the third vertex.
     */
    RasterTriangle3D(const Vector3D* v1, const Vector3D* v2, const Vector3D* v3);

    /**
     * @brief Constructs a raster triangle from pointers to mesh data.
     * @param v1 Pointer to the first vertex.
     * @param v2 Pointer to the second vertex.
     * @param v3 Pointer to the third vertex.
     */
    RasterTriangle3D(const Vector3D* v1, const Vector3D* v2, const Vector3D* v3,
                     const Vector2D* t1, const Vector2D* t2, const Vector2D* t3);

    /**
     * @brief Performs a ray-triangle intersection test.
     * @param rayOrigin The starting point of the ray.
     * @param rayDir The normalized direction of the ray.
     * @param out_t [out] The distance along the ray to the intersection point.
     * @param out_u [out] The barycentric coordinate 'u' of the intersection.
     * @param out_v [out] The barycentric coordinate 'v' of the intersection.
     * @return true if the ray intersects the triangle, false otherwise.
     */
    bool IntersectsRay(const Vector3D& rayOrigin, const Vector3D& rayDir,
                       float& out_t, float& out_u, float& out_v) const;

    /** @brief Returns a pointer to the pre-calculated normal vector. */
    const Vector3D& GetNormal() const;
};
