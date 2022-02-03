#pragma once

#include <chrono>

namespace time_evaluation {
	template<class DurationType>
	const char* const get_unit();

	template<>
	const char* const  get_unit<std::chrono::nanoseconds>() {
		return "nanosecond";
	};

	template<>
	const char* const  get_unit<std::chrono::microseconds>() {
		return "microsecond";
	};

	template<>
	const char* const  get_unit<std::chrono::milliseconds>() {
		return "millisecond";
	};

	template<>
	const char* const  get_unit<std::chrono::seconds>() {
		return "second";
	};
}