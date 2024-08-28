#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H
#include "Mesh.h"
#include <QVector>
#include <QDebug>


struct ShaderInfo
{
    GLenum type;
    std::string filename;
};  //着色器信息换成需使用的着色器编号


class GraphicsItem
{
public:
    bool selected;  //是否被选中
    Matrix4f previousModelR;  //上一步旋转矩阵
    Matrix4f previousModelT;  //上一步平移矩阵
    Matrix4f ModelT, ModelR, ModelS;  //当前变换矩阵
    float M_X = 0, M_Y = 0, M_Z = 0; //Model的三个方向的平移变换量，用于可视化显示
    std::vector<ShaderInfo> shaders;  //着色器程序
    BoundingBox bbox;  //边界框
    std::vector<Mesh> meshes;  //网格
    //std::vector<GraphicsItem> children; //孩子节点
public:
    GraphicsItem();
    ~GraphicsItem();
    void InitialBoundingBox(); //初始化边界框
    void setModelT(float x, float y, float z);
    void setModelR(float angleX, float angleY);
    static void updateVertices(Matrix4f matrix, float& x, float& y, float& z);  //根据矩阵更新顶点数据
};

#endif // GRAPHICSITEM_H
