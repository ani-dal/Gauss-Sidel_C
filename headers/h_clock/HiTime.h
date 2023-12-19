
#pragma once
#ifndef _HCLOCK_
#define _HCLOCK_
#include <chrono>
#include <thread>


#include"HiTime"

namespace h_clock {

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	//std::chrono::duration<float> duration;

	void startTimer(void)
	{
		start = std::chrono::high_resolution_clock::now();

	};

	void sleep(const int _milliseconds)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(_milliseconds));
	};

	int clock_nano(void)
	{
		end = std::chrono::high_resolution_clock::now();
		auto nano_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		return (int)nano_duration.count();
	};

	int clock_micro(void)
	{
		end = std::chrono::high_resolution_clock::now();
		auto micro_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		return (int)micro_duration.count();
	};

	int clock_milli(void)
	{
		end = std::chrono::high_resolution_clock::now();
		auto milli_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		return (int)milli_duration.count();
	};

}
#endif

