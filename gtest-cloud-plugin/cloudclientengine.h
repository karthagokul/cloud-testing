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

#define USE_CURL
#define SERVER_URI "http://192.168.97.15/GTestCloud/updater.php?userid=%s&&machineid=%s&&successrate=%f&&country=%s&&details=%s"

/**
 * @brief The CloudClientEngine class
 */
class CloudClientEngine
{
public:
    /**
     * @brief CloudClientEngine Creates the Engine
     * @param aUserName User Name
     * @param aMACAddress MAC Address as Device ID
     * @param aCountry Country String
     */
    CloudClientEngine(const std::string &aUserName,const std::string &aMACAddress,const std::string &aCountry);

    ~CloudClientEngine();

    /**
     * @brief submit Submits the data to the cloud
     * @param aSuccessrate Success Rate
     * @param aDetails Details ,such as Error String If Any
     * @return
     */
    bool submit(const double &aSuccessrate,const std::string &aDetails);

protected:
#ifdef USE_CURL
    static size_t handle(char * data, size_t size, size_t nmemb, void * p);
    size_t handle_impl(char * data, size_t size, size_t nmemb);
#endif
    std::string convertSpaces(const std::string &aStr);
    std::string convertNewLine(const std::string &aStr);

private:
    std::string mUserName;
    std::string mDeviceId;
    std::string mCountry;

};

#endif // CLOUDCLIENTENGINE_H
