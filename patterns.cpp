#include <bits/stdc++.h>
using namespace std;

void pattern_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << '*';
        }
        cout << "\n";
    }
}

void pattern_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << "\n";
    }
}

void pattern_3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

void pattern_4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

void pattern_5(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << '*';
        }
        cout << "\n";
    }
}

void pattern_6(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

void loop_1(int i, int n)
{
    for (int j = 1; j <= n - i; j++)
    {
        cout << " ";
    }
}

void loop_2(int i)
{

    for (int k = 1; k <= (2 * i) - 1; k++)
    {
        cout << '*';
    }
}

void pattern_7a(int n)
{
    for (int i = 1; i <= n; i++)
    {
        loop_1(i, n);
        loop_2(i);
        loop_1(i, n);
        cout << "\n";
    }
}

void pattern_7b(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (j <= n - i || j >= n + i)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
}

void pattern_8a(int n)
{

    for (int i = n; i >= 0; i--)
    {
        loop_1(i, n);
        loop_2(i);
        loop_1(i, n);
        cout << "\n";
    }
}

void pattern_8b(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            if (j <= n - i || j >= n + i)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
}

void pattern_9(int n)
{
    pattern_7a(n);
    pattern_8a(n);
}

void pattern_10a(int n)
{
    pattern_2(n);
    pattern_5(n - 1);
}

void pattern_10b(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void pattern_11(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int r = i % 2;
        for (int j = 1; j <= i; j++)
        {
            cout << r;
            cout << " ";
            // if (r == 0)
            //     r++;
            // else
            //     r--;
            r = 1 - r;
        }
        cout << "\n";
    }
}

void loop_3(int i)
{
    for (int j = 1; j <= i; j++)
    {
        cout << j;
    }
}

void loop_4(int i, int n)
{
    for (int j = 1; j <= 2 * (n - i); j++)
    {
        cout << " ";
    }
}

void loop_5(int i)
{
    for (int j = i; j >= 1; j--)
    {
        cout << j;
    }
}

void pattern_12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        loop_3(i);
        loop_4(i, n);
        loop_5(i);
        cout << "\n";
    }
}

void pattern_13a(int n)
{
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        for (j; j <= i * (i + 1) / 2; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void pattern_13b(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
}

void pattern_14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= i + 'A'; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

void pattern_15(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (char j = 'A'; j < i + 65; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

void pattern_16(int n)
{
    // char j = 'A';
    for (int i = 1; i <= n; i++)
    {
        char j = 'A' + i - 1;
        for (int m = 1; m <= i; m++)
        {
            cout << j;
        }
        //  j++;
        cout << "\n";
    }
}

void pattern_17a(int n)
{
    for (int i = 1; i <= n; i++)
    {
        loop_1(i, n);
        for (char j = 'A'; j < i + 65; j++)
        {
            cout << j;
        }
        for (char j = 'A' + (i - 2); j >= 'A'; j--)
        {
            cout << j;
        }
        // loop_1(i, n);
        cout << "\n";
    }
}

void pattern_17b(int n)
{
    for (int i = 1; i <= n; i++)
    {
        loop_1(i, n);
        char ch = 'A';
        int bp = (2 * i - 1) / 2;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << ch;
            if (j <= bp)
                ch++;
            else
                ch--;
        }
        cout << "\n";
    }
}

void pattern_18(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (char j = i + 64; j < 'A' + n; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

void pattern_19(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j > i && j <= 2 * n - i)
                cout << " ";
            else
                cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j > i && j <= 2 * n - i)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
}

void pattern_20a(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j > i && j <= 2 * n - i)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j > i && j <= 2 * n - i)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
}

void pattern_20b(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            int k = i;
            if (i > n)
                k = 2 * n - i;

            if (j > k && j <= 2 * n - k)
                cout << " ";
            else
                cout << '*';
        }
        cout << "\n";
    }
}

void pattern_21a(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == n)
        {
            for (int k = 1; k <= n; k++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        else
        {
            cout << "*";
            for (int k = 1; k <= n - 2; k++)
            {
                cout << " ";
            }
            cout << "*" << "\n";
        }
    }
}

void pattern_21b(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void pattern_22(int n)
{

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int k = n - min(min(i, j), min(2 * n - i - 2, 2 * n - j - 2));
            cout << k;
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    pattern_22(n);
    return 0;
}
