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

#include <gtest/gtest.h>
#include "gtestcloudexporter.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    //Lets remove all the default listners
    delete listeners.Release(listeners.default_result_printer());

    //Creates our own Cloud Plugin which gets the Test Events
    GTestCloudExporter *cloudexpo=new GTestCloudExporter();

    //Inits it and provides the ini file
    if(!cloudexpo->init("gcloud.ini"))
    {
        std::cerr<<"Initing Failed"<<std::endl;
        return -1;
    }

    //add it to the Google Testing Framework
    listeners.Append(cloudexpo);

    //Let's run all of the tests
    int value=RUN_ALL_TESTS();

    //Now we need to submit the results we have gathered to the cloud webserver ,So let's do it !
    std::cout<<"Trying to Submit the results to cloud"<<std::endl;
    if(!cloudexpo->submit())
    {
        std::cerr<<"Failed to Submit the data to server"<<std::endl;
        return -1;
    }

    return value;
}
