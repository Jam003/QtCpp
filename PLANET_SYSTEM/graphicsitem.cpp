#include "graphicsitem.h"

GraphicsItem::GraphicsItem()
{
    //this->selected = false;
    this->previousModelR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->previousModelT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);
    this->ModelR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->ModelS = Matrix4f::createScale(1.0f, 1.0f, 1.0f);
    this->ModelT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);
}

GraphicsItem::~GraphicsItem()
{

}

void GraphicsItem::InitialBoundingBox()
{
    float fx = -99, fy = -99, fz = -99, sx = 99, sy = 99, sz = 99;
    for(auto it = this->meshes.begin(); it != this->meshes.end(); it++)
    {
        for (int i = 0; i < it->verNum; i += 3)
        {
            fx = std::max(it->vertices[i], fx);
            fy = std::max(it->vertices[i + 1], fy);
            fz = std::max(it->vertices[i + 2], fz);
            sx = std::min(it->vertices[i], sx);
            sy = std::min(it->vertices[i + 1], sy);
            sz = std::min(it->vertices[i + 2], sz);
        }
    }
    this->bbox.maxVer = ver(fx, fy, fz);
    this->bbox.minVer = ver(sx, sy, sz);
}


void GraphicsItem::setModelT(float x, float y, float z)
{
    this->ModelT = this->previousModelT * Matrix4f::createTranslation(x, y, z);
    this->previousModelT = this->ModelT;
    updateVertices(Matrix4f::createTranslation(x, y, z), this->bbox.maxVer.x, this->bbox.maxVer.y, this->bbox.maxVer.z);
    updateVertices(Matrix4f::createTranslation(x, y, z), this->bbox.minVer.x, this->bbox.minVer.y, this->bbox.minVer.z);
}

void GraphicsItem::setModelR(float angleX, float angleY)
{
    this->ModelR = this->previousModelR * Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f);
    this->previousModelR = this->ModelR;
    updateVertices(Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f), this->bbox.maxVer.x, this->bbox.maxVer.y, this->bbox.maxVer.z);
    updateVertices(Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f), this->bbox.minVer.x, this->bbox.minVer.y, this->bbox.minVer.z);
}

void GraphicsItem::updateVertices(Matrix4f matrix, float& x, float& y, float& z)
{
    qDebug() << x << y << z;
    Vector4f v = matrix * Vector4f(x, y, z, 1.0f);
    x = v.x;
    y = v.y;
    z = v.z;
    qDebug() << x << y << z;
}