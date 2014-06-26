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

#include "cloudclientengine.h"

#include <stdio.h>
#include <string.h>

#ifdef USE_CURL
#include <curl/curl.h>
#endif

CloudClientEngine::CloudClientEngine(const std::string &aUserName,const std::string &aMACAddress,const std::string &aCountry)
{
    mUserName=convertSpaces(aUserName);
    mDeviceId=convertSpaces(aMACAddress);
    mCountry=convertSpaces(aCountry);
}

CloudClientEngine::~CloudClientEngine()
{
}

#ifdef USE_CURL
size_t CloudClientEngine::handle(char * data, size_t size, size_t nmemb, void * p)
{
    return static_cast<CloudClientEngine*>(p)->handle_impl(data, size, nmemb);
}

size_t CloudClientEngine::handle_impl(char* data, size_t size, size_t nmemb)
{
    std::string response(data);
    //std::cout<<"Response is"<<std::endl;
    //std::cout<<std::endl<<response;
    if (response.find("Success") == 0)
    {
        std::cout<<"Successfully Submitted the Test Results"<<std::endl;
    }
    else
    {
        std::cerr<<"Failed to Submit the Test Results"<<std::endl;
        std::cout<<std::endl<<response;
    }

    return size * nmemb;
}
#endif

bool CloudClientEngine::submit(const double &aSuccessrate,const std::string &aDetails)
{
    char formatstr[4096];
    char urlstr[4096];

    strcpy(formatstr,SERVER_URI);

    std::string details=convertSpaces(aDetails);
    details=convertNewLine(details);
    //std::cout<<details;

    sprintf(urlstr,formatstr,mUserName.c_str(),mDeviceId.c_str(),aSuccessrate,mCountry.c_str(),details.c_str());

#ifdef USE_CURL
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    CURLcode res;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,urlstr);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CloudClientEngine::handle);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        {
            std::cerr<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<std::endl;
            return false;
        }
    }
    else
    {
        std::cerr<<"Unable to Update the Results to Cloud"<<std::endl;
        return false;
    }
    curl_global_cleanup();

    return true;
#else
    std::cerr<<"Not Implemented"<<std::endl;
    return false;
#endif

}

std::string CloudClientEngine::convertSpaces(const std::string &aStr)
{
    std::string result=aStr;
    for (size_t pos = result.find(' ');
         pos != std::string::npos;
         pos = result.find(' ', pos))
    {
        result.replace(pos, 1, "%20");
    }
    return result;
}

std::string CloudClientEngine::convertNewLine(const std::string &aStr)
{
    std::string result=aStr;
    for (size_t pos = result.find('\n');
         pos != std::string::npos;
         pos = result.find('\n', pos))
    {
        result.replace(pos, 1, "%0A");
    }
    return result;
}
