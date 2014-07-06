#include "partitionman.h"

#include<algorithm>

int PartitionMan::sumFromTo(int aStart,int aEnd)
{
    int sum=0;
    for(int j=aStart;j<aEnd;j++)
    {
        sum+=mCurrentData[j];
    }
    return sum;
}

int PartitionMan::findCurrentSum()
{
    int sum=0;

    for (int i=0;i<(int)mCurrentData.size()-1;i++)
    {
        sum+=sumFromTo(i,mCurrentData.size());
    }

    return sum;
}

void PartitionMan::push(std::vector<int> aVecData)
{
    mData.push_back(aVecData);
}

void PartitionMan::process()
{
    std::cout<<"Output"<<std::endl;
    for(int i=0;i<(int)mData.size();i++)
    {
        //Fetch the data and process it ;
        mCurrentData=mData[i];
        int optimalsum=computeOptimal();
        std::cout<<optimalsum<<std::endl;
    }
}

int PartitionMan::computeOptimal()
{
    int sum=findCurrentSum();
    do
    {
        int cursum=findCurrentSum();
        if(sum>cursum)
            sum=cursum;

    } while(std::next_permutation(mCurrentData.begin(),mCurrentData.end()));

    return sum;
}


