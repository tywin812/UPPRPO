#include "candle.h"

#include <string>
#include <stdexcept>

Candle::Candle(Price _open, Price _high, Price _low, Price _close)
	: open(_open)
	, high(_high)
	, low(_low)
	, close(_close)
{
}

bool Candle::body_contains(const Price &price) const noexcept
{
	if(is_green())
	{
		const Price &max = close;
		const Price &min = open;
		return price >= min && price <= max;
	}
	else
	{
		const Price &max = open;
		const Price &min = close;
		return price >= min && price <= max;
	}
}

bool Candle::contains(const Price &price) const noexcept
{
	return price >= low && price <= high;
}

double Candle::full_size() const noexcept
{
	return std::abs(low - high);
}

double Candle::body_size() const noexcept
{
	return std::abs(open - close);
}

bool Candle::is_green() const noexcept
{
	return close > open;
}

bool Candle::is_red() const noexcept
{
	return close < open;
}

bool Candle::is_doji() const noexcept
{
	constexpr double threshold = 0.0001; 
	if (open == close) {
		return true;
	}
	double body = body_size();
	double range = full_size();
	if (range == 0.0) {
		return false;
	}
	return body / range <= threshold;
}