#pragma once
#include <GLFW/glfw3.h>
#include"wave.h"

class WindowGenerator {

public:
	WindowGenerator(const int& width, const int& height, const int& size);
	~WindowGenerator();

	bool shouldClose();  //Window related functions.
	void processEvents();
	void refresh();

	void draw_wave_function() ;

private:
	GLFWwindow* m_window; // Window object itself
	int m_width, m_height;  // Window width and height
	int array_size;			// size of sin array
	int memory;				// Indicates the current start position
};