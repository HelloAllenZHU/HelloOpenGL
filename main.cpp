#include "Widget.h"
#include <QApplication>

/*
 * OpenGL demo
 * 1、初始化
 * 2、设置
 * 3、绘图
 * 4、释放
 */

void framebuffer_size_callback( GLFWwindow *window, int width, int height )
{
    // 设置视口的位置和大小
    glViewport( 0, 0, width, height );
}

void processInput( GLFWwindow *window )
{
    if( glfwGetKey( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS )
        glfwSetWindowShouldClose( window, true );
}

int main(int argc, char *argv[])
{
    // 初始化和配置
    glfwInit();
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

#ifdef __APPLE__
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
#endif

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow( 800, 600, "HelloOpenGL", nullptr, nullptr );
    if ( window == nullptr ) {
        glfwTerminate();
        return -1;
    }

    // 设置当前窗口上下文
    glfwMakeContextCurrent( window );
    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );

    // 使用glad加载OpenGL的函数指针
    if ( !gladLoadGLLoader( ( GLADloadproc )glfwGetProcAddress ) ) {
        return -1;
    }

    // 窗口的事件循环
    while( !glfwWindowShouldClose( window ) ) {
        // 输入
        processInput( window );

        // 渲染
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        // buffer交换、事件处理
        glfwSwapBuffers( window );
        glfwPollEvents();
    }

    // 销毁opgengl
    glfwTerminate();
    return 0;
}
