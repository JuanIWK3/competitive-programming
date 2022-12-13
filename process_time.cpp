#include <bits/stdc++.h>

using namespace std;

struct Process {
    int time;    
    bool has_interruption;
    int interruption_time;

    Process(int time, bool has_interruption, int interruption_time) {
        this->time = time;
        this->has_interruption = has_interruption;
        this->interruption_time = interruption_time;
    }
};

int main() {
    int quantity = 3;

    vector<Process*> process_list;
    
    for (int i = 0; i < quantity; i++) {
        int process_time;
        bool has_interruption;
        int interruption_time = 0;

        cout << "time: ";
        cin >> process_time;cin.ignore();
        cout << "has interruption? ";
        cin >> has_interruption;cin.ignore();

        if (has_interruption) {
            srand(time(NULL));
            interruption_time = rand()%10;
        }

        Process *process = new Process(process_time, has_interruption, interruption_time);
        process_list.push_back(process);
    }

    for (size_t i = 0; i < quantity; i++) {
        cout << "process: " << i << endl;
        cout << process_list[i]->time << ", " << process_list[i]->has_interruption << endl;
    }

    

  
    return 0;
}
