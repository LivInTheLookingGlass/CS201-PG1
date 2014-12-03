//Gabe Appleton, CS201
//This is the main file for the program which converts from base 10 to base 12. It was designed in a way where you could convert to other bases
//with slight modification, as it uses the general conversion formula, rather than a specific one.


#include "PG1.h"
#include <string>
#include <iostream>
using namespace std;

//it's the main.  What do you expect?
int main()
{
	/*string a="1000", b;
	int c=0;
	Div12(a, b, c);
	cout << b;
	system("pause");*/
	cout << "What should I convert to duodecimal?" << endl;
	string convertthis;
	int r = 0;
	cin >> convertthis;
	//cout << "start" << endl;
	cout << BaseChange(convertthis) << endl;
	system ("pause");
	return 0;
}

//Divides ludicrously large numbers by twelve
void Div12(string a, string &answer, int &remainder)
{
	for (int i = 0; i < a.length(); i++)
	{
		char b = a[i];
		//cout << "b = " << b << endl; // prints working character
		int c = remainder * 10 + ( b - '0' );
		//cout << "c = " << c << endl; // prints currently divided number
		int d = c / 12;
		//cout << "d = " <<d << endl; // prints divided number over twelve
		remainder = c % 12;
		//cout <<"remainder = "<< remainder << endl; // prints remainder
		if (answer != "" || d != 0)
			answer.append(std::to_string((long long)d));
	}
}

//implements the above method to use the general base conversion formula
string BaseChange(string a)
{
	string solution = "", answer;
	int remainder = 0;
	while (a != "")
	{
		Div12(a,answer,remainder);
		if (remainder == 10)
			solution = (string)"A" + solution;
		else if (remainder == 11)
			solution = (string)"B" + solution;
		else
			solution = std::to_string((long long)remainder) + solution;
		remainder=0;
		a = answer;
		answer = "";
		/*cout << endl;
		cout << std::to_string(remainder) <<endl;
		cout << "solution = " << solution << endl;
		cout << endl;*/
	}
	return solution;
}
