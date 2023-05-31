#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(const int &data = 0, Node *next = NULL) : data(data), next(next) {}
    Node *next;
    int data;
};

class LinkedList
{
    Node *root;
    Node *tail;

public:
    LinkedList() : root(NULL)
    {
        root = new Node();
        tail = root;
    }
    Node *begin() const
    {

        return root->next;
    }
    Node *end() const
    {
        return tail->next;
    }
    bool isempty() const
    {
        return begin() == end();
    }
    void push_back(const int &value)
    {
        insert(end(), value);
    }
    void pop_back()
    {
        erase(end());
    }
    void print()
    {

        Node *temp = begin();
        while (temp !=end())
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
    void push_front(const int &value)
    {
        Node *temp = new Node(value);
        temp->next = root;
        root = temp;
    }
    int front() const
    {
        return begin()->data;
    }
    int back()
    {

        return tail->data;
    }
    void insert(Node *pos, const int &value)
    {
        if (pos == end())
        {
            tail->next = new Node(value);
            tail = tail->next;
        }
        else
        {
            Node *tmp = root;
            while (tmp->next != pos)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node(value, tmp->next);
        }
    }
    void erase(Node *pos)
    {
        if (isempty())
        {
            throw "bos";
        }
        Node *prev = root;
        if (pos == end() || pos == tail)
        {
            pos = tail;
            while (prev->next != pos)
            {
                prev = prev->next;
            }
            prev->next = pos->next;
            tail = prev;
        }
        else
        {
            while (prev->next != pos)
            {
                prev = prev->next;
            }
            prev->next = pos->next;
        }
        delete pos;
    }
};

int main(int argc, char const *argv[])
{

    LinkedList *li = new LinkedList();
    li->push_back(12);
    li->push_back(67);

    li->push_back(56);
    li->push_back(78);

    li->print();
    li->pop_back();
    li->pop_back();
    std::cout << "" << std::endl;
    li->print();

    return 0;
}
