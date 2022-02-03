#pragma once

#include <chrono>

namespace time_evaluation {
	template<class TimerType>
	const char* const get_time_name();

	template<>
	const char* const get_time_name<std::chrono::system_clock>() {
		return "chrono::system_clock";
	};

	template<>
	const char* const get_time_name<std::chrono::steady_clock>() {
		return "chrono::steady_clock";
	};

	struct GetSystemTimeAsFileTime_function_clock;

	template<>
	const char* const get_time_name<GetSystemTimeAsFileTime_function_clock>() {
		return "GetSystemTimeAsFileTime";
	};

	struct GetSystemTimePreciseAsFileTime_function_clock;

	template<>
	const char* const get_time_name<GetSystemTimePreciseAsFileTime_function_clock>() {
		return "GetSystemTimePreciseAsFileTime";
	};

	struct QueryPerformanceCounter_function_clock;

	template<>
	const char* const get_time_name<QueryPerformanceCounter_function_clock>() {
		return "QueryPerformanceCounter";
	};

	struct timespec_get_function_clock;

	template<>
	const char* const get_time_name<timespec_get_function_clock>() {
		return "timespec_get";
	};

	struct clock_function_clock;

	template<>
	const char* const get_time_name<clock_function_clock>() {
		return "clock";
	};

	struct GetTickCount_function_clock;

	template<>
	const char* const get_time_name<GetTickCount_function_clock>() {
		return "GetTickCount";
	};

	struct GetTickCount64_function_clock;

	template<>
	const char* const get_time_name<GetTickCount64_function_clock>() {
		return "GetTickCount64";
	};

	struct timeGetTime_function_clock;

	template<>
	const char* const get_time_name<timeGetTime_function_clock>() {
		return "timeGetTime";
	};

	struct time_function_clock;

	template<>
	const char* const get_time_name<time_function_clock>() {
		return "time";
	};
}