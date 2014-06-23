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

#ifndef SYSUTILS_H
#define SYSUTILS_H

#include <iostream>
#include <string>

/**
 * @brief The SysUtils class A utility class to do some system related activities
 */
class SysUtils
{
public:
    /**
     * @brief getMACAddress Returns the MAC Address of a particular Interface
     * @param aInterfaceName Interface Name to be which MACID is requested
     * @return The Mac Address on Success , if not empty string
     */
    static std::string getMACAddress(const std::string &aInterfaceName);
};

#endif // SYSUTILS_H
