#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	getline(cin, s, '\n');



	// ���ڵ�� ��ü�� �ε�����
	//cout<<
	int index = 0;
	int startindex = 0;
	while (startindex < s.length())
	{
		if (s.find(' ', startindex) == string::npos)
			break;
		startindex = 1 + s.find(' ', startindex);
		index++;


	}
	if (s[0] == ' ')index--;
	if (s[s.length() - 1] == ' ')index--;

	cout << index + 1;
}
//chang ho is
//si��