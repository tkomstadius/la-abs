#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>

using namespace std;

int main()
{
    const int TABLE_SIZE = 1000003;

    bool check[TABLE_SIZE] = {false};

    default_random_engine generator;
    uniform_int_distribution<long> distribution(0, TABLE_SIZE-1);

    //Sample the risk of collision for i keys
    for(int i = 0; i < 10000; i += 50)
    {
        int counter = 0;  //collision counter

        //Attempt 100 times to insert i keys and
        //count how many times it leads to (first time) collision
        for(int j = 1; j <= 100; ++j)
        {
            //Clean the table
            for(int k = 0; k < TABLE_SIZE; ++k)
                check[k] = false;

            //Insert i keys and check for the first collision
            for(int k = 0; k < i; ++k)
            {
                long h = distribution(generator);

                //cout << h << endl;
                //cin.get();

                if (check[h])
                {
                    ++counter; //increment collision counter
                    break;
                }
                else
                {
                    check[h] = true;
                }

            }
        }

        cout << i << " " << counter / 100.0 << endl;
    }

    return 0;
}
