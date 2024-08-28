#pragma once
#include "glad/glad.h"
#include "vmath/vmath.h"
#include "boundingbox.h"
#include "stb_image.h"


class Mesh
{
public:
    GLfloat* vertices;  //顶点
    GLuint* indices;    //索引
    GLfloat* texCoords;  //纹理坐标
    void* texData = NULL; //加载的纹理数据
    std::string texFilename; //纹理图片路径
    int texWidth, texHeight, texNRChannels;  //加载的纹理数据宽高及通道数
    int verNum = 0, indNum = 0, texNum = 0;  //顶点数量，索引数量, 纹理数量

    Mesh();
    void Normalized();   //对顶点坐标标准化
    void loadTexture();  //加载纹理
};

