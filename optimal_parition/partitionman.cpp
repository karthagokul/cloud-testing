/* Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**/

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
    std::cout<<"Results ( Optimal Effort ) for the Input Provided "<<std::endl;
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


