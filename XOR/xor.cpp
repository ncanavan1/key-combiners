#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstddef>
#include <array>
using namespace std;


vector<string> load_keys(string filepath){
    vector<string> keys;
    fstream newfile;
    newfile.open(filepath, ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            keys.push_back(tp);
        }
        newfile.close();
    }
    return keys;
}


array<uint8_t,16> key_gen(){
    array<uint8_t,16> key;

    for(int i=0;i<16;i++){
        
        key[i] = rand()%256;
    }
    return key;
}

array<uint8_t,16> XOR_keys(vector<array<uint8_t,16>> secret_keys){

    array<uint8_t,16> finalkey = secret_keys[0];
    for(auto & key : secret_keys){
        if(key != secret_keys[0]){
            for(int i=0;i<16;i++){
                finalkey[i] = finalkey[i] ^ key[i];
            }
        }
    }
    return finalkey;
}


int main(){
   // vector<string> keys = load_keys("../keys_128bits.txt");
   // cout << keys[0];
   // vector<uint8_t> key = gen_key(16);
   // cout << key[0];


    array<uint8_t,16> key1 = key_gen();
    array<uint8_t,16> key2 = key_gen();

    vector<array<uint8_t,16>> secret_keys;
    secret_keys.push_back(key1);
    secret_keys.push_back(key2);

    array<uint8_t,16> finalkey = XOR_keys(secret_keys);

    cout << "Secret key 1 : ";
    for(int i=0;i<16;i++){
        cout << unsigned(key1[i]) << " ";
    }

    cout << endl;
    cout << "Secret key 2 : ";
    for(int i=0;i<16;i++){
        cout << unsigned(key2[i]) << " ";
    }

    cout << endl;
    cout << "Final XOR key: ";
    for(int i=0;i<16;i++){
        cout << unsigned(finalkey[i]) << " ";
    }
    //cout << unsigned(key1) << " ^ " << unsigned(key2) << " = " << unsigned(finalkey) << endl;
}