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
    :mUserName(aUserName),mDeviceId(aMACAddress),mCountry(aCountry)
{
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
    std::cout<<"Server Says"<<response;
    if (response.find("Success") == 0)
    {
        std::cout<<"Successfully Submitted the Test Results"<<std::endl;
    }
    else
    {
        std::cerr<<"Failed to Submit the Test Results"<<std::endl;
    }

    return size * nmemb;
}
#endif

bool CloudClientEngine::submit(const double &aSuccessrate,const std::string &aDetails)
{
    char formatstr[4096];
    char urlstr[4096];


    strcpy(formatstr,SERVER_URI);
    sprintf(urlstr,formatstr,mUserName.c_str(),mDeviceId.c_str(),aSuccessrate,mCountry.c_str());

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

    if(curl)
    {
        delete curl;
        curl=0;
    }

    return true;
#else
    std::cerr<<"Not Implemented"<<std::endl;
    return false;
#endif

}
