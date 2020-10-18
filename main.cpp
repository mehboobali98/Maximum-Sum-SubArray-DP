#include <iostream>
#include <vector>

using namespace std;

int bottomUp(vector<int> Array, int &start, int &end);

void printVector(vector<int> Array, int start, int end);

int main() {

    vector<int> Array;
    Array.push_back(-3);
    Array.push_back(1);
    Array.push_back(-8);
    Array.push_back(4);
    Array.push_back(-1);
    Array.push_back(2);
    Array.push_back(1);
    Array.push_back(-5);
    Array.push_back(5);


    /*
    Array.push_back(-2);
    Array.push_back(-3);
    Array.push_back(4);
    Array.push_back(-1);
    Array.push_back(-2);
    Array.push_back(1);
    Array.push_back(5);
    Array.push_back(-3);
     */

    vector<int> subArray;
    int end = 0, start = 1;
    cout << "Sum: " << bottomUp(Array, start, end) << endl;
    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;
    printVector(Array, start, end+1);

    return 0;
}

int bottomUp(vector<int> Array, int &start, int &end) {

    int sum = 0, n = Array.size();
    vector<int> OPT(n);
    OPT.at(0) = 0;
    for (int i = 1; i < n; i++) {
        if (OPT.at(i - 1) + Array.at(i) < 0) {
            OPT.at(i) = 0;
            start = i + 1;
        } else {
            OPT.at(i) = OPT.at(i - 1) + Array.at(i);
        }
        if (sum < OPT.at(i)) {
            sum = OPT.at(i);
            end = i;
        }
    }
    return sum;
}

void printVector(vector<int> Array, int start, int end) {
    for (int i = start; i < end; i++)
        cout << Array.at(i) << " ";
}
