#include <iostream>
#include <vector>

#include "nonAccessible.h"

using namespace std;

nonAccessible::nonAccessible() {
	
	cout << "x";

}

nonAccessible::~nonAccessible() {
	
}

void nonAccessible::set(int i, int j) {
	
		x.push_back(i);
		y.push_back(j);
			    
}

int nonAccessible::block(int row, int col, int ch) {
	
	for(int i=0; i < x.size(); i++){
		
		for(int j=0; j < y.size(); j++){
			if(ch=='d')
				if(x[i]==row && y[j]==col+1)
					col-=1;
			if(ch=='a')
				if(x[i]==row && y[j]==col-1)
					col+=1;
			if(ch=='w')
				if(x[i]==row-1 && y[j]==col)
					row+=1;	
			if(ch=='s')
				if(x[i]==row+1 && y[j]==col)
					row-=1;	
	
		}
	}							
				
				if(ch=='w' || ch=='s')
					col=row;
				
				return col;

}

vector<int> nonAccessible::get_x()const {
	
	return x;

}

vector<int> nonAccessible::get_y()const {
	
	return y;

}
