#include <iostream>
#include <string>
using namespace std;


/////////////////////////
// Function declartion //
/////////////////////////

void removeDupicate(string& s);
void commonCharac(string& s1, string& s2, string& s3);
void removeSpace(string& s);


int main() {

	// User's input
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);

	// Remove white space
	removeSpace(s1);
	removeSpace(s2);

	// Find common characters
	string s3 = "";
	commonCharac(s1, s2, s3);
	cout << s3 << endl;

}



/////////////////////////
// Function definition //
/////////////////////////

void removeDupicate(string &s) {

	int sEnd = s.length();
	for (int i = 0; i < sEnd; i++)
	{
		char c = s.at(i);
		for (int j = i + 1; j < sEnd;)
		{
			if (c == s.at(j))
			{
				s.erase(j,1);
				cout << s << endl;
				// Re-calculate sEnd
				sEnd--;
			}
			else
			{
				j++;
			}
			
		}
	}
}
void commonCharac(string& s1, string& s2, string& s3) {
	// Remove duplicate character from each string
	removeDupicate(s1);
	removeDupicate(s2);

	int len1 = s1.length();
	int len2 = s2.length();


	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (s1.at(i) == s2.at(j))
			{
				s3 += s1.at(i);
			}
		}
	}
}
void removeSpace(string& s) {
	int pos;
	do
	{
		pos = s.find_first_of(" ");
		if (pos != string::npos)
			s.erase(pos, 1);
	}
		while (pos != string::npos);
}
