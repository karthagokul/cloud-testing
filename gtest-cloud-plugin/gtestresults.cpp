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

#include "gtestresults.h"
#include <sstream>

GTest::GTest()
    :mName(""),mDetails(""),mSuccessFul(false)
{
}

void GTest::setName(const std::string &aName)
{
    mName=aName;
}

std::string GTest::name() const
{
    return mName;
}

void GTest::setSuccess(bool &aVal)
{
    mSuccessFul=aVal;
}

bool GTest::wasSuccess() const
{
    return mSuccessFul;
}

void GTest::setDetails(const std::string &aDetails)
{
    mDetails=aDetails;
}

void GTest::appendDetails(const std::string &aDetails)
{
    mDetails.append(aDetails);
}

std::string GTest::details() const
{
    return mDetails;
}


std::string GTestResults::printToString() const
{
    std::stringstream buffer;
    for( std::vector<GTest *>::const_iterator i = mList.begin(); i != mList.end(); ++i)
    {
        GTest *test=*i;
        buffer<<test->name();
        if(test->wasSuccess())
        {
            buffer<<" [ Success ]";
        }
        else
        {
            buffer<<" [ Failed ]";
            buffer<<std::endl<<test->details();
        }
        buffer<<std::endl;
    }
    return buffer.str();
}

double GTestResults::getSuccessRate() const
{
    double sum=mList.size();
    double successCount=0;
    for( std::vector<GTest *>::const_iterator i = mList.begin(); i != mList.end(); ++i)
    {
        GTest *test=*i;
        if(test->wasSuccess())
            successCount++;
    }
    double rate=(successCount/sum)*100;
    return rate;
}

GTestResults::~GTestResults()
{
    mList.clear();
}

bool GTestResults::addNew(const std::string &aName)
{
    GTest *aObj=new GTest();
    if(!aObj)
        return false;
    aObj->setName(aName);
    mList.push_back(aObj);
}

bool GTestResults::updateSuccess(bool aResult)
{
    if(mList.size()==0)
        return false;
    mList.back()->setSuccess(aResult);
    return true;
}

bool GTestResults::appendDetails(const std::string &aDetails)
{
    if(mList.size()==0)
        return false;

    mList.back()->appendDetails(aDetails);
    return true;
}

