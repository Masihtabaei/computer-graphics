#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "My First Fancy Triangle (21.05.2024 | 03:02)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "You can not initialize GLEW without having a valid OpenGL context!" << std::endl;
    }

    std::cout << "Your OpenGL version: " << glGetString(GL_VERSION) << std::endl;


    float positionsOfVertices[6] = 
    {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };
    // Generating one buffer for the vertices of our triangle
    unsigned int triangleVerticesBufferId;
    glGenBuffers(1, &triangleVerticesBufferId);

    // Binding the generated buffer
    glBindBuffer(GL_ARRAY_BUFFER, triangleVerticesBufferId);

    // Providing the data
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positionsOfVertices, GL_STATIC_DRAW);


    // Specifying the layout of our vertex buffer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    // Enabling the vertex array containing the positions of vertices
    glEnableVertexAttribArray(triangleVerticesBufferId);



    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        // Drawing a traingle using legacy OpenGL-code
        glClear(GL_COLOR_BUFFER_BIT);
       // glBegin(GL_TRIANGLES);
       // glVertex2f(-0.5f, -0.5f);
       // glVertex2f(0.0f, 0.5f);
       // glVertex2f(0.5f, -0.5f);
       // glEnd();

        // Drawing a point using legacy OpenGL-Code
        // glPointSize(10);
        // glColor3f(0, 1, 0);
        // for (int i = 0; i < 199; i++)
        // {
        //    glBegin(GL_POINTS);
        //    glVertex2f(-1.0f, -1 + i * 0.01f);
        //    glEnd();
        // }

        // Issuing a draw call
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}