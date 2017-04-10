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

	private:
	int w;
	int h;
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

	cout << CYAN "w = " << w << ", h = " <<  h << NONE << endl;
}

int main()
{
	GameOfLife game;

	return 0;
}

