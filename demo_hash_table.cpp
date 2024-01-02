#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};

//hash table size
const int HASH_TABLE_SIZE = 11;

//initialize hash table
node *hash_table[HASH_TABLE_SIZE];

//create new node
node *makeNode(int value);

//retun index of value
int make_index(int value);

//insert value into hash table
void insert_hash_table(int value);

//return true if value is found in hash table
bool find (int value);

int main()
{
    for (int i = 0; i < 5; i++){
        int tmp; cin >> tmp;
        insert_hash_table(tmp);
    }
    for (int i = 0; i < 5; i++){
        int tmp; cin >> tmp;
        if (find(tmp)){
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}

node *makeNode(int value){
    node *newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int make_index(int value){
    return value % HASH_TABLE_SIZE;
}

void insert_hash_table(int value){
    int index = make_index(value);
    node *newNode = makeNode(value);

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

bool find (int value){
    int index = make_index(value);
    node *current = hash_table[index];
    while (current){
        if (current->data == value){
            return true;
        }
        current = current->next;
    }
    return false;
}
