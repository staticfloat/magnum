/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "Sphere.h"

#include "Math/Functions.h"
#include "Math/Matrix3.h"
#include "Math/Matrix4.h"
#include "Math/Geometry/Distance.h"
#include "LineSegment.h"
#include "Point.h"

using namespace Magnum::Math::Geometry;

namespace Magnum { namespace Physics {

namespace {
    template<UnsignedInt dimensions> static typename DimensionTraits<dimensions>::VectorType unitVector();

    template<> inline Vector2 unitVector<2>() {
        return Vector2(1/Constants::sqrt2());
    }

    template<> inline Vector3 unitVector<3>() {
        return Vector3(1/Constants::sqrt3());
    }
}

template<UnsignedInt dimensions> void Sphere<dimensions>::applyTransformationMatrix(const typename DimensionTraits<dimensions>::MatrixType& matrix) {
    _transformedPosition = matrix.transformPoint(_position);
    Float scaling = (matrix.rotationScaling()*unitVector<dimensions>()).length();
    _transformedRadius = scaling*_radius;
}

template<UnsignedInt dimensions> bool Sphere<dimensions>::collides(const AbstractShape<dimensions>* other) const {
    if(other->type() == AbstractShape<dimensions>::Type::Point)
        return *this % *static_cast<const Point<dimensions>*>(other);
    if(other->type() == AbstractShape<dimensions>::Type::Line)
        return *this % *static_cast<const Line<dimensions>*>(other);
    if(other->type() == AbstractShape<dimensions>::Type::LineSegment)
        return *this % *static_cast<const LineSegment<dimensions>*>(other);
    if(other->type() == AbstractShape<dimensions>::Type::Sphere)
        return *this % *static_cast<const Sphere<dimensions>*>(other);

    return AbstractShape<dimensions>::collides(other);
}

template<UnsignedInt dimensions> bool Sphere<dimensions>::operator%(const Point<dimensions>& other) const {
    return (other.transformedPosition()-transformedPosition()).dot() <
        Math::pow<2>(transformedRadius());
}

template<UnsignedInt dimensions> bool Sphere<dimensions>::operator%(const Line<dimensions>& other) const {
    return Distance::linePointSquared(other.transformedA(), other.transformedB(), transformedPosition()) <
        Math::pow<2>(transformedRadius());
}

template<UnsignedInt dimensions> bool Sphere<dimensions>::operator%(const LineSegment<dimensions>& other) const {
    return Distance::lineSegmentPointSquared(other.transformedA(), other.transformedB(), transformedPosition()) <
        Math::pow<2>(transformedRadius());
}

template<UnsignedInt dimensions> bool Sphere<dimensions>::operator%(const Sphere<dimensions>& other) const {
    return (other.transformedPosition()-transformedPosition()).dot() <
        Math::pow<2>(transformedRadius()+other.transformedRadius());
}

template class MAGNUM_PHYSICS_EXPORT Sphere<2>;
template class MAGNUM_PHYSICS_EXPORT Sphere<3>;

}}
