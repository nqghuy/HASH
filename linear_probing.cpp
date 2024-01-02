#include <bits/stdc++.h>
using namespace std;

//hash table size const
const int HASH_TABLE_SIZE = 29;

//hash table
//hash table use linear probing so do not use struct node*
string hash_table[HASH_TABLE_SIZE] = {};

//hast table contain fruits
int make_index (string fruit){
    // int i = 0;
	// int j = 9;
	// while (fruit[i] != '\0')
	// {
	// 	j = (31 * j + fruit[i]) % HASH_TABLE_SIZE;
	// 	i++;
	// }
	// return j;
    return fruit[0] - 'a';
}

void insert(string fruit){
    int index = make_index(fruit);
    while (hash_table[index] != ""){
        //cycle index
        index = (index + 1) % HASH_TABLE_SIZE;
    }
    hash_table[index] = fruit;
}

int search(string fruit){
    int index = make_index(fruit);
    int copy_index = index;
    do{
        if (hash_table[index] == "")    return -1;
        if (hash_table[index] == fruit) return index;
        index = (index + 1) % HASH_TABLE_SIZE;
    }while (index != copy_index); // end a circle
    return -1;
}


int main(){
    for (int i = 0; i < 5; i++){
        string fruit;
        getline(cin, fruit);
        insert(fruit);
    }
    for (int i = 0; i < 5; i++){
        string fruit;
        getline(cin, fruit);
        int res = search(fruit);
        if (res != -1)  cout << res << endl;
        else cout << "no\n";
    }
}