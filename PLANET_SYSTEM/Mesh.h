#pragma once
#include "glad/glad.h"
#include "vmath/vmath.h"
#include "boundingbox.h"
#include "stb_image.h"


class Mesh
{
public:
    GLfloat* vertices;  //����
    GLuint* indices;    //����
    GLfloat* texCoords;  //��������
    void* texData = NULL; //���ص���������
    std::string texFilename; //����ͼƬ·��
    int texWidth, texHeight, texNRChannels;  //���ص��������ݿ�߼�ͨ����
    int verNum = 0, indNum = 0, texNum = 0;  //������������������, ��������

    Mesh();
    void Normalized();   //�Զ��������׼��
    void loadTexture();  //��������
};

