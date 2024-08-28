#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include "scenemanage.h"
#include "cube.h"
#include "triangle.h"
#include <QOpenGLWidget>
#include <QObject>
#include <QMouseEvent>
#include <QKeyEvent>



class MyOpenglWidget : public QOpenGLWidget
{
    Q_OBJECT
private:
    SceneManage* scene;
    QPointF startPos;  //��㣬���ڼ�������ƶ���Ӧ�ĽǶȱ任 
    float sensitivity = 0.02f;  //�Ƕȱ任������
public:
    MyOpenglWidget(QWidget *parent = nullptr);
    inline SceneManage* getScene() { return scene; };  //���س�������
protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
signals:
    void mousePress(double x, double y);
    void keyPress(int key);
    void mouseMove(float angleX, float angleY);
};

#endif // MYOPENGLWIDGET_H
