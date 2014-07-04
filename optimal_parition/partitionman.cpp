#include "partitionman.h"

PartitionMan::PartitionMan()
{
    mTotal=800;
    mOriginalData.push_back(500);
    mOriginalData.push_back(200);
    mOriginalData.push_back(100);
}

int PartitionMan::sumFromTo(int aStart,int aEnd)
{
    int sum=0;
    for(int j=aStart;j<aEnd;j++)
    {
        sum+=mOriginalData[j];
    }
    //std::cout<<" From "<<aStart<<" : "<<aEnd<<" Sum is "<<sum<<std::endl;
    return sum;
}

int PartitionMan::currentResultSum()
{
    int sum=0;

    for (int i=0;i<mResults.size()-1;i++)
    {
        //std::cout<<mResults[i]<<std::endl;
        sum+=sumFromTo(i,mResults.size());
    }
    return sum;
}

int PartitionMan::findOriginalSum(int index)
{
    int sum=0;

    for(int j=index;j<mOriginalData.size();j++)
    {
    int tmp=mOriginalData[j+1];
    mOriginalData[j+1]=mOriginalData[j];
    mOriginalData[j]=tmp;
    for (int i=0;i<mOriginalData.size()-1;i++)
    {
        //std::cout<<mOriginalData[i]<<std::endl;
        sum+=sumFromTo(i,mOriginalData.size());
    }
    std::cout<<"Sum is "<<sum<<std::endl;
    }
    return sum;
}

void PartitionMan::start()
{
    std::cout<<std::endl;

    //Lets assign the results
    mResults=mOriginalData;

    for(int i=0;i<mOriginalData.size()-1;i++)
    {
        int sum=findOriginalSum(i);
        if(sum<currentResultSum())
        {
            mResults=mOriginalData;
        }

    }

    std::cout<<std::endl;
}


