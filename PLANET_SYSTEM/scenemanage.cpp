#include "scenemanage.h"

SceneManage::SceneManage(QObject* parent)
    : QObject{ parent }
{
    this->num = 0;
    this->previousViewR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->previousViewT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);
    this->previousView = Matrix4f::createLookAt(Vector3f(0.0f, 0.0f, 3.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));

    this->Projection = Matrix4f::createFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 100.0f);
    this->View = Matrix4f::createLookAt(Vector3f(0.0f, 0.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 1.0f, 0.0f));
    this->ViewR = Matrix4f::createRotationAroundAxis(0.0f, 0.0f, 0.0f);
    this->ViewT = Matrix4f::createTranslation(0.0f, 0.0f, 0.0f);

}

void GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        qDebug() << "[OpenGL Error](" << error << ")function" <<
            " " << file << ";" << line;
        return false;
    }
    return true;
}

void SceneManage::addItem(GraphicsItem item)
{
    this->ra.push_back(item);
    this->num++;
}

void SceneManage::render(Mesh mesh, Matrix4f ModelS, Matrix4f ModelR, Matrix4f ModelT, std::vector<ShaderInfo> shaders)
{
    GLuint vao, vbo, ibo, program, s[7], texture, tbo;
    glCreateVertexArrays(1, &vao); //创建vao
    glBindVertexArray(vao);  //绑定
    glCreateBuffers(1, &vbo);  //创建vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);  //绑定
    glNamedBufferStorage(vbo, sizeof(GLfloat) * mesh.verNum, mesh.vertices, 0);  //给vbo分配存储空间并设置数据
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);  //规定数据排列
    glEnableVertexAttribArray(0);  //激活顶点属性
    glCreateBuffers(1, &ibo);  //创建ibo
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo); //绑定
    glNamedBufferStorage(ibo, sizeof(GLuint) * mesh.indNum, mesh.indices, 0);  //给ibo分配存储空间并设置数据
    
   
    program = glCreateProgram();  //创建着色器程序
    for (int i = 0; i < shaders.size(); i++)
    {
        std::string source = getSource(shaders[i].filename);
        s[i] = glCreateShader(shaders[i].type);
        const char* c = source.c_str();
        glCALL(glShaderSource(s[i], 1, &c, NULL));
        glCALL(glCompileShader(s[i]));    //编译
        glCALL(glAttachShader(program, s[i]));  //关联到program
    }
    glCALL(glLinkProgram(program));  //链接
    glCALL(glUseProgram(program));   //使用

    
    if (mesh.texData)
    {
        glCreateBuffers(1, &tbo);
        glBindBuffer(GL_ARRAY_BUFFER, tbo);
        glNamedBufferStorage(tbo, sizeof(GLfloat) * mesh.texNum, mesh.texCoords, 0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(1);

        glCreateTextures(GL_TEXTURE_2D, 1, &texture);  //创建纹理对象
        glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);  //参数设置
        glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glCALL(glTextureStorage2D(texture, 1, GL_RGBA12, mesh.texWidth, mesh.texHeight)); //分配空间 
        glTextureSubImage2D(texture, 0, 0, 0, mesh.texWidth, mesh.texHeight, GL_RGBA, GL_UNSIGNED_BYTE, mesh.texData);  //传入数据
        glBindTextureUnit(0, texture);  //这里第一个参数根据该图形纹理数量依次绑定
        glUniform1i(glGetUniformLocation(program, std::string("tex").c_str()), 0); //传递采样器单元值

    }
   

    //Matrix4f View = this->ViewR * this->ViewT;   //场景维护视图矩阵变换
    Matrix4f Model = ModelS * ModelR * ModelT;  //图形项维护模型矩阵变换
    GLuint location = glGetUniformLocation(program, std::string("Model").c_str());
    glCALL(glUniformMatrix4fv(location, 1, GL_FALSE, Model));
    location = glGetUniformLocation(program, std::string("View").c_str());
    glCALL(glUniformMatrix4fv(location, 1, GL_FALSE, this->View));
    location = glGetUniformLocation(program, std::string("Projection").c_str());
    glCALL(glUniformMatrix4fv(location, 1, GL_FALSE, this->Projection));

    /*if (item.selected == true)  //图形选中加粗
        glLineWidth(3.0f);
    else
        glLineWidth(1.0f);*/

    glCALL(glDrawElements(GL_TRIANGLES, mesh.indNum, GL_UNSIGNED_INT, 0)); //绘制

    glDeleteBuffers(1, &vbo);
    if(glIsBuffer(tbo))
        glDeleteBuffers(1, &tbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &ibo);
    if(glIsTexture(texture))
        glDeleteTextures(1, &texture);
    glDeleteProgram(program);
}

void SceneManage::renderLoop()
{
    std::vector<GraphicsItem> r = ra;
    for (auto i = r.begin(); i != r.end(); i++)
    {
        for (auto j = i->meshes.begin(); j != i->meshes.end(); j++)
            render(*j, i->ModelS, i->ModelR, i->ModelT, i->shaders);
    }
}

std::string SceneManage::getSource(std::string filename)  //利用QString读取总是出问题，shader文件的读取还是用std::string
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        qDebug() << "文件打开失败";
        return " ";
    }
    std::string source;
    std::string line;
    while (!file.eof())
    {
        std::getline(file, line);
        source += line + '\n';
    }
    return source;
}

