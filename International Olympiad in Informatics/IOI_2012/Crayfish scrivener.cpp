#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;

__gnu_cxx::crope s[1000010];

int tot;

void Init(){};

void TypeLetter(char L){
	
	++tot;
	
	s[tot] = s[tot-1];
	
	s[tot].push_back(L);
	
}

void UndoCommands(int U){
	++tot;
	s[tot] = s[tot - U - 1];
}

char GetLetter(int P){
	return s[tot][P];
}