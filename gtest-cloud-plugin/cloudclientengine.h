#ifndef CLOUDCLIENTENGINE_H
#define CLOUDCLIENTENGINE_H

#include <iostream>
#include <string>

#define SERVER_URI "http://localhost/gtest-server"

enum CloudClientEngineError
{
    CloudUnabletoConnect,
    CloudUnabletoPost,
    CloudWrongMessageFormat
};

class CloudClientEngineObserver
{
public:
    virtual void onCloudClientError(const CloudClientEngineError &aStatus , const std::string &aErrorMessage)=0;
};

class CloudClientEngine
{
public:
    CloudClientEngine(CloudClientEngineObserver *aObserver);
    ~CloudClientEngine();
    bool submit();

private:
    CloudClientEngineObserver *mObserver;
};

#endif // CLOUDCLIENTENGINE_H
