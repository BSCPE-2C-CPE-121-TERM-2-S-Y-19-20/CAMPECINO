#include <bits/stdc++.h> 
#include<string.h> 

using namespace std;

class wordsearch
{
	public:
		
		char inp1[100], inp2[100], search[100];
		char combine[100], temp1[100]; 
		int count1, count2;
		
		int KMPSearch(char* pat, char* txt) 
		{ 
			int M = strlen(pat); 
			int N = strlen(txt); 

			int lps[M]; 

			computeLPSArray(pat, M, lps); 

			int i = 0;  
			int j = 0; 
			int count=0;
			while (i < N) { 
				if (pat[j] == txt[i]) { 
					j++; 
					i++; 
				} 

				if (j == M) { 
					count++;
					j = lps[j - 1]; 
				} 
 
				else if (i < N && pat[j] != txt[i]) { 
			
					if (j != 0) 
						j = lps[j - 1]; 
					else
						i = i + 1; 
				}
			}
			return count; 
		} 

		void computeLPSArray(char* pat, int M, int* lps) 
		{ 
			int len = 0; 

			lps[0] = 0; 
			int i = 1; 
			while (i < M) { 
				if (pat[i] == pat[len]) { 
					len++; 
					lps[i] = len; 
					i++; 
						} 
				else 
				{ 
			 
					if (len != 0) { 
						len = lps[len - 1]; 
					} 
					else 
					{ 
						lps[i] = 0; 
						i++; 
					} 
				} 
			} 
		} 

};
