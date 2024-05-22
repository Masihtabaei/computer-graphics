#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

static unsigned int createAndCompileTheShader(unsigned int shaderTypeToCreate, std::string& sourceCodeOfShaderToCreate)
{
    // Creating the shader
    unsigned int idOfTheCreatedShader = glCreateShader(shaderTypeToCreate);

    // Converting the string into a C-string (as desired by OpenGL)
    const char* sourceCodeOfShaderToCreateAsCString = sourceCodeOfShaderToCreate.c_str();
    // Attaching (actually replacing) the source code for the shader created previously
    glShaderSource(idOfTheCreatedShader, 1, &sourceCodeOfShaderToCreateAsCString, NULL);

    // Compiling the shader created previously
    glCompileShader(idOfTheCreatedShader);

    // Getting the compilation state of the shader compiled previously
    int compilationResult;
    glGetShaderiv(idOfTheCreatedShader, GL_COMPILE_STATUS, &compilationResult);
    // Checking whether something went wrong during the compilation
    if (compilationResult == GL_FALSE)
    {
        // Getting the length of the log message
        int lengthOfLogMessage;
        glGetShaderiv(idOfTheCreatedShader, GL_INFO_LOG_LENGTH, &lengthOfLogMessage);
        // Getting the actual log message
        char* logMessage = new char[lengthOfLogMessage];
        glGetShaderInfoLog(idOfTheCreatedShader, GL_INFO_LOG_LENGTH, &lengthOfLogMessage,logMessage);
        // Printing out the log message
        std::cout << "Compilation failed for" <<
            (shaderTypeToCreate == GL_VERTEX_SHADER ? " vertex " : " fragment ") << "with following error: "
            << logMessage << std::endl;
        delete[] logMessage;
        // Deleting the shader which could not get compiled successfully
        glDeleteShader(idOfTheCreatedShader);
        // Returning 0 to indicate that the compilation went wrong
        return 0;
    }

    // Returning id of the shader created and compiled successfully
    return idOfTheCreatedShader;

}

static unsigned int createTheVertexAndFragmentShader(std::string& vertexShaderSourceCode, std::string& fragmentShaderSourceCode)
{
    // Creating the program
    unsigned int idOfTheCreatedProgram = glCreateProgram();
    // Creating and compiling the vertex shader
    unsigned int vertexShaderId = createAndCompileTheShader(GL_VERTEX_SHADER, vertexShaderSourceCode);
    // Creating and compiling the fragment shader
    unsigned int fragmentShaderId = createAndCompileTheShader(GL_FRAGMENT_SHADER, fragmentShaderSourceCode);
    
    // Attaching the vertex shader to the program created previously
    glAttachShader(idOfTheCreatedProgram, vertexShaderId);
    // Attaching the fragment shader to the program created previously
    glAttachShader(idOfTheCreatedProgram, fragmentShaderId);

    // Linking the program
    glLinkProgram(idOfTheCreatedProgram);

    // Validating the program
    glValidateProgram(idOfTheCreatedProgram);

    int validationResult;
    glGetProgramiv(idOfTheCreatedProgram, GL_VALIDATE_STATUS, &validationResult);

    // Deleting the vertex shader
    glDeleteShader(vertexShaderId);
    // Deleting the fragment shader
    glDeleteShader(fragmentShaderId);


    if (validationResult == GL_FALSE)
    {
        // Getting the length of the log message
        int lengthOfLogMessage;
        glGetProgramiv(idOfTheCreatedProgram, GL_INFO_LOG_LENGTH, &lengthOfLogMessage);
        // Getting the actual log message
        char* logMessage = new char[lengthOfLogMessage];
        glGetProgramInfoLog(idOfTheCreatedProgram, GL_INFO_LOG_LENGTH, &lengthOfLogMessage, logMessage);
        // Printing out the log message
        std::cout << "Following problems were detected during validation:" << logMessage << std::endl;
        delete[] logMessage;
        // Deleting the program installed previously
        glDeleteProgram(idOfTheCreatedProgram);

        // Returning 0 to indicate that the compilation went wrong
        return 0;
    }

    // Returning id of the created program
    return idOfTheCreatedProgram;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "My First Fancy Triangle Using Moderm OpenGL (22.05.2024 | 06:38)", NULL, NULL);
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

    // Printing out the OpenGL-version in use
    std::cout << "Your OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    // Defining the positions of vertices of the triangle
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
    
    // Enabling the atrribute of vertex array representing the positions of vertices
    glEnableVertexAttribArray(0);

    // Specifying the layout of our vertex buffer
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    // Defining the source code for the vertex shader
    std::string sourceCodeOfVertexShader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";

    // Defining the source code for the fragment shader
    std::string sourceCodeOfFragmentShader =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "void main()\n"
        "{\n"
        "   color = vec4(0.0, 1.0, 1.0, 1.0);\n"
        "}\n";

    // Creating the program
    unsigned int programId = createTheVertexAndFragmentShader(sourceCodeOfVertexShader, sourceCodeOfFragmentShader);
    // Using (installing) the program
    glUseProgram(programId);

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

    // Deleting the program installed previously
    glDeleteProgram(programId);
    // Deleting the vertex buffer created previously
    glDeleteBuffers(1, &triangleVerticesBufferId);

    glfwTerminate();

    return 0;
}