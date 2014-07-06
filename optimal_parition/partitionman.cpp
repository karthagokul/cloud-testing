#include "partitionman.h"

#include<vector>
#include<algorithm>

PartitionMan::PartitionMan()
{
    mTotal=100;
    mOriginalData.push_back(30);
    mOriginalData.push_back(40);
    mOriginalData.push_back(10);
    mOriginalData.push_back(20);

}

void PartitionMan::printPermutations()
{

    do{
         std::cout<<mOriginalData[0]<<" "<<mOriginalData[1]<<" "<<mOriginalData[2]<<std::endl;;
     }

     while(std::next_permutation(mOriginalData.begin(),mOriginalData.end()));
}

int PartitionMan::sumFromTo(int aStart,int aEnd)
{
    int sum=0;
    for(int j=aStart;j<aEnd;j++)
    {
        sum+=mOriginalData[j];
    }
    return sum;
}


int PartitionMan::findOriginalSum()
{
    int sum=0;

    for (int i=0;i<mOriginalData.size()-1;i++)
    {
        sum+=sumFromTo(i,mOriginalData.size());
    }

   return sum;
}

void PartitionMan::start()
{
    std::cout<<std::endl;
    int sum=findOriginalSum();
    do
    {
        int cursum=findOriginalSum();

        /*for( std::vector<int>::const_iterator i = mOriginalData.begin(); i != mOriginalData.end(); ++i)
            std::cout << *i << ' '<<std::endl;
*/
        std::cout<<"Permutation Sum is "<<cursum<<" And Results sum is "<<sum<<std::endl;

        if(sum>cursum)
            sum=cursum;

    } while(std::next_permutation(mOriginalData.begin(),mOriginalData.end()));

    std::cout<<"Optimal Sum is "<<sum;
    std::cout<<std::endl;
}


