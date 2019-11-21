#ifndef NONACCESSIBLE_H
#define NONACCESSIBLE_H

#include <iostream>
#include <vector>

class nonAccessible {
	
	private:
		
		std::vector<int> x;
		std::vector<int> y; 

	public:
		
		nonAccessible();
		~nonAccessible();
		
		void set(int x, int y);
		int block(int x, int y,int ch);
		std::vector<int> get_x()const;
		std::vector<int> get_y()const;
};
#endif

