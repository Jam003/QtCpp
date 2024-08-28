#include "triangle.h"

Triangle::Triangle()
{
    Mesh mesh;
    mesh.vertices = new GLfloat[9];
    mesh.indices = new GLuint[3];
    mesh.texCoords = new GLfloat[6];
    GLfloat v[9] = {-0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f};
    GLuint e[3] = {0, 1, 2};
    GLfloat t[6] = { 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f };
    memcpy(mesh.vertices, v, sizeof(GLfloat) * 9);
    memcpy(mesh.indices, e, sizeof(GLuint) * 3);
    memcpy(mesh.texCoords, t, sizeof(GLfloat) * 6);
    mesh.verNum = 9;
    mesh.indNum = 3;
    mesh.texNum = 6;
    mesh.texFilename = "D:\\QtProgram\\PLANET_SYSTEM\\textures\\flower.jpg";
    mesh.loadTexture();
    this->meshes.push_back(mesh);

    this->shaders.push_back({GL_VERTEX_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\triangles.vert"});
    this->shaders.push_back({GL_FRAGMENT_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\triangles.frag"});
    this->ModelR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->ModelS = Matrix4f::createScale(1.0f, 1.0f, 1.0f);
    this->ModelT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);
    
    InitialBoundingBox();
}
