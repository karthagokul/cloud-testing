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
#include "iniReader/C++/iniReader.h"

GTestCloudExporter::GTestCloudExporter():
    mSuccessCount(0),mFailedCount(0)
{
}

bool GTestCloudExporter::init(const char *aConfigFile)
{
    if(!parseIniFile(aConfigFile))
    {
        std::cerr<<"Unable to find the file"<<std::endl;
        return false;
    }
    std::string username=getOptionToString("username");
    std::string networkiFace=getOptionToString("network_interface");
    std::string country=getOptionToString("country");

    if(username.empty()||networkiFace.empty()||country.empty())
    {
        std::cerr<<"Unable to Fetch all the required fields from the conf file"<<std::endl;
        return false;
    }
    std::string deviceId=SysUtils::getMACAddress(networkiFace);
    if(deviceId.empty())
    {
        std::cerr<<"Device ID Is Empty ;Please check the interface name provided "<<std::endl;
        return false;
    }

    //If everything goes well, lets create the back end engine
    mCloudEngine=new CloudClientEngine(username,deviceId,country);
    return true;

}

GTestCloudExporter::~GTestCloudExporter()
{
    if(mCloudEngine)
    {
        delete mCloudEngine;
        mCloudEngine=0;
    }
}

void GTestCloudExporter::OnTestStart(const ::testing::TestInfo& test_info)
{
    std::string name=std::string(test_info.test_case_name());
    name.append("::");
    name.append(std::string(test_info.name()));
    mResultsTable.addNew(name);
}

void GTestCloudExporter::OnTestPartResult(const ::testing::TestPartResult& test_part_result)
{
    if(!mResultsTable.appendDetails(test_part_result.summary()))
    {
        std::cerr<<"Unable to Append";
        exit(-1);
    }
}

void GTestCloudExporter::OnTestEnd(const ::testing::TestInfo& test_info)
{
    mResultsTable.updateSuccess(test_info.result()->Passed());

}

bool GTestCloudExporter::submit()
{
    bool status=true;

    status=mCloudEngine->submit(mResultsTable.getSuccessRate(),mResultsTable.printToString());

    return status;
}
