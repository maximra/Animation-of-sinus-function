#include "Animation.h"






WindowGenerator::WindowGenerator(const int& width, const int& height, const int& size)
{
    memory = 0;
    array_size = size;
    m_width = width;
    m_height = height;
    // Initialize GLFW library
    glfwInit();

    // Create a window
    m_window = glfwCreateWindow(m_width, m_height, "Window Generator", NULL, NULL);

    // Set the window as the current OpenGL context
    glfwMakeContextCurrent(m_window);

    // Set the viewport to the entire window
    glViewport(0, 0, m_width, m_height);

    // Set the clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

WindowGenerator::~WindowGenerator()
{
    // Destroy the window and terminate GLFW
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

bool WindowGenerator::shouldClose()
{
    // Check if the window should close (e.g. user clicked the close button)
    return glfwWindowShouldClose(m_window);
}

void WindowGenerator::processEvents()
{
    // Poll for and process events (e.g. window resize, key presses)
    glfwPollEvents();
}

void WindowGenerator::refresh()
{
    // Swap the front and back buffers (double buffering)
    glfwSwapBuffers(m_window);
}

void WindowGenerator::draw_wave_function()      // Draws the sin wave function
{
    sin_wave a(array_size);
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the colors
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw a hollow square
    glBegin(GL_LINES);
    for (int i = 0 ; i < array_size; i++)
    {
        if (i + memory<=array_size)
            glVertex2f(-1.0f + (2.0f * float(i) / (float(array_size - 1))), a.return_specific_data(i + memory));
        else
            glVertex2f(-1.0f + (2.0f * float(i) / (float(array_size - 1))), a.return_specific_data(i + memory-array_size));
    }
    glEnd();
    memory++;
    if (memory == array_size)
        memory = 0;
}


