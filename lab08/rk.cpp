// /* Following program is a C++ implementation of Rabin Karp
// Algorithm given in the CLRS book */
// #include <bits/stdc++.h>
// using namespace std;

// // d is the number of characters in the input alphabet
// #define d 256

// /* pat -> pattern
// 	txt -> text
// 	q -> A prime number
// */
// void search(char pat[], char txt[], int q)
// {
// 	int M = strlen(pat);
// 	int N = strlen(txt);
// 	int i, j;
// 	int p = 0; // hash value for pattern
// 	int t = 0; // hash value for txt
// 	int h = 1;

// 	// The value of h would be "pow(d, M-1)%q"
// 	for (i = 0; i < M - 1; i++)
// 		h = (h * d) % q;

// 	// Calculate the hash value of pattern and first
// 	// window of text
// 	for (i = 0; i < M; i++) {
// 		p = (d * p + pat[i]) % q;
// 		t = (d * t + txt[i]) % q;
// 	}

// 	// Slide the pattern over text one by one
// 	for (i = 0; i <= N - M; i++) {

// 		// Check the hash values of current window of text
// 		// and pattern. If the hash values match then only
// 		// check for characters one by one
// 		if (p == t) {
// 			/* Check for characters one by one */
// 			for (j = 0; j < M; j++) {
// 				if (txt[i + j] != pat[j]) {
// 					break;
// 				}
// 			}

// 			// if p == t and pat[0...M-1] = txt[i, i+1,
// 			// ...i+M-1]

// 			if (j == M)
// 				cout << "Pattern found at index " << i
// 					<< endl;
// 		}

// 		// Calculate hash value for next window of text:
// 		// Remove leading digit, add trailing digit
// 		if (i < N - M) {
// 			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

// 			// We might get negative value of t, converting
// 			// it to positive
// 			if (t < 0)
// 				t = (t + q);
// 		}
// 	}
// }

// /* Driver code */
// int main()
// {
// 	char txt[] = "GEEKS FOR GEEKS";
// 	char pat[] = "GEEK";

// 	// we mod to avoid overflowing of value but we should
// 	// take as big q as possible to avoid the collison
// 	int q = INT_MAX;

// 	// Function Call
// 	search(pat, txt, q);
// 	return 0;
// }

// // This is code is contributed by rathbhupendra


















#include <bits/stdc++.h> 
using namespace std; 
const int t = 256;
const int w = 1283;

void Rabin_Karp_Algorithm(string text,string pattern){
    
    //Length of text string.
    int tlen = text.length();
    
    //Length of pattern string.
    int plen = pattern.length();
    
    int flag;
    int c=1,i=0;
    
    //Calculate hash_p(hash value of pattern) and hash_0
    int hash_p=0,hash=0;
    while(i<plen){
        hash_p=(hash_p*t + pattern[i])%w;
        hash=(hash*t + text[i])%w;
        i++;
    }
    
     //Calculate (t^(plen-1))%w
    for(int i=1;i<=plen-1;i++)
        c=(c*t)%w;
    
    i=0;
    while(i<=tlen-plen){
       if(hash_p==hash){
            flag=1;
            for(int j=0;j<plen;j++){
                if(pattern[j]==text[i+j]){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
           }
            if(flag==1)cout<<i<<" ";
       }
       
       
       //Calculate hash value of next window
       //hash_i+1 = t * {hash_i - text[i] * t^(plen-1)} + text[i+plen]
       if(i<tlen-plen){
           hash=((t*(hash-text[i]*c))+text[i+plen])%w;
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }
}

          
 
int main() 
{ 
    string text = "ababcdabcb"; 
    string pattern="abc";
    Rabin_Karp_Algorithm(text,pattern);
    return 0; 
}
