#include "partitionman.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <iterator>

/**
 * Utility Function which splits the line into std::vector data
 */
template<typename T>
std::vector<T> split(const std::string& line) {
    std::istringstream is(line);
    return std::vector<T>(std::istream_iterator<T>(is), std::istream_iterator<T>());
}

/**
 * @brief main Main Function
 * @return
 */
int main()
{
    PartitionMan pMan;
    std::vector<int> data;
    std::string input;
    int numberOfTestCases,numberOfDivisions;
    getline(std::cin,input);
    numberOfTestCases=atoi(input.c_str());
    for(int i=0;i<numberOfTestCases;i++)
    {
        getline(std::cin,input);
        numberOfDivisions=atoi(input.c_str());

        //Clear the std::vector for next set of data
        data.clear();
        getline(std::cin,input);

        //Converts the line string into std::vector<int>
        data=split<int>(input);;
        if((int)data.size()!=numberOfDivisions)
        {
            std::cerr<<"Entered data size doesn't match "<<data.size();
            return -1;
        }
        //Lets push the collected data
        pMan.push(data);
    }
    pMan.process();
    return 0;
}



