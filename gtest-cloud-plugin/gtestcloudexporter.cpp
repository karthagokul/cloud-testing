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

#include "gtestcloudexporter.h"
#include <iostream>

GTestCloudExporter::GTestCloudExporter():
    mSuccessCount(0),mFailedCount(0)
{
}

void GTestCloudExporter::OnTestStart(const ::testing::TestInfo& test_info)
{
    std::cout<<"Running\t"<<test_info.test_case_name()<<"::"<<test_info.name()<<std::endl;
}

void GTestCloudExporter::OnTestPartResult(const ::testing::TestPartResult& test_part_result)
{
    std::cout<<test_part_result.file_name()<<" Line# "<<test_part_result.line_number()<<std::endl;
    std::cout<<test_part_result.summary()<<std::endl;
}

void GTestCloudExporter::OnTestEnd(const ::testing::TestInfo& test_info)
{
    if(test_info.result()->Passed())
    {
        std::cout<<"Succeeded"<<std::endl;
        mSuccessCount++;
    }
    else
    {
        std::cerr<<"Failed:"<<std::endl;
        mFailedCount++;
    }
    std::cout<<"Ended\t"<<test_info.test_case_name()<<"::"<<test_info.name()<<std::endl;
}
