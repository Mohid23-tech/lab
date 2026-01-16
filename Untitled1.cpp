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
// Queue for Prayer Reminders
class PrayerQueue {
private:
    static const int MAX = 5; // For 5 daily prayers
    string prayers[MAX];
    int front, rear;
public:
    PrayerQueue() : front(-1), rear(-1) {}
    
    bool isFull() { return rear == MAX - 1; }
    bool isEmpty() { return front == -1 || front > rear; }
    
    void addPrayer(string prayer) {
        if (isFull()) {
            cout << "Prayer queue is full!" << endl;
            return;
        }
        if (isEmpty()) front = 0;
        prayers[++rear] = prayer;
        cout << "Added Prayer Reminder: " << prayer << endl;
    }
    
    void displayNextPrayer() {
        if (isEmpty()) {
            cout << "No prayer reminders." << endl;
            return;
        }
        cout << "Next Prayer: " << prayers[front++] << endl;
        if (front > rear) front = rear = -1; // Reset if queue is empty
    }
};




























