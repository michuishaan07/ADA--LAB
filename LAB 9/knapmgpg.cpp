#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Item {
    int weight;
    int value;
};


int mergeAndPurge(int W, const vector<Item>& items) {
    vector<pair<int, int>> s0 = {{0, 0}};

    for (const auto& item : items) {
        vector<pair<int, int>> si1; 
        for (const auto& pair : s0) {
            int Pj = pair.first;
            int Wj = pair.second;
            int P_prime = Pj + item.value;
            int W_prime = Wj + item.weight;

            if (W_prime <= W) {
                si1.push_back({P_prime, W_prime});
            }
        }

       
        s0.insert(s0.end(), si1.begin(), si1.end());

        
        vector<pair<int, int>> si;
        for (const auto& pair : s0) {
            bool add = true;
            int Pj = pair.first;
            int Wj = pair.second;

            for (const auto& p : s0) {
                int Pk = p.first;
                int Wk = p.second;
                if (Pk <= Pj && Wk >= Wj && !(Pk == Pj && Wk == Wj)) {
                    add = false;
                    break;
                }
            }

            if (add) {
                si.push_back(pair);
            }
        }

        s0 = si; 
    }

    
    int max_profit = 0;
    for (const auto& pair : s0) {
        max_profit = max(max_profit, pair.first);
    }

    return max_profit;
}

int main() {
    int W; 
    int n; 
    cout << "Enter the capacity of knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> items[i].weight >> items[i].value;
    }

    int max_value = mergeAndPurge(W, items);
    cout << "Maximum value in the knapsack: " << max_value << endl;

    return 0;
}
