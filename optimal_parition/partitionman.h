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
    int findOriginalSum(int index);
private:
    int mTotal;
    std::vector<int> mOriginalData;
    std::vector<int> mResults;
};

#endif // PARTITIONMAN_H
