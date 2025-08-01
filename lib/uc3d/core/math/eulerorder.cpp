#include "eulerorder.hpp"

// Default constructor.
EulerOrder::EulerOrder()
    : AxisOrder(Axis::XYZ),
      FrameTaken(AxisFrame::Static),
      Permutation(0, 1, 2) {}

// Parameterized constructor.
EulerOrder::EulerOrder(Axis axisOrder, AxisFrame axisFrame, Vector3D permutation)
    : AxisOrder(axisOrder),
      FrameTaken(axisFrame),
      Permutation(permutation) {}

// Convert EulerOrder to a string representation.
uc3d::UString EulerOrder::ToString() {
    return Permutation.ToString();
}
