#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openglW = new MyOpenglWidget(this);

    QSurfaceFormat format;
    format.setSwapInterval(1);
    openglW->setFormat(format);  //设置垂直同步

    openglW->setGeometry(100, 100, 400, 400);

    connect(openglW->getScene(), &SceneManage::updateOpenglWidget, this, &MainWindow::do_update);
    connect(ui->btnFileSelect, &QPushButton::clicked, this, &MainWindow::do_btnFileSelect_clicked);
    connect(ui->btnTexSelect, &QPushButton::clicked, this, &MainWindow::do_btnTexSelect_clicked);
    connect(ui->hSliderAngleX, &QAbstractSlider::valueChanged, openglW->getScene(), &SceneManage::do_hSliderX_valueChanged);
    connect(ui->hSliderAngleY, &QAbstractSlider::valueChanged, openglW->getScene(), &SceneManage::do_hSliderY_valueChanged);
    connect(ui->hSliderAngleX, &QAbstractSlider::valueChanged, this, &MainWindow::do_hSliderAngleX_valueChanged);
    connect(ui->hSliderAngleY, &QAbstractSlider::valueChanged, this, &MainWindow::do_hSliderAngleY_valueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_btnFileSelect_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "选择一个文件", QDir::currentPath(), "模型文件(*.obj)");
    //文件选择完毕后，利用assimp得到渲染所需数据
    GraphicsItem item; //创建一个图形项对象，将数据导入

    Assimp::Importer import;
    const aiScene* scene = import.ReadFile(filename.toStdString(), aiProcess_Triangulate | aiProcess_FlipUVs);  //assimp导入模型文件，scene对象中包含模型所有部分网格的信息
    for (int i = 0; i < scene->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[i];
        Mesh m;
        m.verNum = 0;
        m.indNum = 0;
        
        m.vertices = new GLfloat[mesh->mNumVertices * 3];
        m.indices = new GLuint[mesh->mNumFaces * 3];
        

        for (int i = 0; i < mesh->mNumVertices; i++)
        {
            m.vertices[m.verNum++] = mesh->mVertices[i].x;
            m.vertices[m.verNum++] = mesh->mVertices[i].y;
            m.vertices[m.verNum++] = mesh->mVertices[i].z;
        }
        for (int i = 0; i < mesh->mNumFaces; i++)
        {
            m.indices[m.indNum++] = mesh->mFaces[i].mIndices[0];
            m.indices[m.indNum++] = mesh->mFaces[i].mIndices[1];
            m.indices[m.indNum++] = mesh->mFaces[i].mIndices[2];
        }
        if(mesh->mNumUVComponents[0] == 2)
        {
            m.texNum = 0;
            m.texCoords = new GLfloat[mesh->mNumVertices * 2];

            for (int i = 0; i < mesh->mNumVertices; i++)
            {
                m.texCoords[m.texNum++] = mesh->mTextureCoords[i]->x;
                m.texCoords[m.texNum++] = mesh->mTextureCoords[i]->y;
            }

            aiString* filepath;
            scene->mMaterials[mesh->mMaterialIndex]->GetTexture(aiTextureType_DIFFUSE, 0, filepath);

            m.texFilename = std::string(filepath->data);
            m.loadTexture();
        }

        m.Normalized();
        item.meshes.push_back(m);
    }
    item.InitialBoundingBox();

    item.shaders.push_back({ GL_VERTEX_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\notexture.vert" });
    item.shaders.push_back({ GL_FRAGMENT_SHADER, "D:\\QtProgram\\PLANET_SYSTEM\\notexture.frag" });
   
    this->openglW->getScene()->addItem(item); 
}

void MainWindow::do_btnTexSelect_clicked()
{
    GraphicsItem* item = this->openglW->getScene()->getCurrentItem();
    if(item != NULL)
    {
        QString filename = QFileDialog::getOpenFileName(this, "选择一个文件", QDir::currentPath(), "(*.jpg)");
        //item->texFilename = filename.toStdString();
        //item->loadTexture();
    }
    item = NULL;  
}

void MainWindow::do_hSliderAngleX_valueChanged(int value)
{
    ui->lineEditAngleX->setText(QString::number(value));
}

void MainWindow::do_hSliderAngleY_valueChanged(int value)
{
    ui->lineEditAngleY->setText(QString::number(value));
}

void MainWindow::do_update()
{
    this->openglW->update();
}

