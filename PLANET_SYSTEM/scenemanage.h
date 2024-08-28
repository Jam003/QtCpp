#ifndef SCENEMANAGE_H
#define SCENEMANAGE_H

#include <QObject>
#include "graphicsitem.h"
#include <QFile>
#include <fstream>

#define ASSERT(x) if (!(x)) __debugbreak();
#define glCALL(x) GLClearError();\
x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

class SceneManage : public QObject
{
    Q_OBJECT
private:
    int num;  //图形项数量
    bool VM_Flag;  //VM的意思是应用View变换还是Model变换
    float V_X = 0, V_Y = 0, V_Z = 0;   //View的三个方向的平移变换量,暂时未用，可视化界面可能会用
    Matrix4f Projection;
    Matrix4f View;
    Matrix4f previousView;
    Matrix4f ViewT, ViewR;  //视图矩阵
    Matrix4f previousViewR;   //上一步的旋转矩阵，用于作为下一步旋转操作的基础
    Matrix4f previousViewT;
    std::vector<GraphicsItem> ra;  //渲染数组 
    GraphicsItem* currentItem = NULL;
public:
    explicit SceneManage(QObject *parent = nullptr);
    void addItem(GraphicsItem item);
    void render(Mesh item, Matrix4f ModelS, Matrix4f ModelR, Matrix4f ModelT, std::vector<ShaderInfo> shaders);
    void renderLoop();
    std::string getSource(std::string filename);
    void setViewR(float angleX, float angleY);
    void setViewT(float x, float y, float z);
    inline GraphicsItem* getCurrentItem() { return currentItem; };
    bool checkIntersection(BoundingBox bbox);  //相交检测
signals:
    void updateOpenglWidget();
public slots:
    void do_mousePress(double x, double y);
    void do_keyPress(int key);
    void do_mouseMove(float angleX, float angleY);
    void do_hSliderX_valueChanged(int value);  
    void do_hSliderY_valueChanged(int value);
};

#endif // SCENEMANAGE_H



