#include <iostream>
#include <cstring>

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
		int mode;
		int generation;
		bool stateMap[300][300];
		void clearScreen();
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

void GameOfLife::initialize(int mode)
{
	if(! (1 <= mode && mode <= 100)) {
		cout << RED "Mode out-of-range!" NONE << endl;
		return;
	}

	this->mode = mode;

	memset(stateMap, 0, sizeof(stateMap));
	if(mode == 1) {
		// 3 * 3
		int upperLeftX = h / 2 - 3 / 2;
		int upperLeftY = w / 2 - 3 / 2;

		bool data[3][3] = {{1, 1, 1},
						   {1, 0, 0},
						   {0, 1, 0}};

		for(int i = upperLeftX; i < upperLeftX + 3; i++) {
			for(int j = upperLeftY; j < upperLeftY + 3; j++) {
				stateMap[i][j] = data[i - upperLeftX][j - upperLeftY];	
			}
		}
	} else if(mode == 2) {
		// 4 * 5
		int upperLeftX = h / 2 - 4 / 2;
		int upperLeftY = w / 2 - 5 / 2;
		bool data[4][5] = {{0, 1, 0, 0, 1},
						   {1, 0, 0, 0, 0},
						   {1, 0, 0, 0, 1},
						   {1, 1, 1, 1, 0}};

		for(int i = upperLeftX; i < upperLeftX + 4; i++) {
			for(int j = upperLeftY; j < upperLeftY + 5; j++) {
				stateMap[i][j] = data[i - upperLeftX][j - upperLeftY];	
			}
		}
	} else if(mode == 3) {
		// 13 * 13
		int upperLeftX = h / 2 - 13 / 2;
		int upperLeftY = w / 2 - 13 / 2;
		bool data[13][13] = {{0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
							 {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
							 {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
							 {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
							 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
							 {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0},
							 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							 {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0},
							 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
							 {1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
							 {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
							 {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0},
							 {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0}};

		for(int i = upperLeftX; i < upperLeftX + 13; i++) {
			for(int j = upperLeftY; j < upperLeftY + 13; j++) {
				stateMap[i][j] = data[i - upperLeftX][j - upperLeftY];	
			}
		}
	} else {
		
	}
}

void GameOfLife::proceed(int generation)
{
	if(generation < 1) {
		cout << RED "Generation out-of-range!" NONE << endl;
		return;
	}
	this->generation = generation;
}

void GameOfLife::clearScreen() 
{
	for(int i = 0; i < 100; i++)
		printf("\n");
}

void GameOfLife::display()
{	
	int currentGeneration = 1;
	for(; currentGeneration <= generation; currentGeneration++) {
		clearScreen();
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				printf("%c", stateMap[i][j] == true ? '#' : '.');
			}
			printf("\n");
		}

		cout << YELLOW "Generation " << currentGeneration << NONE << endl;
	}
}

int main()
{
	GameOfLife game(16, 16);

	cout << GREEN "Please select a mode:\n1     glide\n2     lightweight spaceship\n3     pulsar\n4-100 percentage of live cells"  NONE << endl;
	int mode;
	cin >> mode;
	game.initialize(mode);

	cout << GREEN "How many generations do you want to proceed?" NONE << endl;
	int generation;
	cin >> generation;
	game.proceed(generation);

	cout << GREEN "Let's start!" NONE << endl;
	game.display();

	return 0;
}

