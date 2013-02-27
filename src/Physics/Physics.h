#ifndef Magnum_Physics_Physics_h
#define Magnum_Physics_Physics_h
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

/** @file
 * @brief Forward declarations for Magnum::Physics namespace
 */

#include "Types.h"

namespace Magnum { namespace Physics {

/** @todoc remove when doxygen is sane again */
#ifndef DOXYGEN_GENERATING_OUTPUT
template<UnsignedInt> class AbstractShape;
typedef AbstractShape<2> AbstractShape2D;
typedef AbstractShape<3> AbstractShape3D;

template<UnsignedInt> class AxisAlignedBox;
typedef AxisAlignedBox<2> AxisAlignedBox2D;
typedef AxisAlignedBox<3> AxisAlignedBox3D;

template<UnsignedInt> class Box;
typedef Box<2> Box2D;
typedef Box<3> Box3D;

template<UnsignedInt> class Capsule;
typedef Capsule<2> Capsule2D;
typedef Capsule<3> Capsule3D;

template<UnsignedInt> class Line;
typedef Line<2> Line2D;
typedef Line<3> Line3D;

template<UnsignedInt> class LineSegment;
typedef LineSegment<2> LineSegment2D;
typedef LineSegment<3> LineSegment3D;

template<UnsignedInt> class ObjectShape;
typedef ObjectShape<2> ObjectShape2D;
typedef ObjectShape<3> ObjectShape3D;

template<UnsignedInt> class ObjectShapeGroup;
typedef ObjectShapeGroup<2> ObjectShapeGroup2D;
typedef ObjectShapeGroup<3> ObjectShapeGroup3D;

class Plane;

template<UnsignedInt> class Point;
typedef Point<2> Point2D;
typedef Point<3> Point3D;

template<UnsignedInt> class ShapeGroup;
typedef ShapeGroup<2> ShapeGroup2D;
typedef ShapeGroup<3> ShapeGroup3D;

template<UnsignedInt> class Sphere;
typedef Sphere<2> Sphere2D;
typedef Sphere<3> Sphere3D;
#endif

}}

#endif
