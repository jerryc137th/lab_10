#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cardNames[14] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[14] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int g = rand()%13+1;
	return g;
}

int calScore(int x,int y,int z){
	int r;
	if(x>=10) x=0;
	if(y>=10) y=0;
	if(z>=10) z=0;
	r = ((x+y+z)%10);
	return r;
}

int findYugiAction(int s){	
	int d = rand()%100+1;
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else if(s==6||s==7||s==8){
		if(d<=69){
			return 1;
		}
		else if(d>=70){
			return 2;
		}
	}
    return 0;
}



void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if(p==y){
		cout <<   "|             Draw!!!           |"; // when p is equal to y
	}
	else if(p>y){
		cout <<   "|         Player wins!!!        |"; // when p is greater than y
	}
	else{
		cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	}
	
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; //This line of code is not completed. You need to initialize value of yugiCards[].

	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction!=1&&playerAction!=2); //This line of code is not completed. You need to set the condition to do loop if user's input is not 1 or 2. 
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: ";
		//srand(time(0));
		playerCards[2] = drawCard();
		cout<<cardNames[playerCards[2]]<<endl;
		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Your new score: " << playerScore<< "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are not completed. Please correct it.

	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]]<< "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiCards[2] = drawCard();
	yugiAction = findYugiAction(yugiScore);
	
	
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: ";
		//srand(time(0));
		//yugiCards[2] = drawCard();
		cout<<cardNames[yugiCards[2]]<<endl;
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's new score: " <<yugiScore<<endl;
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
	return 0;
}
