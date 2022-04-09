
//  Sorting Network
//
//  Created by Shayan Aryania


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> read_numbers(int count) {
    vector<int> result;
    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        result.push_back(number);
    }
    return result;
}

vector<string> read_network(int num_of_inputs) {
    vector<string> result;
    for (int i = 0; i < num_of_inputs; ++i) {
        string line;
        cin >> line;
        result.push_back(line);
    }
    return result;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool is_valid_network(vector<string> network, int num_of_stages) {
    for (int j = 0; j < num_of_stages; ++j) {
        for (int i = 0; i < network.size(); ++i) {
            if (network[i][j] == '-')
                continue;
            
            int count = 0;
            for (int k = 0; k < network.size(); k++)
                if (network[i][j] == network[k][j])
                    count++;

            if (count != 2) {
                return false;
            }
        }
    }
    return true;
}

void apply(vector<string> network, int j, vector<int>& numbers) {
    for (int i = 0; i < network.size() - 1; i++) {
        if (network[i][j] == '-')
            continue;

        for (int k = i + 1; k < network.size(); k++)
            if (network[i][j] == network[k][j])
                if (numbers[i] > numbers[k])
                    swap(numbers[i], numbers[k]);
    }
}

bool sorted(vector<int> numbers) {
    for (int i = 0; i < numbers.size() - 1; i++)
        if (numbers[i] > numbers[i+1])
            return false;
    return true;
}

void process_testcase(int _Num_Of_Numbers, int _Num_Of_Netlines) {
    vector<string> network = read_network(_Num_Of_Netlines);
    vector<int> numbers = read_numbers(_Num_Of_Numbers);

    if (!is_valid_network(network, _Num_Of_Netlines)) {
        cout << "Invalid network\n";
        return;
    }

    for (int j = 0; j < _Num_Of_Netlines; j++)
        apply(network, j, numbers);

    if (sorted(numbers))
        cout << "Sorted";
    else
        cout << "Not sorted";
    cout << endl;
}

int main() {
    int Num_Of_Numbers;
    int Num_Of_Netlines;

    cin >> Num_Of_Numbers >> Num_Of_Netlines;
    while (Num_Of_Numbers != 0 && Num_Of_Netlines != 0) {
        process_testcase(Num_Of_Numbers, Num_Of_Netlines);
        cin >> Num_Of_Numbers >> Num_Of_Netlines;
    }
}

//For input You can Try
// 4 4
// ac-e
// a-de
// b-df
// bc-f
