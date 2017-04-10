#include <iostream>

using namespace std;

// define terminal color
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
#define NONE "\x1B[0m"

class GameOfLife
{
	public:
	GameOfLife();
	GameOfLife(int w, int h);

	void initialize(int p);
	void proceed(int t);
	void display();

	private:
	int w;
	int h;
	bool stateMap[300][300];
};

GameOfLife::GameOfLife()
{
	this->w = 80;
	this->h = 23;

	cout << CYAN "w = " << w << ", h = " <<  h << NONE << endl;
}

GameOfLife::GameOfLife(int w, int h)
{
	this->w = w;
	this->h = h;
	
	if( !(16 <= w && w <= 256) )
		cout << RED "Width is not within the proper range. Program behavior is undefined!" NONE << endl;
	else if( !(16 <= h && h <= 256) )
		cout << RED "Height is not within the proper range. Program behavior is undefined!" NONE << endl;
	else
		cout << CYAN "w = " << w << ", h = " <<  h << NONE << endl;
}

int main()
{
	GameOfLife game;

	cout << GREEN "Please select a mode:\n1     glide\n2     lightweight spaceship\n3     pulsar\n4-100 percentage of live cells"  NONE << endl;
	int mode;
	cin >> mode;

	cout << GREEN "How many generations do you want to proceed?" NONE << endl;
	int generation;
	cin >> generation;

	cout << GREEN "Let's start!" NONE << endl;

	return 0;
}

