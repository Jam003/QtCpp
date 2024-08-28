#include "Mesh.h"

Mesh::Mesh()
{
    
}

void Mesh::Normalized()
{
    float fx = -9999, fy = -9999, fz = -9999, sx = 9999, sy = 9999, sz = 9999;
    for (int i = 0; i < this->verNum; i += 3)
    {
        fx = std::max(this->vertices[i], fx);
        fy = std::max(this->vertices[i + 1], fy);
        fz = std::max(this->vertices[i + 2], fz);
        sx = std::min(this->vertices[i], sx);
        sy = std::min(this->vertices[i + 1], sy);
        sz = std::min(this->vertices[i + 2], sz);
    }
    float center_x = (fx + sx) / 2.0f;
    float center_y = (fy + sy) / 2.0f;
    float center_z = (fz + sz) / 2.0f;
    float scale_x = 2.0f / (fx - sx);
    float scale_y = 2.0f / (fy - sy);
    float scale_z = 2.0f / (fz - sz);

    for (int i = 0; i < this->verNum; i += 3)
    {
        this->vertices[i] = (this->vertices[i] - center_x) * scale_x;
        this->vertices[i + 1] = (this->vertices[i + 1] - center_y) * scale_y;
        this->vertices[i + 2] = (this->vertices[i + 2] - center_z) * scale_z;
    }
}

void Mesh::loadTexture()
{
    if (this->texData != NULL)
        stbi_image_free(this->texData);
    this->texData = stbi_load(this->texFilename.c_str(), &this->texWidth, &this->texHeight, &this->texNRChannels, 4);
}

