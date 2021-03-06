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

#ifndef GTESTCLOUDEXPORTER_H
#define GTESTCLOUDEXPORTER_H

#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "gtestresults.h"
#include "cloudclientengine.h"


/**
 * @brief The GTestCloudExporter class
 */
class GTestCloudExporter: public ::testing::EmptyTestEventListener
{
public:
    /**
     * @brief GTestCloudExporter Constructor
     * @param aUserName UserName  which is used to access the webserver
     * @param aNetworkInterfaceName Primary Network InterfaceName used
     */
    GTestCloudExporter();

    /**
     * @brief init Inits the plugin with a configuration where the necessary information is provided
     * @param aFileLocation Configuration file name
     * @return True for success false for failure
     */
    bool init(const char *aFileLocation);

    ~GTestCloudExporter();

    /**
     * @brief submit
     * @return True for Success and False for failure
     */
    bool submit();

    //Overriden from Listner
protected:
    virtual void OnTestStart(const ::testing::TestInfo& test_info);
    virtual void OnTestPartResult(const ::testing::TestPartResult& test_part_result);
    virtual void OnTestEnd(const ::testing::TestInfo& test_info);
private:
    int mSuccessCount;
    int mFailedCount;
    CloudClientEngine *mCloudEngine;
    GTestResults mResultsTable;

};

#endif // GTESTCLOUDEXPORTER_H
