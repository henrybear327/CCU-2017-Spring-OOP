#include <iostream>

using namespace std;

class Test
{
public:
    Test();
    Test(int num);

private:
    int number;
};

Test::Test()
{
    printf("Default constructor\n");
}

Test::Test(int num)
{
    number = num;
    printf("number = %d\n", number);
}

int main()
{
    Test object1, object2, object3, object4;
    printf("%p %p %p %p\n", &object1, &object2, &object3, &object4);
    object1 = Test(1);
    object2 = Test(2);
    object3 = Test(3);
    object4 = Test(4);
    printf("%p %p %p %p\n", &object1, &object2, &object3, &object4);

    return 0;
}
