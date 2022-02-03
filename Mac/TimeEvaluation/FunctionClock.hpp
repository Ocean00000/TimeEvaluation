#pragma once

#include <chrono>
#include <time.h>
#include <sys/time.h>

namespace time_evaluation {

	struct clock_function_clock {
		using rep = long long;
		using period = std::micro;
		using duration = std::chrono::microseconds;
		using time_point = std::chrono::time_point<clock_function_clock>;

		static inline time_point now() noexcept {
			return (time_point(duration(clock())));
		}
	};

    struct time_function_clock{
        using rep = long long;
        using period = std::ratio<1, 1>;
        using duration = std::chrono::seconds;
        using time_point = std::chrono::time_point<time_function_clock>;

        static inline time_point now() noexcept {
            return (time_point(duration(time(nullptr))));
        }

    };
    
    template<clockid_t clock_id>
    struct clock_gettime_function_clock {
        using rep = long long;
        using period = std::nano;
        using duration = std::chrono::nanoseconds;
        using time_point = std::chrono::time_point<clock_gettime_function_clock<clock_id>>;

        static inline time_point now() noexcept {
            timespec time;
            clock_gettime(clock_id, &time);
            return (time_point(duration(time.tv_sec * period::den + time.tv_nsec)));
        }
    };

    struct timespec_get_function_clock {
        using rep = long long;
        using period = std::nano;
        using duration = std::chrono::nanoseconds;
        using time_point = std::chrono::time_point<timespec_get_function_clock>;

        static inline time_point now() noexcept {
            timespec time;
            timespec_get(&time, TIME_UTC);
            return (time_point(duration(time.tv_sec * period::den + time.tv_nsec)));
        }
    };

    struct gettimeofday_function_clock {
        using rep = long long;
        using period = std::micro;
        using duration = std::chrono::microseconds;
        using time_point = std::chrono::time_point<gettimeofday_function_clock>;

        static inline time_point now() noexcept {
            timeval time;
            gettimeofday(&time, nullptr);
            return (time_point(duration(time.tv_sec * period::den + time.tv_usec)));
        }
    };
}
