/*
Name: 曾俊宏
Student ID: 403410033
Department: Computer Science and Information Technology
Year: Junior

Notes:

1. The program has a make file, which can be used for compiling the program.
2. The program is tested on MacOS 10.12.4, with g++-6 (Homebrew GCC 6.3.0_1) 6.3.0
3. Change DEBUG value to 1 for testing four patterns with 100 generations
*/

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <ctime>

using namespace std;

#define DEBUG 1

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
		void proceed(int t = 1);
		void display();
		void setGeneration(int generation);
		void setAutoProceed(char inp[]);
		void run();
		void info();

	private:
		int w;
		int h;
		int mode;
		int generation;
		bool cell[300][300];
		void clearScreen();
		void go();
		bool inBound(int x, int y);
		bool autoProceed;
		void promptForContinue(bool firstTime = false);
};

GameOfLife::GameOfLife()
{
	this->w = 80;
	this->h = 23;
}

GameOfLife::GameOfLife(int w, int h)
{
	this->w = w;
	this->h = h;

	if( !(16 <= w && w <= 256) )
		cout << RED "Width is not within the proper range. Program behavior is undefined!" NONE << endl;
	else if( !(16 <= h && h <= 256) )
		cout << RED "Height is not within the proper range. Program behavior is undefined!" NONE << endl;
}

void GameOfLife::info()
{
	cout << GREEN "\n\n\n====================INFO====================" NONE << endl;
	cout << GREEN "w = " << w << ", h = " << h << NONE << endl;
	if(mode == 1)
		cout << GREEN "Using pattern Glider"  NONE << endl;
	else if(mode == 2)
		cout << GREEN "Using pattern Lightweight Spaceship" NONE << endl;
	else if(mode == 3)
		cout << GREEN "Using pattern Pulsar" NONE << endl;
	else
		cout << GREEN "Using " << mode << "%" NONE << endl;
	cout << GREEN "Proceeding " << generation << " generation(s) with " << (autoProceed == true ? "automatic" : "manual") << " proceeding" << NONE << endl;
	cout << GREEN "=====================INFO====================\n\n\n" NONE << endl;

#if DEBUG == 1
	promptForContinue();
#else
	promptForContinue(true);
#endif
}

void GameOfLife::initialize(int p)
{
	int mode = p;
	if(! (1 <= mode && mode <= 100)) {
		cout << RED "Mode out-of-range!" NONE << endl;
		return;
	}

	this->mode = mode;

	memset(cell, 0, sizeof(cell));
	if(mode == 1) {
		// 3 * 3
		int upperLeftX = h / 2 - 3 / 2;
		int upperLeftY = w / 2 - 3 / 2;

		bool data[3][3] = {{1, 1, 1},
			{1, 0, 0},
			{0, 1, 0}};

		for(int i = upperLeftX; i < upperLeftX + 3; i++) {
			for(int j = upperLeftY; j < upperLeftY + 3; j++) {
				cell[i][j] = data[i - upperLeftX][j - upperLeftY];
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
				cell[i][j] = data[i - upperLeftX][j - upperLeftY];
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
				cell[i][j] = data[i - upperLeftX][j - upperLeftY];
			}
		}
	} else {
		srand(time(NULL));
		int count = w * h * (mode * 1.0 / 100);
		for(int i = 0; i < count; i++) {
			do {
				int x = rand() % h;
				int y = rand() % w;
				if(cell[x][y] == false) {
					cell[x][y] = true;
					break;
				}
			} while(1);
		}
	}
}

void GameOfLife::setGeneration(int generation)
{
	if(generation < 1) {
		cout << RED "Generation out-of-range!" NONE << endl;
		return;
	}
	this->generation = generation;
}

bool GameOfLife::inBound(int x, int y)
{
	return (0 <= x && x < h) && (0 <= y && y < w);
}

void GameOfLife::go()
{
	const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int newStateMap[300][300];
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			int neighbors = 0;
			for(int k = 0; k < 8; k++) {
				int xx = i + dx[k];
				int yy = j + dy[k];

				if(inBound(xx, yy)) {
					neighbors += (cell[xx][yy] == true ? 1 : 0);
				}
			}

			if(cell[i][j]) {
				newStateMap[i][j] = ((neighbors == 2 || neighbors == 3) ? true : false);
			} else {
				newStateMap[i][j] = (neighbors == 3 ? true : false);
			}
		}
	}

	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			cell[i][j] = newStateMap[i][j];
}

void GameOfLife::setAutoProceed(char inp[])
{
	if(inp[0] == 'y') {
		this->autoProceed = true;
	} else {
		this->autoProceed = false;
	}
}

void GameOfLife::promptForContinue(bool firstTime)
{
	cout << YELLOW "Press any key to continue..." << NONE << endl;
	if(firstTime)
		getchar();
	getchar();
}

void GameOfLife::run()
{
	if(autoProceed) {
		// auto
		cout << YELLOW "Initial state" NONE << endl;
		display();
		promptForContinue();

		proceed(generation);
	} else {
		// manual
		cout << YELLOW "Initial state" NONE << endl;
		display();
		promptForContinue();

		for(int i = 0; i < generation; i++) {
			proceed();
			cout << YELLOW "Generation " << i + 1 << NONE << endl;
			promptForContinue();
		}
	}
}

void GameOfLife::proceed(int t)
{
	for(int g = 1; g <= t; g++) {
		clearScreen();
		// printf("\n");
		go();
		display();

		if(autoProceed) {
			cout << YELLOW "Generation " << g << NONE << endl;
			usleep(100000);
		}
	}
}

void GameOfLife::clearScreen()
{
	for(int i = 0; i < 100; i++)
		printf("\n");
}

void GameOfLife::display()
{
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			printf("%c", cell[i][j] == true ? '#' : '.');
		}
		printf("\n");
	}
}

int main()
{
#if DEBUG == 1
	for(int i = 1; i <= 4; i++) {
		GameOfLife game;
		game.initialize(i);
		game.setGeneration(100);
		game.setAutoProceed("y");
		game.info();
		game.run();

		cout << endl;
	}
#else
	cout << GREEN "Please set the width and height (enter -1, -1 for default size)"  NONE << endl;
	int w, h;
	cin >> w >> h;
	GameOfLife game;
	if(w != -1 && h != -1)
		game = GameOfLife(w, h);

	cout << GREEN "Please select a mode:\n1     glide\n2     lightweight spaceship\n3     pulsar\n4-100 percentage of live cells"  NONE << endl;
	int mode;
	cin >> mode;
	game.initialize(mode);

	cout << GREEN "How many generations do you want to proceed?" NONE << endl;
	int generation;
	cin >> generation;
	game.setGeneration(generation);

	cout << GREEN "Do you want automatic proceeding? (y/n)" NONE << endl;
	char inp[100];
	cin >> inp;
	game.setAutoProceed(inp);

	cout << GREEN "Let's start!" NONE << endl;
	game.info();
	game.run();
#endif
	return 0;
}
