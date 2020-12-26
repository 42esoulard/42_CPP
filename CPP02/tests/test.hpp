#include <iostream>

class test {
	
	public:
		test(void);
		test(test const &src);
		~test(void);

		test & operator=(test const &rhs);

	private:
		
};

std::ostream & operator<<(std::ostream &o, test const &rhs);