#include <iostream>
using namespace std;
void square_Diamond_pattern()
{
    /*
    #######
    ###*###
    ##***##
    #*****#
    ##***##
    ###*###
    #######
    */
    int n = 7;
    int mid = (n / 2) + 1;
    int spaces = mid - 1;

    int stars = 1;
    for (int i = 1; i <= n; i++)
    {

        if (i == 1 || i == n)
        {
            for (int j = 1; j <= n; j++)
                cout << "#";
        }
        else
        {
            for (int j = 1; j <= spaces; j++)
                cout << "#";

            for (int k = 1; k <= stars; k++)
                cout << "*";

            for (int j = 1; j <= spaces; j++)
                cout << "#";

            if (i < mid)
            {
                spaces = spaces - 1;
                stars = stars + 2;
            }
            else
            {
                spaces = spaces + 1;
                stars = stars - 2;
            }
        }
        cout << endl;
    }
}

void pyramid()
{
    /*
     *
     * *
     * * *
     * * * *
     * * * * *
     */
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int spaces = n - i;
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
            cout << "* ";
        cout << endl;
    }
}

void hollowTringle()
{
    int n;
    cin >> n;

    /*
          *
         * *
        *   *
       *     *
      *       *
     *         *
    * * * * * * *

        */
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            if (k == 1 || k == i || i == n)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
}

void hollowSquare()
{
    cout << "enter the number of rows : \n";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n || i == j || j == n - i + 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
void cross()
{
    cout << "enter the number of rows : \n";
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || j == n - i + 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
}

void leftArrow()
{
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void rightArrow()
{
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--)
    {
        int spaces = n - i;
        for (int k = 1; k <= spaces; k++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        int spaces = n - i;
        for (int k = 1; k <= spaces; k++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    rightArrow();
    return 0;
}