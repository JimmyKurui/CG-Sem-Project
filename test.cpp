//#include <glad/glad.h>
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glad/glad.h>
//#include "Initializer.h"    // Class to initialize
using namespace std;

void generateCharacter();

int main()
{
    /*Initializer start = Initializer(600, 600);
    GLFWwindow* window = start.getWindow();
    */
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    float polygonVertices[] = {
        0.2f, 0.2f, 0.0f,
        -0.2f, 0.2f, 0.0f,
        -0.2f, -0.2f, 0.0f,
        0.2f, -0.2f, 0.0f
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    // render loop
    // -----------
    while(!glfwWindowShouldClose(window))
    {
        // input
        // -----
        start.processInput(window);

        // render
        // ------
        glClearColor(0.0f, 0.1f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle

        glUseProgram(start.shaderFunction());
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, polygonVertices);
        glDrawArrays(GL_POLYGON, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
        // glBindVertexArray(0); // no need to unbind it every time 

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    /*glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);*/

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

