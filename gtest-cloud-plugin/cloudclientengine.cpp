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
