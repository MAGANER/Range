#ifndef RANGE_H
#define RANGE_H
/*
	This little header-only library was written to write
	easier for-range cycle with numeric progressions.

	Without Range:
	for(int i = 0;i<10;i++)
	{
		//do something
	}

	With Range:
	for(auto n:Range<int>(0,10,1)
	{
		//do something
	}

	First and second arguments are begin and end [begin;end)
	and the last one is step

*/
template<typename T>
class RangeIterator 
{
private:
	T step;
public:
	RangeIterator(T p, T step)
	{
		this->p = p;
		this->step = step;
	}
	RangeIterator(const RangeIterator& it) { p = it.p; }
	bool operator!=(RangeIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(RangeIterator const& other) const
	{
		return p == other.p;
	}

	T operator*() const
	{
		return p;
	}
	RangeIterator& operator++()
	{
		p += step;
		return *this;
	}
private:
	T p;
};


template<typename T>
class Range
{
private:
	T _begin = T();
	T _end   = T();
	T _step  = T();

	RangeIterator<T>* iter = nullptr;
public:
	Range(const T& begin, const T& end, const T& step)
	{
		this->_begin = begin;
		this->_end = end;
		this->_step = end < begin?-step:step;//make it able to move forward/bacward

		iter = new RangeIterator<T>(T(), step);
	}
	~Range()
	{
		delete iter;
	}

	RangeIterator<T> begin()
	{
		return RangeIterator<T>(_begin, _step);
	}
	RangeIterator<T> end()
	{
		return RangeIterator<T>(_end, _step);
	}
};
#endif //RANGE_H