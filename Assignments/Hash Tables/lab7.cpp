#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;  

const int HASHSIZE = 4001;

class HashTable {
private:
    struct HashEntry {
        string key;
        int value;
    };

    HashEntry table[HASHSIZE];
    int numElements;
    int accessProbes;

public:
    HashTable() : numElements(0), accessProbes(0) {
        // Initialize the hash table with empty keys and zero values
        for (int i = 0; i < HASHSIZE; ++i) {
            table[i].key = "";
            table[i].value = 0;
        }
    }

    int hash(const std::string& key) {
        int hashValue = 0;
        for (size_t i = 0; i < key.length(); ++i) // Loop through the characters of the key
        {
            // Calculate the hash value using a hash function
            hashValue = (hashValue * 31 + key[i]) % HASHSIZE;
        }
        return hashValue;
    }

    void update(const std::string& key) {
        int index = hash(key);
        while (!table[index].key.empty() && table[index].key != key) {
            index = (index + 1) % HASHSIZE;  // Linear probing to handle collisions
            accessProbes++;
        }
        if (table[index].key.empty()) {
            // Insert the key with a value of 1 and increment the element count
            table[index].key = key;
            table[index].value = 1;
            numElements++;
        } else {
            // Key already exists; increment its value
            table[index].value++;
        }
    }

    int size() const {
        // Return the number of unique elements in the hash table
        return numElements;
    }

    int probes() const {
        // Return the number of array accesses (probes)
        return accessProbes;
    }
};

int main() {
    HashTable hashTable;
    int updates[HASHSIZE] = {0}; // Array for updates
    int cost[HASHSIZE] = {0};    // Array for cost

    ifstream inputFile("RomeoAndJuliet.txt");  // Open the input file

    if (!inputFile) {
        cerr << "Error opening file." << endl;  // Handle file opening errors
        return 1;
    }

    string word;
    while (inputFile >> word) {
        hashTable.update(word);
        updates[hashTable.size()]++;
        cost[hashTable.size()] += hashTable.probes();
    }

    inputFile.close();  // Close the input file

    cout << "Number of unique words: " << hashTable.size() << endl;  // Output the number of unique words
    cout << "\n\nCost per update:" << endl;

    for (int i = 1; i <= hashTable.size(); i++) {
        if (updates[i] > 0) {
            double ratio = static_cast<double>(cost[i]) / updates[i];
            cout << fixed << setprecision(2) << ratio;  // Output cost per update
        } else {
            cout << "0.00";
        }

        if (i < hashTable.size()) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