void SceneManage::setViewR(float angleX, float angleY)
{
    this->ViewR = this->previousViewR * Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f);  //累加上一次变化的状态
    this->previousViewR = this->ViewR;
    for (int i = 0; i < this->num; i++)
    {
        GraphicsItem::updateVertices(Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f), this->ra[i].bbox.maxVer.x, this->ra[i].bbox.maxVer.y, this->ra[i].bbox.maxVer.z);
        GraphicsItem::updateVertices(Matrix4f::createRotationAroundAxis(angleX, angleY, 0.0f), this->ra[i].bbox.minVer.x, this->ra[i].bbox.minVer.y, this->ra[i].bbox.minVer.z);
    }
}

void SceneManage::setViewT(float x, float y, float z)
{
    this->ViewT = this->previousViewT * Matrix4f::createTranslation(x, y, z);
    this->previousViewT = this->ViewT;
    for (int i = 0; i < this->num; i++)
    {
        GraphicsItem::updateVertices(Matrix4f::createTranslation(x, y, z), this->ra[i].bbox.maxVer.x, this->ra[i].bbox.maxVer.y, this->ra[i].bbox.maxVer.z);
        GraphicsItem::updateVertices(Matrix4f::createTranslation(x, y, z), this->ra[i].bbox.minVer.x, this->ra[i].bbox.minVer.y, this->ra[i].bbox.minVer.z);
    }
}

void SceneManage::do_keyPress(int key)
{
    if (!VM_Flag)
    {
        if (key == Qt::Key_A)
            this->setViewT(-0.02f, 0.0f, 0.0f);
        else if (key == Qt::Key_D)
            this->setViewT(0.02f, 0.0f, 0.0f);
        else if (key == Qt::Key_W)
            this->setViewT(0.0f, 0.0f, -0.02f);
        else if (key == Qt::Key_S)
            this->setViewT(0.0f, 0.0f, 0.02f);
        else if (key == Qt::Key_Space)
            this->setViewT(0.0f, 0.02f, 0.0f);
        else if (key == Qt::Key_Control)
            this->setViewT(0.0f, -0.02f, 0.0f);
    }
    else if (VM_Flag)
    {
        for (int i = 0; i < this->num; i++)
        {
            qDebug() << this->ra[i].selected;
            if (this->ra[i].selected == true)
            {
                if (key == Qt::Key_A)
                    this->ra[i].setModelT(-0.02f, 0.0f, 0.0f);
                else if (key == Qt::Key_D)
                    this->ra[i].setModelT(0.02f, 0.0f, 0.0f);
                else if (key == Qt::Key_W)
                    this->ra[i].setModelT(0.0f, 0.0f, -0.02f);
                else if (key == Qt::Key_S)
                    this->ra[i].setModelT(0.0f, 0.0f, 0.02f);
                else if (key == Qt::Key_Space)
                    this->ra[i].setModelT(0.0f, 0.02f, 0.0f);
                else if (key == Qt::Key_Control)
                    this->ra[i].setModelT(0.0f, -0.02f, 0.0f);
            }
        }
    }

    emit updateOpenglWidget();
}

void SceneManage::do_mouseMove(float angleX, float angleY)
{
    //VM_Flag为false,场景设置其View矩阵，如下
    if (!VM_Flag)
    {
        this->setViewR(angleX, angleY);
    }
    else if (VM_Flag)    //为true，对场景当前图形项currentItem设置ModelR矩阵，设置之前调用scene->checkIntersection遍历图形项检测相交，相交则不应用，否则应用
    {
        for (int i = 0; i < this->num; i++)
        {
            qDebug() << this->ra[i].selected;
            if (this->ra[i].selected == true)
            {
                this->ra[i].setModelR(angleX, angleY);
            }
        }
    }

    emit updateOpenglWidget();
}

void SceneManage::do_hSliderX_valueChanged(int value)
{
    if (!VM_Flag)
    {
        this->setViewR(value, 0);
    }
    else if (VM_Flag)
    {
        for (int i = 0; i < this->num; i++)
        {
            qDebug() << this->ra[i].selected;
            if (this->ra[i].selected == true)
            {
                this->ra[i].setModelR(value, 0);
            }
        }
    }

    emit updateOpenglWidget();
}

void SceneManage::do_hSliderY_valueChanged(int value)
{
    if (!VM_Flag)
    {
        this->setViewR(0, value);
    }
    else if (VM_Flag)
    {
        for (int i = 0; i < this->num; i++)
        {
            qDebug() << this->ra[i].selected;
            if (this->ra[i].selected == true)
            {
                this->ra[i].setModelR(0, value);
            }
        }
    }

    emit updateOpenglWidget();
}

void SceneManage::do_mousePress(double x, double y)
{
    //判断当前点是否在图形项中，是则VM_Flag = true, 图形项被选中设为true, 否则VM_Flag = false
    VM_Flag = false;
    for (int i = 0; i < this->num; i++)
    {
        if (x < this->ra[i].bbox.maxVer.x && y < this->ra[i].bbox.maxVer.y && x > this->ra[i].bbox.minVer.x && y > this->ra[i].bbox.minVer.y)
        {
            VM_Flag = true;
            this->ra[i].selected = true;  //图形项设置被选中
            this->currentItem = &(this->ra[i]);
        }
        else
        {
            this->ra[i].selected = false;
            this->currentItem = NULL;
        }
    }
    qDebug() << VM_Flag;

    emit updateOpenglWidget();
}

