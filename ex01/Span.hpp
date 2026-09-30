#include <vector>


class Span {
	private:
	std::vector<int>	_storage;
	unsigned int		_sizeMax;

	public:
	//OCF
	Span();
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	Span(unsigned int n);
	void addNumber(int num);// Any attempt to add a new element if there are already N elements stored should throw an exception
	long shortestSpan();
	long longestSpan();

	//Template functions:
	template <typename It>
	void addNumbers(It begin, It end)
	{
		if(_storage.size() + std::distance(begin, end) > _sizeMax)
		{
			throw FullSpanException();
		}
	_storage.insert(_storage.end(), begin, end);
	}

	//Exceptions
	class FullSpanException : public std::exception {
		public:
		const char* what() const throw(); //mira que pasa sin const throw()
	};
	class NoSpanException : public std::exception {
		public:
		const char* what() const throw(); //mira que pasa sin const throw()
	};
	



};