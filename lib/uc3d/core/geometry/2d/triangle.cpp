#include "triangle.hpp"

Triangle2D::Triangle2D() : p1(), p2(), p3(), Shape(Vector2D(), Vector2D()) {}

Triangle2D::Triangle2D(const Vector2D& p1In,
                       const Vector2D& p2In,
                       const Vector2D& p3In)
    : p1(p1In), p2(p2In), p3(p3In), 
    Shape(
        Vector2D((p1.X + p2.X + p3.X) / 3.0f, (p1.Y + p2.Y + p3.Y) / 3.0f), 
        Vector2D(Mathematics::Max(p1.X, p2.X, p3.X) - Mathematics::Min(p1.X, p2.X, p3.X), 
                 Mathematics::Max(p1.Y, p2.Y, p3.Y) - Mathematics::Min(p1.Y, p2.Y, p3.Y) )
    ) {}

float Triangle2D::GetArea() const {
    return 0.5f * ((p2.X - p1.X) * (p3.Y - p1.Y) -
                   (p3.X - p1.X) * (p2.Y - p1.Y));
}

Vector2D Triangle2D::GetCentroid() const {
    return Vector2D{ (p1.X + p2.X + p3.X) / 3.0f,
                     (p1.Y + p2.Y + p3.Y) / 3.0f };
}

bool Triangle2D::IsInShape(Vector2D point) {
    float dX = point.X - p3.X;
    float dY = point.Y - p3.Y;
    float dX21 = p3.X - p2.X;
    float dY12 = p2.Y - p3.Y;
    float dY31 = p3.Y - p1.Y;
    float dX13 = p1.X - p3.X;
    float denom = dY12 * dX13 + dX21 * dY31;
    float a = (dY12 * dX + dX21 * dY) / denom;
    float b = (dY31 * dX + dX13 * dY) / denom;
    float c = 1.0f - a - b;

    return a >= 0.0f && b >= 0.0f && c >= 0.0f;
}
