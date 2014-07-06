#ifndef PARTITIONMAN_H
#define PARTITIONMAN_H

#include <iostream>
#include <vector>

class PartitionMan
{
public:
    PartitionMan();
    void start();
private:
    int sumFromTo(int aStart,int aEnd);
    int currentResultSum();
    int findOriginalSum();

public:
    void printPermutations();
private:
    int mTotal;
    std::vector<int> mOriginalData;
};

#endif // PARTITIONMAN_H
