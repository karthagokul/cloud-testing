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

#ifndef GTESTRESULTS_H
#define GTESTRESULTS_H

#include <iostream>
#include <vector>

/**
 * @brief The GTest class
 */
class GTest
{
public:
    /**
     * @brief GTest
     */
    GTest();

    /**
     * @brief setName
     * @param aName
     */
    void setName(const std::string &aName);

    /**
     * @brief name
     * @return
     */
    std::string name() const;

    /**
     * @brief setSuccess
     * @param aVal
     */
    void setSuccess(bool &aVal);

    /**
     * @brief wasSuccess
     * @return
     */
    bool wasSuccess() const;

    /**
     * @brief setDetails
     * @param aDetails
     */
    void setDetails(const std::string &aDetails);

    /**
     * @brief appendDetails
     * @param aDetails
     */
    void appendDetails(const std::string &aDetails);

    /**
     * @brief details
     * @return
     */
    std::string details() const;

private:
    std::string mName;
    bool mSuccessFul;
    std::string mDetails;
};

class GTestResults
{
public:
    ~GTestResults();
    /**
     * @brief printToString
     * @return
     */
    std::string printToString() const;

    /**
     * @brief getSuccessRate
     * @return
     */
    double getSuccessRate() const;

    /**
     * @brief addNew
     * @param aName
     * @return
     */
    bool addNew(const std::string &aName);

    /**
     * @brief updateSuccess
     * @param aResult
     * @return
     */
    bool updateSuccess(bool aResult);

    /**
     * @brief appendDetails
     * @param aDetails
     * @return
     */
    bool appendDetails(const std::string &aDetails);

private:
    std::vector<GTest*> mList;
};

#endif // GTESTRESULTS_H
