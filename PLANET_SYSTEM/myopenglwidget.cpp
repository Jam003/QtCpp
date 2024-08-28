#include "myopenglwidget.h"

MyOpenglWidget::MyOpenglWidget(QWidget *parent):QOpenGLWidget(parent)   //注意这里父类也需要初始化
{
    scene = new SceneManage(this);
    //Cube c;
    Triangle t;
    //scene->addItem(c);
    scene->addItem(t);

    this->setFocusPolicy(Qt::StrongFocus); //焦点策略，通过鼠标点击或者tab获得焦点，从而接收按键事件

    connect(this, &MyOpenglWidget::mousePress, this->scene, &SceneManage::do_mousePress);
    connect(this, &MyOpenglWidget::keyPress, this->scene, &SceneManage::do_keyPress);
    connect(this, &MyOpenglWidget::mouseMove, this->scene, &SceneManage::do_mouseMove);
}

void MyOpenglWidget::initializeGL()
{
    gladLoadGL();
}

void MyOpenglWidget::resizeGL(int width, int height)
{
    

}

void MyOpenglWidget::paintGL()
{
    static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    glClearBufferfv(GL_COLOR, 0, black);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    scene->renderLoop();
}

void MyOpenglWidget::mousePressEvent(QMouseEvent* event)
{
    QPointF pos = event->pos();
    startPos = pos;

    double x = (pos.x() - this->width() / static_cast<double>(2)) / (this->width() / static_cast<double>(2));
    double y = (this->height() / static_cast<double>(2) - pos.y()) / (this->height() / static_cast<double>(2)); //x，y标准化，-1到1之间

    emit mousePress(x, y);
}

void MyOpenglWidget::keyPressEvent(QKeyEvent* event)
{
    int key = event->key();
    
    emit keyPress(key);
}

void MyOpenglWidget::mouseMoveEvent(QMouseEvent* event)
{
    QPointF pos = event->pos();
    float maxAcceleration = 20.0f;
    float dx = pos.x() - startPos.x();
    float dy = pos.y() - startPos.y();
    float accelerationX = std::min(maxAcceleration, std::max(-maxAcceleration, dx));
    float accelerationY = std::min(maxAcceleration, std::max(-maxAcceleration, dy));  //限制旋转速度
    float angleX = accelerationY * sensitivity;
    float angleY = accelerationX * sensitivity;

    emit mouseMove(angleX, angleY);
}
