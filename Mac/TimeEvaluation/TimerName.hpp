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

	struct clock_function_clock;

	template<>
	const char* const get_time_name<clock_function_clock>() {
		return "clock";
	};

    struct timespec_get_function_clock;

    template<>
    const char* const get_time_name<timespec_get_function_clock>() {
        return "timespec_get";
    };

    struct time_function_clock;
    template<>
    const char* const get_time_name<time_function_clock>() {
        return "time";
    };
    template<clockid_t clock_id>
    struct clock_gettime_function_clock;
    
    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_REALTIME>>() {
        return "clock_gettime(CLOCK_REALTIME)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_MONOTONIC>>() {
        return "clock_gettime(CLOCK_MONOTONIC)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_MONOTONIC_RAW>>() {
        return "clock_gettime(CLOCK_MONOTONIC_RAW)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_MONOTONIC_RAW_APPROX>>(){
        return "clock_gettime(CLOCK_MONOTONIC_RAW_APPROX)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_UPTIME_RAW>>(){
        return "clock_gettime(CLOCK_UPTIME_RAW)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_UPTIME_RAW_APPROX>>(){
        return "clock_gettime(CLOCK_UPTIME_RAW_APPROX)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_PROCESS_CPUTIME_ID>>() {
        return "clock_gettime(CLOCK_PROCESS_CPUTIME_ID)";
    };

    template<>
    const char* const get_time_name<clock_gettime_function_clock<CLOCK_THREAD_CPUTIME_ID>>() {
        return "clock_gettime(CLOCK_THREAD_CPUTIME_ID)";
    };

    struct gettimeofday_function_clock;
    template<>
    const char* const get_time_name<gettimeofday_function_clock>() {
        return "gettimeofday";
    };
}
