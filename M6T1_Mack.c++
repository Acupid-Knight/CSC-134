
 // CSC 134
 // MackA
 // 3/24/25

 #include <iostream>
 using namespace std;

// CSC 134
// M6T1
// name
// 4/7/2025

int main () {
    
    // We have six stats, lets use names for them
    const int NUM_STATS = 6;
    const int STR = 0;
    const int DEX = 1;
    const int CON = 2;
    const int INT = 3;
    const int WIS = 4;
    const int CHA = 5;

    // other variables
    int stats[NUM_STATS];
    string stat_names[] = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};  // for user iput
    int current_stat;
    double total_stats;  // double makes average be double
    double average_stat; // tota; / num_stats

    cout << "Please eneter your character stats." << endl;
    for (int i=0; i<NUM_STATS; i++) {
        cout << "Stat: ";
        cin >> current_stat;
        stats[i] = current_stat;
    }
    // Find total and average
    average_stat = total_stats / NUM_STATS;
    // print all the stats
    cout << "Total: " << total_stats << " Average: " << average_stat << endl;
    cout << "Character Sheet: " << endl;
    for (int i=0; i<NUM_STATS; i++) {
        cout << stat_names[i] << ": " << stats[i] << endl;
        
    }
}
