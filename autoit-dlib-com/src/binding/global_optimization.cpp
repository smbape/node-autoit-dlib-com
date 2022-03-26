#include "global_optimization.h"
using namespace dlib;
using namespace std;

// ----------------------------------------------------------------------------------------

// console.log(Array.from(new Array(35).keys()).map(i => `
//     template<>
//     struct Function<${ i + 1 }> {
//         typedef double (*type)(${ ", double".repeat(i + 1).slice(2) });
//     };
// `.replace(/^ {4}/mg, "").trim()).join("\n\n"))

template <size_t N>
struct Function;

template<>
struct Function<1> {
	typedef double (*type)(double);
};

template<>
struct Function<2> {
	typedef double (*type)(double, double);
};

template<>
struct Function<3> {
	typedef double (*type)(double, double, double);
};

template<>
struct Function<4> {
	typedef double (*type)(double, double, double, double);
};

template<>
struct Function<5> {
	typedef double (*type)(double, double, double, double, double);
};

template<>
struct Function<6> {
	typedef double (*type)(double, double, double, double, double, double);
};

template<>
struct Function<7> {
	typedef double (*type)(double, double, double, double, double, double, double);
};

template<>
struct Function<8> {
	typedef double (*type)(double, double, double, double, double, double, double, double);
};

template<>
struct Function<9> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<10> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<11> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<12> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<13> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<14> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<15> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<16> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<17> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<18> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<19> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<20> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<21> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<22> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<23> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<24> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<25> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<26> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<27> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<28> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<29> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<30> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<31> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<32> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<33> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<34> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

template<>
struct Function<35> {
	typedef double (*type)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
};

double call_func(void* f, const matrix<double, 0, 1>& args)
{
	const auto num = args.size();
	DLIB_CASSERT(0 < num && num < 35, "Functions being optimized must take between 1 and 35 scalar arguments.");

#define CALL_WITH_N_ARGS(N) case N: return dlib::gopt_impl::_cwv(reinterpret_cast<Function<N>::type>(f), args, typename make_compile_time_integer_range<N>::type()); 
	switch (num)
	{
		CALL_WITH_N_ARGS(1)
			CALL_WITH_N_ARGS(2)
			CALL_WITH_N_ARGS(3)
			CALL_WITH_N_ARGS(4)
			CALL_WITH_N_ARGS(5)
			CALL_WITH_N_ARGS(6)
			CALL_WITH_N_ARGS(7)
			CALL_WITH_N_ARGS(8)
			CALL_WITH_N_ARGS(9)
			CALL_WITH_N_ARGS(10)
			CALL_WITH_N_ARGS(11)
			CALL_WITH_N_ARGS(12)
			CALL_WITH_N_ARGS(13)
			CALL_WITH_N_ARGS(14)
			CALL_WITH_N_ARGS(15)
			CALL_WITH_N_ARGS(16)
			CALL_WITH_N_ARGS(17)
			CALL_WITH_N_ARGS(18)
			CALL_WITH_N_ARGS(19)
			CALL_WITH_N_ARGS(20)
			CALL_WITH_N_ARGS(21)
			CALL_WITH_N_ARGS(22)
			CALL_WITH_N_ARGS(23)
			CALL_WITH_N_ARGS(24)
			CALL_WITH_N_ARGS(25)
			CALL_WITH_N_ARGS(26)
			CALL_WITH_N_ARGS(27)
			CALL_WITH_N_ARGS(28)
			CALL_WITH_N_ARGS(29)
			CALL_WITH_N_ARGS(30)
			CALL_WITH_N_ARGS(31)
			CALL_WITH_N_ARGS(32)
			CALL_WITH_N_ARGS(33)
			CALL_WITH_N_ARGS(34)
			CALL_WITH_N_ARGS(35)

	default:
		DLIB_CASSERT(false, "oops");
		break;
	}
}

// ----------------------------------------------------------------------------------------

void dlib::find_max_global(
	void* f,
	std::vector<double>& bound1,
	std::vector<double>& bound2,
	std::vector<bool>& is_integer_variable,
	ULONG num_function_calls,
	double solver_epsilon,
	std::vector<double>& x,
	float* y
) {
	DLIB_CASSERT(bound1.size() == bound2.size());
	DLIB_CASSERT(bound1.size() == is_integer_variable.size());

	auto func = [&](const matrix<double, 0, 1>& x)
	{
		return call_func(f, x);
	};

	auto result = find_max_global(func, list_to_mat(bound1), list_to_mat(bound2),
		is_integer_variable, max_function_calls(num_function_calls),
		solver_epsilon);

	mat_to_list(result.x, x);
	*y = result.y;
}

void dlib::find_max_global(
	void* f,
	std::vector<double>& bound1,
	std::vector<double>& bound2,
	ULONG num_function_calls,
	double solver_epsilon,
	std::vector<double>& x,
	float* y
) {
	DLIB_CASSERT(bound1.size() == bound2.size());

	auto func = [&](const matrix<double, 0, 1>& x)
	{
		return call_func(f, x);
	};

	auto result = find_max_global(func, list_to_mat(bound1), list_to_mat(bound2), max_function_calls(num_function_calls), solver_epsilon);

	mat_to_list(result.x, x);
	*y = result.y;
}

void dlib::find_min_global(
	void* f,
	std::vector<double>& bound1,
	std::vector<double>& bound2,
	std::vector<bool>& is_integer_variable,
	ULONG num_function_calls,
	double solver_epsilon,
	std::vector<double>& x,
	float* y
) {
	DLIB_CASSERT(bound1.size() == bound2.size());
	DLIB_CASSERT(bound1.size() == is_integer_variable.size());

	auto func = [&](const matrix<double, 0, 1>& x)
	{
		return call_func(f, x);
	};

	auto result = find_min_global(func, list_to_mat(bound1), list_to_mat(bound2),
		is_integer_variable, max_function_calls(num_function_calls),
		solver_epsilon);

	mat_to_list(result.x, x);
	*y = result.y;
}

void dlib::find_min_global(
	void* f,
	std::vector<double>& bound1,
	std::vector<double>& bound2,
	ULONG num_function_calls,
	double solver_epsilon,
	std::vector<double>& x,
	float* y
) {
	DLIB_CASSERT(bound1.size() == bound2.size());

	auto func = [&](const matrix<double, 0, 1>& x)
	{
		return call_func(f, x);
	};

	auto result = find_min_global(func, list_to_mat(bound1), list_to_mat(bound2), max_function_calls(num_function_calls), solver_epsilon);

	mat_to_list(result.x, x);
	*y = result.y;
}