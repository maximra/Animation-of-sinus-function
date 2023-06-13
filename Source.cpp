#include"wave.h"
#include"Animation.h"
#include<iostream>
#include <conio.h>
#include <cstdlib>
#include<string>
#include <crtdbg.h>
#include<time.h>
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW

#define FRAME_RATE   1.0f/60.0f   // Controls the frame rate of the animation
#define TIME_BEFORE_WE_COUNT 5.0f  // giving some time for the balls to mix together
const int Width = 800; // Window width.
const int Height = 600; // Window height.
const int Array_size = 60; // Array size.



using namespace std;



int main()
{
	{
		double current_time = 0, previous_time = 0;
		WindowGenerator window_1(Width, Height, Array_size);
		while (!window_1.shouldClose()) {

			current_time = glfwGetTime();
			if (current_time - previous_time >= FRAME_RATE)
			{
				previous_time = current_time;
				window_1.draw_wave_function();
				window_1.refresh();
				window_1.processEvents();  // Process events (if any)
			}
		}
		
	}
	cout << endl;
	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;
	return 0;
}