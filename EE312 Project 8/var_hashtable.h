//
// Created by zanez on 8/13/2020.
//

#ifndef PROJECT8_VAR_HASHTABLE_H
#define PROJECT8_VAR_HASHTABLE_H


#include <iostream>
#include <cstring>

using namespace std;

/*
 * This is a hash table holding int values.
 * The hash table has an array of Nodes called buckets.
 *
 */

struct Node { // Linked list to hold entries at each position.
    int el; // value to be entered in the hash table
    Node* next;
    char* name;
    long hash () {
        return name[0]*31 + name[1]*31*31 + el;
    }
};

class HashTable {
private:
    Node** buckets; // An array of Node pointers.
    int size; // size of the table, not the number of entries

    int hash(int el) { // Hash function is a modulo function
        return el % size;
    }

    int hash(Node& n) {
        return n.hash() % size;
    }

public:
    HashTable(int size) {
        this->size = size;
        buckets = new Node*[size]; // create an array of Node pointers
        for (int i = 0; i < size; i++) {
            buckets[i] = NULL; // initialize each Node pointer in array
        }
    }

    void insert(char* name, int el) {
        if (find(name)) return;
        Node* n = new Node(); // create a new Node object
        n->el = el; // initialize new Node's variables
        n->name = name;
        n->next = NULL;

        int ix = hash(el);  // calculate the place where the new value will be placed
        if (buckets[ix] != NULL) { // find the start of the linked list at that place ix
            n->next = buckets[ix];
        }
        buckets[ix] = n;
    }

    bool find(char* name) { // find the value el in the list
        int ix = 0;// find the index of the hash table where the element might be
        while(ix < size) {
            Node *head = buckets[ix]; // the head of the linked-list at location ix
            while (head != NULL) { // search through the linked-list at that location
                if (!strcmp(head->name, name)) { // if found, return true
                    return true;
                }
                head = head->next;
            }
            ix ++;
        }
        return false;

    }
    int find_num(char* name){
        int ix = 0;// find the index of the hash table where the element might be
        while(ix < size) {
            Node *head = buckets[ix]; // the head of the linked-list at location ix
            while (head != NULL) { // search through the linked-list at that location
                if (!strcmp(head->name, name)) { // if found, return true
                    return head->el;
                }
                head = head->next;
            }
            ix ++;
        }
        return 0;


    }


    void printMe() {
        for (int i = 0; i < this->size; i++) {
            cout << i << " ";
            Node *head = buckets[i];
            while (head != NULL) {
                cout << head->name << " ";
                cout << head->el << " ";

                head = head->next;
            }
            cout << endl;
        }
    }
};


#endif //PROJECT8_VAR_HASHTABLE_H
