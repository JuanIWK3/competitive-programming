#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main()
{
    using namespace std;
    string arr;
    getline(cin, arr);

    stringstream ss(arr);
    int value;
    vector<int> ages;
    vector<int> counted;

    while (ss >> value)
    {
        ages.push_back(value);
    }

    for (int i = 0; i < ages.size(); i++)
    {
        bool has = false;

        for (int j = 0; j < counted.size(); j++)
        {
            if (counted[j] == ages[i])
            {
                has = true;
            }
        }

        if (has)
            continue;

        int count = 0;
        for (int j = 0; j < ages.size(); j++)
        {
            if (ages[i] == ages[j])
            {
                count++;
            }
        }
        cout << ages[i] << " " << count << endl;
        counted.push_back(ages[i]);
    }
}