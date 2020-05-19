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
#include <thread>
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
	if (n != string::npos){
		word.erase(n, n + 1);
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
	n = word.find('\"');
	if (n != string::npos){
		word.erase(n, n + 1);
		n = word.find('\"');
		if (n != string::npos){
			word.erase(n, n + 1);
		}
	}
	n = word.find('\'');
	if (n != string::npos && (n == 0 || n <= word.size()-1)){
		word.erase(n, n + 1);
		n = word.find('\'');
		if (n != string::npos && (n == 0 || n <= word.size() - 1)){
			word.erase(n, n + 1);
		}
	}
	n = word.find("...");
	if (n != string::npos){
		word.erase(n,n+3);
	}

	transform(word.begin(), word.end(), word.begin(), tolower);

	return word;
}

void indexer(string path, int begin, int end)
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
				if (word.size() > 0)
				{
					auto it = dict.find(word);
					if (it != dict.end())
					{
						if (!p[it->second].find(i))
						{
							p[it->second].add(i);
						}
					}
					else
					{
						dict.insert(pair<string, int>(word, index));
						p[index].add(i);
						index++;
					}
				}
			}
			fin.close(); // закрываем файл
		}
	}
}

void router(int box1, int box2, int box3, int box4, int bigbox_start, int bigbox_end)
{
	if (box1)
	{
		indexer(path1, START, END);
	}
	if (box2)
	{
		indexer(path2, START, END);
	}
	if (box3)
	{
		indexer(path3, START, END);
	}
	if (box4)
	{
		indexer(path4, START, END);
	}
	if (bigbox_start < bigbox_end)
	{
		indexer(path1, bigbox_start, bigbox_end);
	}
}


int main(){
	
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Enter number of threads:";
	cin >> n;

		system("pause");
		return 0;
}