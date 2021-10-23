#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    void show(string & s) // для вывода посимвольно
        {
            cout<<"(";
            for (auto & i : s)
                {
                    cout<<i<<") (";
                }
            cout<<endl;
        };
    
    int myAtoi(string s) 
        {
            int res = 0; // ответ
            bool negative = 0; // индикатор отрицательного числа
            cout<<"ATOI get\n";
            show(s);
            int sit = 0; // string iterator
            
            while((s[sit] == ' ') && (sit < s.size())) sit++; // игнорируем пробелы

            if((s[sit] == '-') || (s[sit] == '+')) // если был знак
                {
                    cout<<"найден знак\n";
                    if((48 > s[sit+1]) || (s[sit+1] > 57)) return 0;// если следующий символ не число то возвращаем ноль.
                    negative = (s[sit] == '-'); //если минус то запоминаем.
                    cout<<"negative = "<<negative<<endl;
                    sit++; // шаг
                }

            while((47 < s[sit]) && (s[sit] < 58)) // пока символ это цифра
                {
                    cout<<"найдена цифра "<<s[sit]<<endl;
                    if(res < 214748364) // если ответ меньше максимального на данном этапе
                        {
                            res = ((res*10) + (s[sit] - 48)); // добавляем цифру к ответу
                        }
                        else if(res > 214748364) return ((negative)? -2147483648 : 2147483647); //если ответ меньше максимального на данном этапе возвращаем экстремум
                                else // res == 214748364 последнюю цифру можно добавить если это не 9 для отрицательного ответа и не больше 8 для положительного. 
                                    {
                                        if (negative)
                                            { 
                                                if(s[sit] > 55) return -2147483648; // если цифра больше 7 (8 или 9) то возвращаем максимальное отрицательное число -2147483648
                                            }
                                            else
                                                {
                                                    if(s[sit] > 54) return 2147483647; // если цифра больше 6 (7, 8 или 9) то возвращаем максимальное положительное число 2147483647
                                                }
                                        res = ((res*10) + (s[sit] - 48)); //в остальных случаях (0,1,2,3,4,5,6) стоит добавить последнюю цифру.  
                                    };
                    if((sit + 1) < s.size()) sit++;// шаг 
                        else {
                                cout<<"конец строки\n";
                                return ((negative)? (res * (-1)) : res ); // возвращаем ответ.
                                break;  
                             } 
                }
            cout<<"выход из цикла while\n";
            return ((negative)? (res * (-1)) : res ); // возвращаем ответ.
        };
};


int main()
{
    Solution s;
    vector<string> teststr;
    
    teststr.push_back("04193");
    teststr.push_back("-42");
    teststr.push_back("+4193");
    teststr.push_back("55яыв");
    teststr.push_back("_ы8");
    teststr.push_back("      7");
    teststr.push_back("      -34");
    teststr.push_back("      +56");
    teststr.push_back("      -89www");
    teststr.push_back("      -eee89");
    teststr.push_back("      89www");
    teststr.push_back("      eee89");
    teststr.push_back("2147483647");
    teststr.push_back(" 21474836499");
    teststr.push_back(" -2147483648");
    teststr.push_back("   -2147483649");
    teststr.push_back("-168135468435455");
    teststr.push_back("+12");
    teststr.push_back("+-12");
    teststr.push_back("-+12");
    teststr.push_back("--12");
    teststr.push_back("++12");
    teststr.push_back("+012");
    teststr.push_back("-012");
    teststr.push_back("2147483644");
    teststr.push_back("2147483640");
    teststr.push_back("21474836408");

    
    
    for (auto & i : teststr)
        {
            int ANSWER = s.myAtoi(i);
            cout<<"ANSWER -> "<<ANSWER<<"<-\n";
        }
    cout<<endl;
    
    return 0;
}
