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

#ifndef CLOUDCLIENTENGINE_H
#define CLOUDCLIENTENGINE_H

#include <iostream>
#include <string>

#define SERVER_URI "http://10.254.84.103:8080/GTestCloud/updater.php?userid=%s&&machineid=%s&&successrate=%d&&country=%s"

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
