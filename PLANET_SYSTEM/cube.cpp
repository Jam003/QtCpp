#include "cube.h"

Cube::Cube()
{
    Mesh mesh;
    GLfloat v[24] = {-0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f};
    GLuint e[24] = {0, 1, 2, 3, 4, 5, 6, 7, 4, 0, 3, 7, 1, 5, 6, 2, 3, 2, 6, 7, 4, 5, 1, 0};
    memcpy(mesh.vertices, v, sizeof(GLfloat) * 24);
    memcpy(mesh.indices, e, sizeof(GLuint) * 24);
    mesh.verNum = 24;
    mesh.indNum = 24;
    this->meshes.push_back(mesh);

    this->shaders.push_back({GL_VERTEX_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\triangles.vert"});
    this->shaders.push_back({GL_FRAGMENT_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\triangles.frag"});
    this->ModelR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->ModelS = Matrix4f::createScale(1.0f, 1.0f, 1.0f);
    this->ModelT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);


    InitialBoundingBox();
}
