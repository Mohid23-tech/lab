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

// Stack for Prophet Stories Navigation
class StoryStack {
private:
    static const int MAX = 10; // Max stories
    string stories[MAX];
    int top;
public:
    StoryStack() : top(-1) {}
    
    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }
    
    void pushStory(string story) {
        if (isFull()) {
            cout << "Story stack is full!" << endl;
            return;
        }
        stories[++top] = story;
        cout << "Navigated to: " << story << endl;
    }
    
    void popStory() {
        if (isEmpty()) {
            cout << "No previous story to go back to." << endl;
            return;
        }
        cout << "Back to: " << stories[top--] << endl;
    }
};

// Node for Binary Tree (Study Planner)
struct StudyNode {
    string task;
    int studyTime;
    StudyNode* left;
    StudyNode* right;
    StudyNode(string t, int time) : task(t), studyTime(time), left(NULL), right(NULL) {}
};

// Binary Tree for Study Planner
class StudyPlanner {
private:
    StudyNode* root;
    
    void addTaskRec(StudyNode*& node, string task, int time) {
        if (!node) {
            node = new StudyNode(task, time);
            cout << "Added Task: " << task << " (" << time << " mins)" << endl;
            return;
        }
        addTaskRec(node->left, task, time); // Add to left for simplicity
    }
    
    void displayRec(StudyNode* node) {
        if (!node) return;
        cout << "Task: " << node->task << ", Time: " << node->studyTime << " mins" << endl;
        displayRec(node->left);
        displayRec(node->right);
    }
    
    void deleteTree(StudyNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
public:
    StudyPlanner() : root(NULL) {}
    
    void addTask(string task, int time) {
        addTaskRec(root, task, time);
    }
    
    void displayTasks() {
        if (!root) {
            cout << "\nNo study tasks assigned.\n";
            return;
        }
        cout << "\nStudy Plan:\n";
        displayRec(root);
    }
    
    ~StudyPlanner() {
        deleteTree(root);
    }
};

int main() {
    TasbeehCounter tasbeeh;
    PrayerQueue prayerQueue;
    StoryStack storyStack;
    StudyPlanner planner;
    int choice;
    
    cout << "\n=== Sacred Space - Islamic App ===\n";
    do {
        cout << "\n1. Add Zikr (Tasbeeh Counter)\n";
        cout << "2. View Zikr History\n";
        cout << "3. Add Prayer Reminder\n";
        cout << "4. View Next Prayer\n";
        cout << "5. Navigate to Prophet Story\n";
        cout << "6. Go Back to Previous Story\n";
        cout << "7. Add Study Task\n";
        cout << "8. View Study Plan\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline for getline
        
        switch (choice) {
            case 1: {
                string zikr;
                int count;
                cout << "Enter Zikr (e.g., SubhanAllah): ";
                getline(cin, zikr);
                cout << "Enter count: ";
                cin >> count;
                cin.ignore(); // Clear newline after count
                tasbeeh.addZikr(zikr, count);
                break;
            }
            case 2:
                tasbeeh.displayZikrHistory();
                break;
            case 3: {
                string prayer;
                cout << "Enter prayer name (e.g., Fajr): ";
                getline(cin, prayer);
                prayerQueue.addPrayer(prayer);
                break;
            }
            case 4:
                prayerQueue.displayNextPrayer();
                break;
            case 5: {
                string story;
                cout << "Enter story title: ";
                getline(cin, story);
                storyStack.pushStory(story);
                break;
            }
            case 6:
                storyStack.popStory();
                break;
            case 7: {
                string task;
                int time;
                cout << "Enter study task (e.g., Read Surah Yasin): ";
                getline(cin, task);
                cout << "Enter time (minutes): ";
                cin >> time;
                cin.ignore(); // Clear newline after time
                planner.addTask(task, time);
                break;
            }
            case 8:
                planner.displayTasks();
                break;
            case 9:
                cout << "Exiting Sacred Space.Until next time stay connected to your Deen. JazakAllah Khair!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
    
    return 0;
}

























