#include <iostream>
#include <string>
#include <sstream>

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isIPrime(int n)
{
    std::string str = std::to_string(n);
    std::string rStr = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        rStr += str[i];
    }

    if (rStr == str)
        return false;

    int newNum = std::stoi(rStr);

    if (newNum == 1)
        return false;
    if (newNum == 2)
        return true;

    for (int i = 2; i < newNum; i++)
    {
        if (newNum % i == 0)
            return false;
    }

    return true;
}

int main()
{
    using namespace std;
    int value;

    while (1)
    {
        cin >> value;
        if (cin.eof())
            break;
        cin.ignore();

        if (!isPrime(value))
        {
            std::cout << value << " nao primo" << endl;
        }
        else if (isPrime(value) && !isIPrime(value))
        {
            std::cout << value << " primo" << endl;
        }
        else
        {
            std::cout << value << " omirp" << endl;
        }
    }
}