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
#include "sysutils.h"

GTestCloudExporter::GTestCloudExporter(const std::string &aUserName,const std::string &aNetworkInterfaceName,const std::string &aCountryName):
    mSuccessCount(0),mFailedCount(0)
{
    std::string deviceId;
    deviceId=SysUtils::getMACAddress(aNetworkInterfaceName);
    if(deviceId.empty())
    {
        std::cerr<<"Device ID Is Empty "<<std::endl;
        deviceId="UnKnown";
    }
    mCloudEngine=new CloudClientEngine(aUserName,deviceId,aCountryName);


}

GTestCloudExporter::~GTestCloudExporter()
{
    //std::cout<<__PRETTY_FUNCTION__<<std::endl;
    if(mCloudEngine)
    {
        delete mCloudEngine;
        mCloudEngine=0;
    }
}

void GTestCloudExporter::OnTestStart(const ::testing::TestInfo& test_info)
{
    //std::cout<<"Running\t"<<test_info.test_case_name()<<"::"<<test_info.name()<<std::endl;
    std::string name=std::string(test_info.test_case_name());
    name.append("::");
    name.append(std::string(test_info.name()));
    mResultsTable.addNew(name);
}

void GTestCloudExporter::OnTestPartResult(const ::testing::TestPartResult& test_part_result)
{
    //    std::cerr<<std::endl;
    //    std::cerr<<test_part_result.file_name()<<" Line Number : "<<test_part_result.line_number()<<std::endl;
    //    std::cerr<<test_part_result.summary()<<std::endl;
    //    std::cerr<<std::endl;

    if(!mResultsTable.appendDetails(test_part_result.summary()))
    {
        std::cerr<<"Unable to Append";
        exit;
    }
}

void GTestCloudExporter::OnTestEnd(const ::testing::TestInfo& test_info)
{
    //std::cout<<test_info.test_case_name()<<"::"<<test_info.name()<<"\t";
    mResultsTable.updateSuccess(test_info.result()->Passed());

}

bool GTestCloudExporter::submit()
{
    bool status=true;

    status=mCloudEngine->submit(mResultsTable.getSuccessRate(),mResultsTable.printToString());

    return status;
}
