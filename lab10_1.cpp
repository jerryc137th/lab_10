#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

int grade(void){
	int a = rand()%9;
	return a;
}


int main(){
	int count=0,g;
	string x;
	cout << "Press Enter 3 times to reveal your future.";
	for(int i = 0;i<3;i++){
		cin.get();
	}
	srand(time(0));
	g = grade();
	x = (g==0)? "A":(g==1)? "B+":(g==2)? "B":(g==3)? "C+":(g==4)? "C":(g==5)? "D+":(g==6)? "D":(g==7)? "F": "W";
	cout << "You will get "<<x<<" in this 261102.";
	return 0;
}