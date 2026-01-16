#include <iostream>
#include <string>
using namespace std;

// Node for Linked List (Tasbeeh Counter)
struct ZikrNode {
    string zikr;
    int count;
    ZikrNode* next;
    ZikrNode(string z, int c) : zikr(z), count(c), next(NULL) {}
};

