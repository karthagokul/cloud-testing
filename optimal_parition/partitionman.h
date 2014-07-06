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

#ifndef PARTITIONMAN_H
#define PARTITIONMAN_H

#include <iostream>
#include <vector>

/**
 * @brief The PartitionMan class A Utility Engine class which does the Business Logic
 */
class PartitionMan
{
public:
    /**
     * @brief push Adds Input for processing
     * @param aVecData a vector of integers
     */
    void push(std::vector<int> aVecData);

    /**
     * @brief process Process the input and generates the optimal value ( prints on console )
     */
    void process();

private:

    /**
     * @brief sumFromTo Finds the Effort from one input to another
     * @param aStart Start Index
     * @param aEnd Stop Index
     * @return Sum as Integer
     */
    int sumFromTo(int aStart,int aEnd);

    /**
     * @brief findCurrentSum Finds the effort of current data set
     * @return  Sum as Integer
     */
    int findCurrentSum();

    /**
     * @brief computeOptimal Called by process function which does the calculation
     * @return  the optimal result of one input set
     */
    int computeOptimal();

private:
    //Data structure holds the current processing data for one input data set
    std::vector<int> mCurrentData;

    //Holds the compelete input data as a two diamensional vector
    std::vector<std::vector<int> > mData;
};

#endif // PARTITIONMAN_H
