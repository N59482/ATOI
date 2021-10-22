#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    void show(string & s)
        {
            for (auto & i : s)
                {
                    cout<<i<<'-';
                }
            cout<<endl;
        };
    int myAtoi(string s) 
        {
            bool negative = 0;
            cout<<"ATOI get\n";
            show(s);
            for (auto & i : s)
                {
                    char temp = i;
                    cout<<"cut ("<<i<<")\n";
                    if(i != ' ')
                        {
                            if(i == '-')
                                {
                                    cout<<"find minus\n";
                                    negative = 1;
                                }
                                else if ((i <= 57) && (i >= 48))// если это число.
                                        {
                                            int res = i - 48;
                                            cout<<"INT ->"<<res<<endl;
                                        }
                        }
                }            
            return 0;
        }
};


int main()
{
    Solution s;
    string teststr = "     12";
    string teststr2 = "   -34";
    string teststr3 = "   +56";
    string teststr4 = "    89www";
    string teststr5 = "    eee89";
    
    cout<<teststr<<endl;

    for (auto & i : teststr)
        {
            cout<<i<<"-";
        }
    cout<<endl;
    
    s.myAtoi(teststr);
    
    char ch = '9';// 48 - 57
    int res = ch;
    //cout<<res<<endl;
    
    return 0;
}
