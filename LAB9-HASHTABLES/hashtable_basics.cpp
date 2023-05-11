#include <cstring>
#include <string>
#include <iostream>
using namespace std;


struct HashTable{
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void intialize_hashtable(){
        for (int i = 0; i < 4; i++){
            password[i].clear();
        }
    }
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].empty()){
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name){
        int sum = 0;
        int hash = 0;
        for(auto i : user_name){
            sum += int(i);
        }
        hash = sum % MAX_LENGTH;
        return hash;
    }
    bool is_slot_empty(int hash){
        bool empty = password[hash].empty();
        return empty;
    }
    void insert(string user_name,string user_password){
        int hash;
        int length ;
        bool empty;
        hash = hashfunc(user_name);
        int index = hash ;
        int start =0;
        length = password->size();
        empty = is_slot_empty(hash);
        if(empty){
            password[hash] = user_password;
        }
        else{
            while(empty != true &&  index < length   ){
                index++;
                empty = is_slot_empty(index);
            }
            if(empty){
                password[index]= user_password;

            }
            while(empty != true && start<hash ){

                empty= is_slot_empty(start);
                if(empty){
                    break;
                }
                start++;

            }
            if(empty){
                password[start]=user_password;
            }
        }
    }
    void hash_lookup(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        int index = hash;
        if(empty){
            cout<<"Username Not Found";
        }
        else{
            cout<<password[hash];
        }

	//add an if condition to complete the code here
	
	
	
    }
    void delete_item(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);
        empty = is_slot_empty(hash);
        if(empty){
            cout<<"No item found\n";
        }
        else{
            password[hash].clear();
            cout<<"User deleted\n";
        }

    }
    void print_hashtable(){
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->"<<password[i]<<"\n";
        }
    }
};

int main(){
    HashTable * hashtbl = new HashTable;
    hashtbl->intialize_hashtable();
    cout<< hashtbl->isFull()<<"\n";

    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "Type command: ";
        cin >> command;
        switch (command){
        case 1:
            /* insert the new item*/
            cout << "Enter user name: ";
            cin >> user_name;
            cout << "Enter password to be saved: ";
            cin >> password;
            hashtbl->insert(user_name,password);
            break;
        case 2:
            /* delete item */
            cout << "Enter item to be deleted: ";
            cin >> user_name;
            hashtbl->delete_item(user_name);
            break;
        case 3:
            /* hash lookup password*/
            cout << "Enter user name to look up password:";
            cin >> user_name;
            hashtbl->hash_lookup(user_name);
            break;
        case 4:
            hashtbl->print_hashtable();
            break;
        case -1:
            /* hash lookup password*/
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
