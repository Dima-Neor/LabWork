#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string RemoveDublicat(string str)
{
	vector<string> words;
	stringstream f;
	f << str;
	str = "";
	while (f >> str)
	{
		words.push_back(str);
	}
	for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "\n";
    }
    
}
int main()
{
    string str;
    cin >> str;
    RemoveDublicat(str);
    system ("pause");
    return 0;
}