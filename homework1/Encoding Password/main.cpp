#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void countLetter(string s)
{
    int counter=1;
    int stringlenghth=s.length();
    for(int i=0;i<stringlenghth;i++)
    {
        while(s[i]==s[i+1])
        {
            counter++;
            i++;
        }
        cout<<counter<<s[i];
        counter=1;
    }
}

int main() {
    string s;
    getline(cin,s);
    countLetter(s);
    return 0;
}
