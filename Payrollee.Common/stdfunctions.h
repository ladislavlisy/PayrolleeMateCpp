#pragma once

template< class F, template<class...>class S, class X, class Y,
class Res = typename std::result_of< F(X, Y) >::type >
	S<Res> zip(F&& f, const S<X>& v, const S<Y>& w) {
	S<Res> r;
	std::transform(std::begin(v), std::end(v),
		std::begin(w),
		std::back_inserter(r),
		std::forward<F>(f));
	return r;
}

