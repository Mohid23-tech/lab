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

// Linked List for Tasbeeh Counter
class TasbeehCounter {
private:
    ZikrNode* head;
public:
    TasbeehCounter() : head(NULL) {}
    
    void addZikr(string zikr, int count) {
        ZikrNode* newNode = new ZikrNode(zikr, count);
        newNode->next = head;
        head = newNode;
        cout << "Added Zikr: " << zikr << " (Count: " << count << ")" << endl;
    }
    
    void displayZikrHistory() {
        if (!head) {
            cout << "No Zikr history." << endl;
            return;
        }
        cout << "\nZikr History:\n";
        ZikrNode* temp = head;
        while (temp) {
            cout << temp->zikr << ": " << temp->count << " times" << endl;
            temp = temp->next;
        }
    }
    
    ~TasbeehCounter() {
        while (head) {
            ZikrNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

