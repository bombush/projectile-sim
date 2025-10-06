// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <entt/entt.hpp>
#include <thread>
#include <chrono>

#include "Components.hpp"
#include "World.hpp"

int main()
{
	// spawn the world
	auto World = GWorld();

	// count simulation steps so far
	int counter_steps = 0;

	// initialize clock
	std::chrono::steady_clock::time_point last_frame_time = std::chrono::steady_clock::now();

	while (counter_steps < 100000)
	{
		// calculate delta time and FPS
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<float> frame_duration = now - last_frame_time;
		float dt = frame_duration.count();
		float fps = 1.0f / dt;
		last_frame_time = now;

		// tick the world
		World.Tick(dt); 
		counter_steps++;

		// print out the info
		std::cout << "Step: " << counter_steps << "  DT: " << (dt*1000.0f) << "ms  FPS: " << fps << " \n";

		// sleep. @TODO: use fixed time step instead of thread sleep
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}



    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
