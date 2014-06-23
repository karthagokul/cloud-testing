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

#define USE_CURL

#ifdef USE_CURL
#include <curl/curl.h>
#endif

CloudClientEngine::CloudClientEngine(CloudClientEngineObserver *aObserver)
    :mObserver(aObserver)
{
}

CloudClientEngine::~CloudClientEngine()
{
}

bool CloudClientEngine::submit()
{
#ifdef USE_CURL
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    CURLcode res;
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL,SERVER_URI);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel&project=curl");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            std::cerr<<"curl_easy_perform() failed: "<<curl_easy_strerror(res)<<std::endl;
            return false;
        }
        curl_easy_cleanup(curl);
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
