#pragma once
#ifndef CLIST
#define CLIST

struct  Node {
        int data;
        Node *prev, *next;
};

class Clist
{
    public:
        Clist();
        virtual ~Clist();
        Node *head;     // current node that is being pointed to
        int size;
        bool isEmpty();
        void addNodeAtBEG(char);           // inserted before head
        void addNodeAfter(char);            // inserted after head
        void addNodeBeforeData(char, Node*);// Same as above, inserted before/after a specific node
        void addNodeAfterData(char, Node*);
        void out(bool);     // Prints the list, true starts from beginning, false starts from end
        void setData(char);
        void setPrev(Node*);
        void setNext(Node*);
        bool findData(char);    // Searches through the list to find the char
        void deleteData(char, bool);

};

#endif // CLIST_H