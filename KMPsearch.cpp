//	1st·Input:·AABAACAADAABAABA
//	2nd·Input:·AABAACAADAABAABAA
//	Pattern·to·be·searched:·AABA
//	Output:·AABAACAADAABAABA·+·AABAACAADAABAABAA·both·string·has·a·pattern·of·AABA.
//	Concatenated·Sorted·Characters:·AAAAAAAAAAAAAAAAAAAAAAABBBBBBCCDD
//Base Class --> Pattern Searching  Algorithm (Knuth–Morris–Pratt string-searching algorithm)
//Derive Class --> Sorting Algorithms with the O(nk) or O(n+k) .
#include <bits/stdc++.h> 
#include<string.h> 
#include"KMPsearch.h"
#define RANGE 255

using namespace std;

class body: public wordsearch
{
	public:
		void input()
		{
			cin.getline(inp1, 100);
			cin.getline(inp2, 100);
			cin.getline(search, 100);
			strcpy(temp1, inp2);
			strcpy(combine, inp1);
			strcat(combine, temp1);

		}
		
		void countSort(char arr[]) 
		{ 
	
			char output[strlen(arr)]; 

			int count[RANGE + 1], i; 
			memset(count, 0, sizeof(count)); 

			for(i = 0; arr[i]; ++i) 
			++count[arr[i]]; 

			for (i = 1; i <= RANGE; ++i) 
			count[i] += count[i-1]; 

			for (i = 0; arr[i]; ++i) 
			{ 
			output[count[arr[i]]-1] = arr[i]; 
			--count[arr[i]]; 
			} 

			for (i = 0; arr[i]; ++i) 
			arr[i] = output[i]; 
		}
	 void output(char* inp1, char* inp2)
	 {
	 	cout<<"Output: "<<inp1<<" + "<<inp2;
		if(count1>0&&count2>0)
		{
			cout<<" both string has a pattern of "<<search<<".";
		    countSort(combine); 
			cout<<"\nConcatenated Sorted Characters: "<<combine;
		}
		
		else
		{
				cout<<" one of the string has no pattern of "<<search<<".";
		        cout<<"\nConcatenated Characters: "<<strcat(inp1, inp2);
		}
	 }
	
};

int main()
{
	body gecille;
	gecille.input();
	gecille.count1=gecille.KMPSearch(gecille.search, gecille.inp1);
	gecille.count2=gecille.KMPSearch(gecille.search, gecille.inp2);
	gecille.output(gecille.inp1, gecille.inp2);
	return 0;
}
