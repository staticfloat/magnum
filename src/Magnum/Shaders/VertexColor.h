#ifndef Magnum_Shaders_VertexColor_h
#define Magnum_Shaders_VertexColor_h
/*
    This file is part of Magnum.

    Copyright © 2010, 2011, 2012, 2013, 2014, 2015
              Vladimír Vondruš <mosra@centrum.cz>

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

/** @file
 * @brief Class @ref Magnum::Shaders::VertexColor
 */

#include "Magnum/DimensionTraits.h"
#include "Magnum/Math/Color.h"
#include "Magnum/Math/Matrix3.h"
#include "Magnum/Math/Matrix4.h"
#include "Magnum/Shaders/Generic.h"
#include "Magnum/Shaders/visibility.h"

namespace Magnum { namespace Shaders {

/**
@brief Vertex color shader

Draws vertex-colored mesh. You need to provide @ref Position and @ref Color
attributes in your triangle mesh and call at least
@ref setTransformationProjectionMatrix().

@image html shaders-vertexcolor.png
@image latex shaders-vertexcolor.png

## Example usage

Common mesh setup:
@code
struct Vertex {
    Vector3 position;
    Color3 color;
};
Vertex data[] = { ... };

Buffer vertices;
vertices.setData(data, BufferUsage::StaticDraw);

Mesh mesh;
mesh.addVertexBuffer(vertices, 0,
    Shaders::VertexColor3D::Position{},
    Shaders::VertexColor3D::Color{});
@endcode

Common rendering setup:
@code
Matrix4 transformationMatrix = Matrix4::translation(Vector3::zAxis(-5.0f));
Matrix4 projectionMatrix = Matrix4::perspectiveProjection(35.0_degf, 1.0f, 0.001f, 100.0f);

Shaders::VertexColor3D shader;
shader.setTransformationProjectionMatrix(projectionMatrix*transformationMatrix);

mesh.draw(shader);
@endcode

@see @ref shaders, @ref VertexColor2D, @ref VertexColor3D
*/
template<UnsignedInt dimensions> class MAGNUM_SHADERS_EXPORT VertexColor: public AbstractShaderProgram {
    public:
        /**
         * @brief Vertex position
         *
         * @ref shaders-generic "Generic attribute", @ref Vector2 in 2D,
         * @ref Vector3 in 3D.
         */
        typedef typename Generic<dimensions>::Position Position;

        /**
         * @brief Vertex color
         *
         * @ref shaders-generic "Generic attribute", @ref Color3.
         */
        typedef typename Generic<dimensions>::Color Color;

        explicit VertexColor();

        /**
         * @brief Set transformation and projection matrix
         * @return Reference to self (for method chaining)
         *
         * Default is identity matrix.
         */
        VertexColor<dimensions>& setTransformationProjectionMatrix(const MatrixTypeFor<dimensions, Float>& matrix) {
            setUniform(transformationProjectionMatrixUniform, matrix);
            return *this;
        }

    private:
        Int transformationProjectionMatrixUniform;
};

/** @brief 2D vertex color shader */
typedef VertexColor<2> VertexColor2D;

/** @brief 3D vertex color shader */
typedef VertexColor<3> VertexColor3D;

}}

#endif
