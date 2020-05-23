//#include <string>
#include "clean.h"

#pragma once 
wstring clean(wstring word)   // убирает нежелательные символы
{

	int n;
	n = word.find(L"<br />");
	if (n != wstring::npos){
		word.erase(n, n + 3);
		n = word.find(L"<br />");
		if (n != wstring::npos){
			word.erase(n, n + 3);
		}
	}
	n = word.find(L'(');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L')');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'(');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'.');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L',');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'[');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L']');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L':');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L';');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'!');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'?');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'<');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'>');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'{');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'}');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'\\');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'/');
	if (n != wstring::npos){
		word.erase(n, n + 1);
	}
	n = word.find(L'\"');
	if (n != wstring::npos){
		word.erase(n, n + 1);
		n = word.find(L'\"');
		if (n != wstring::npos){
			word.erase(n, n + 1);
		}
	}
	n = word.find(L'\'');
	if (n != wstring::npos && (n == 0 || n <= word.size() - 1)){
		word.erase(n, n + 1);
		n = word.find(L'\'');
		if (n != wstring::npos && (n == 0 || n <= word.size() - 1)){
			word.erase(n, n + 1);
		}
	}
	n = word.find(L'*');
	if (n != wstring::npos){
		word.erase(n, n + 1);
		n = word.find(L'*');
		if (n != wstring::npos){
			word.erase(n, n + 1);
		}
	}
	n = word.find(L"...");
	if (n != wstring::npos){
		word.erase(n, n + 3);
	}
	for (int j = 0; j < word.size(); j++)
	{
		if (word[j] >= 65 && word[j] <= 90)
		{
			word[j] += 32;
		}
	}
	//transform(word.begin(), word.end(), word.begin(), tolower);

	return word;
}