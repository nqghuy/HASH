#include <bits/stdc++.h>
using namespace std;

struct node{
    string EnglishWord;
    string vietnamesWord;
    node *next;
};

//hash table size
const int HASH_TABLE_SIZE = 10;

//initialize hash table
node *hash_table[HASH_TABLE_SIZE];

//create new node
node *makeNode(string, string);

//retun index of value
int make_index(string);

//insert value into hash table
void insert_hash_table(string, string);

//return true if value is found in hash table
bool find (string);

int main()
{
    for (int i = 0; i < 5; i++){
        string EngWord, VietWord;
        getline(cin, EngWord);
        getline(cin, VietWord);
        insert_hash_table(EngWord, VietWord);
    }
    for (int i = 0; i < 5; i++){
        string word;
        getline (cin, word);
        if (!find(word))    cout << "not found\n";
    }
}

node *makeNode(string EngWord, string VieWord){
    node *newNode = new node();
    newNode->EnglishWord = EngWord;
    newNode->vietnamesWord = VieWord;
    newNode->next = NULL;
    return newNode;
}

int make_index(string EngWord){
    int i = 0;
	int j = 9;
	while (EngWord[i] != '\0')
	{
		j = (31 * j + EngWord[i]) % HASH_TABLE_SIZE;
		i++;
	}
	return j;
}

void insert_hash_table(string EngWord, string VieWord){
    int index = make_index(EngWord);
    node *newNode = makeNode(EngWord, VieWord);

    //check if hash table [index] is available
    if (hash_table[index] == NULL){
        hash_table[index] = newNode;
    }
    else{
        // insert new node in front 
        // node *tmp = hash_table[index];
        // while (tmp->next != NULL){
        //     tmp = tmp->next;
        // }
        // tmp->next = newNode;
        
        //insert new node back 
        newNode->next = hash_table[index];
        hash_table[index] = newNode;
    }
}

//find vietnamese or english word
bool find (string EngWord){
    int index = make_index(EngWord);
    node *current = hash_table[index];
    while (current){
        if (current->EnglishWord == EngWord){
            cout << current->EnglishWord << " : " << current->vietnamesWord << endl;
            return true;
        }
        current = current->next;
    }
    return false;
}
