#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
#include <io.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#define START 2500
#define END 2750
// 10 000 - 11 000
//#include <regex>

using namespace std;

map <string, int> dictionary;
int i;
string  path1 = "aclImdb\\test\\neg\\",
		path2 = "aclImdb\\test\\pos\\",
		path3 = "aclImdb\\train\\neg\\",
		path4 = "aclImdb\\train\\pos\\",
		path5 = "aclImdb\\train\\unsup\\";



class Pages
{
	
private:
	vector<int> x;
public:
	
	void add(int el){
		x.push_back(el);
	}
	void show()
	{
		for (int i = 0; i < x.size(); i++)
			cout << x[i] <<" ";
	}
	int find(int page)
	{
		int flag = 0;
		for (auto it = x.begin(); it <= x.end();it++)
		{
			if (*it == page)
			{
				flag = 1;
				break;
			}
		}
		return flag;
	}
	int sizeon()
	{
		return x.size();
	}

};

Pages page[10000];

string clean(string word)
{
	int n;
	n = word.find('(');
	if (n!= string::npos){
		word.erase(n,n+1);
	}
	n = word.find(')');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('(');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('.');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find(',');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('[');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find(']');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find(':');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find(';');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('!');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('?');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('<');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('>');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('{');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find('}');
	if (n != string::npos){
		word.erase(n, n + 1);
	}
	n = word.find("...");
	if (n != string::npos){
		word.erase(n,n+3);
	}

	transform(word.begin(), word.end(), word.begin(), tolower);

	return word;
}

void indexter(string path, int begin, int end)
{
	int index = 0,i;
	Pages p[1000];
	map <string, int> dict;
	for (i = begin; i <= end; i++)
	{
		_finddata_t data;
		string buff;
		buff = to_string(i);
		buff = path + buff + "\*";
		//cout << buff<<endl;
		char a[50];
		strcpy(a, buff.c_str());
		//cout << a;
		intptr_t handle = _findfirst(a, &data);
		//cout << data.name<<endl;
		ifstream fin(data.name);

		if (!fin.is_open()) // если файл не открыт
			cout << "Файл " << data.name << "отклыть не удалось"; // сообщить об этом
		else
		{
			string word;
			while (!fin.eof())
			{
				fin >> word; // считать слово из файла
				word = clean(word);
			}
			fin.close(); // закрываем файл
		}
	}
}

int main(){
	
	setlocale(LC_ALL, "rus");
	//map <string, A> lol;

	/*if(lol["first"].sizeon()) cout<< "lol";
	auto it = lol.find("first");
	it->second.add(1);
	it->second.add(2);
	cout << it->first;
	it->second.show();
	/*_finddata_t data;
	string buff;
	buff = to_string(150);
	buff = buff + "\*";
	//cout << buff<<endl;
	char a[10];
	strcpy(a, buff.c_str());
	//cout << a;
	intptr_t handle = _findfirst(a,&data);
	//cout << data.name<<endl;
	ifstream fin(data.name);
	
	if (!fin.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n"; // сообщить об этом
	else
	{
		fin >> buff; // считали первое слово из файла
		cout << buff << endl; // напечатали это слово
		fin.close(); // закрываем файл
	}*/
		system("pause");
		return 0;
}