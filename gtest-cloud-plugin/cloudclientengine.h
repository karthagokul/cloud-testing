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
#define SERVER_URI "http://10.254.84.103:8080/GTestCloud/updater.php?userid=%s&&machineid=%s&&successrate=%f&&country=%s"

/**
 * @brief The CloudClientEngine class
 */
class CloudClientEngine
{
public:
    /**
     * @brief CloudClientEngine
     * @param aUserName
     * @param aMACAddress
     * @param aCountry
     */
    CloudClientEngine(const std::string &aUserName,const std::string &aMACAddress,const std::string &aCountry);

    ~CloudClientEngine();

    /**
     * @brief submit
     * @param aSuccessrate
     * @param aDetails
     * @return
     */
    bool submit(const double &aSuccessrate,const std::string &aDetails);

#ifdef USE_CURL
protected:
    static size_t handle(char * data, size_t size, size_t nmemb, void * p);
    size_t handle_impl(char * data, size_t size, size_t nmemb);
#endif

private:
    std::string mUserName;
    std::string mDeviceId;
    std::string mCountry;

};

#endif // CLOUDCLIENTENGINE_H
