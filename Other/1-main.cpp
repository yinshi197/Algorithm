//解压字符串
#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    string temp;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] < 'a') temp.push_back(s[i]);
        else
        {
            if(!temp.empty())
            {
                int count = stoi(temp);
                temp = "";
                for(int j = 1; j < count; j++)
                    ans.push_back(s[i]);
            }
            ans.push_back(s[i]);
        }
    }

    cout << ans << endl;

    return 0;

}

