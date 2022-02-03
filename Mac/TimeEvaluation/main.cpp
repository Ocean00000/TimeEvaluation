#include "TimerName.hpp"
#include "FunctionClock.hpp"
#include "Unit.hpp"
#include <chrono>
#include <iostream>

using namespace time_evaluation;
using namespace std::chrono;
using namespace std;

namespace {
    template<class ClockType, class DurationType>
    double get_latency(const size_t count) {
        const auto start = ClockType::now();
        for (int index = 0; index < count; ++index) {
            ClockType::now();
        }
        const auto stop = ClockType::now();

        return static_cast<double>(duration_cast<DurationType>(stop - start).count()) / (count + 1);
    }

    template<class ClockType, class DurationType>
    double get_resolution_time(const size_t& count) {
        size_t index = 0;
        typename ClockType::time_point next;
        long long sum = 0;
        for (auto last = ClockType::now(); index < count; last = ClockType::now()) {
            next = ClockType::now();
            if (last != next) {
                ++index;
                sum += duration_cast<DurationType>(next - last).count();
            }
        }

        return static_cast<double>(sum) / index;
    }

    template<class ClockType, class DurationType>
    void output_time(const pair<size_t, size_t>& count) {
        cout << get_time_name<ClockType>() << "," << std::fixed << get_resolution_time<ClockType, DurationType>(count.first) << "," << get_unit<DurationType>()
            << "," << std::fixed << get_latency<ClockType, nanoseconds>(count.second) << "," << get_unit<nanoseconds>() << endl;
    }
}

int main() {
    const pair<size_t, size_t> count{ 2000, 500000000 };
    cout << "Timer,Resolution,Unit,Latency,Unit" << endl;
    output_time<system_clock, nanoseconds>(count);
    output_time<steady_clock, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_REALTIME>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_MONOTONIC>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_MONOTONIC_RAW>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_MONOTONIC_RAW_APPROX>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_UPTIME_RAW>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_UPTIME_RAW_APPROX>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_PROCESS_CPUTIME_ID>, nanoseconds>(count);
    output_time<clock_gettime_function_clock<CLOCK_THREAD_CPUTIME_ID>, nanoseconds>(count);
    output_time<timespec_get_function_clock, nanoseconds>(count);
    output_time<clock_function_clock, microseconds>(count);
    output_time<gettimeofday_function_clock, microseconds>(count);
    output_time<time_function_clock, seconds>(make_pair(200, 5000000000));
    return 0;
}
