#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Initializer.h"    // Class to initialize

void generateCharacter();

int main()
{
    Initializer start = Initializer(600, 600);
    GLFWwindow* window = start.getWindow();
    
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };
    start.vertexBuffer(vertices, 3);
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
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
        glDrawArrays(GL_TRIANGLES, 0, 3);
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

