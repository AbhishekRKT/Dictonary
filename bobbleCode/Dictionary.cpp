#include <bits/stdc++.h> 
using namespace std; 



// Structure of Trie 
struct Trie { 
	bool isLast; 
	unordered_map<char, Trie*> map; 
	int freq; 
}; 






// function for creating new tries
Trie* makeNode() 
{ 
	Trie* Node = new Trie; 
	Node->isLast = false; 
	return Node; 
} 






// Function to Insert a students name  with their frequencies
// in the dictionary for building trie 

void InsertionOfWords(Trie*& rootNode, const string& str, 
			const int& freq) 
{ 

	// If rootNode is null 
	if (rootNode == NULL) 
		rootNode = makeNode(); 

	Trie* t = rootNode; 

	for (int i = 0; i < str.length(); i++) 
    { 
		char x = str[i]; 


		//to make the new  node if there is no path 
		if (t->map.find(x) == t->map.end()) 
			t->map[x] = makeNode(); 

		t = t->map[x]; 
	} 

	// Mark last name and store the meaning 
	t->isLast = true; 
	t->freq = freq; 
} 







// Function to find a student in the Trie and return its freq if it exists

 int find(Trie * rootNode, string word)
 {
     if(rootNode == NULL) return -1;
     Trie* t = rootNode; 

	// find a student name in Trie 

	for (int i = 0; i < word.length(); i++)
     { 
		t = t->map[word[i]]; 
		if (t == NULL) 
			return -1; 
	} 

    if (t->isLast) 
		return t->freq; 
    return -1;    
 }





//  This is derived function
 
int main() 
{ 
	Trie* rootNode = NULL; 


	// Build the dictionary 
	ifstream myFile;
	myFile.open("EnglishDictionary.csv");
	string freq;
    string  words, line;

	vector<pair<string, int>> v;
	int f;

	while(getline(myFile, line))
    {
		stringstream st(line);
		getline(st, words, ',');
		getline(st, freq, ',');
		f = stoi(freq);
		v.push_back({word,f});
	}

	for(auto it : v){
		InsertionOfWords(rootNode, it.first, it.second);
	}
	
    int answer = find(rootNode, "keyboard");
	if(answer != -1) cout << "YES " << answer << endl;
	else cout << "NO\n";

	return 0;              
}