#ifndef PARTITIONMAN_H
#define PARTITIONMAN_H

#include <iostream>
#include <vector>

class PartitionMan
{
public:
    void process();
    void push(std::vector<int> aVecData);

private:
    int sumFromTo(int aStart,int aEnd);
    int findCurrentSum();
    int computeOptimal();

private:
    std::vector<int> mCurrentData;
    std::vector<std::vector<int> > mData;
};

#endif // PARTITIONMAN_H
