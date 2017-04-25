#include <bits/stdc++.h>

using namespace std;

class Server
{
public:
    Server(char name);
    void output() const;
    static void next();

private:
    static int turn;
    char name;
};

int Server::turn = 0;

Server::Server(char name)
{
    this->name = name;
}

void Server::output() const
{
    printf("%c %d\n", name, turn);
}

void Server::next() // no need to add static in front
{
    turn++;
}

int main()
{
    Server a('a');
    a.output();

    a.next();
    a.output();

    a.next();
    a.output();

    a.next();
    a.output();

    Server::next(); // class-level function call
    a.output();

    return 0;
}
