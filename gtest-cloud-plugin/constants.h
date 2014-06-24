#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <vector>

class GTest
{
private:
    std::string mName;
    bool mSuccessFul;
    std::string mDetails;

public:
    GTest()
        :mName(""),mDetails(""),mSuccessFul(false)
    {
    }

    void setName(const std::string &aName)
    {
        mName=aName;
    }

    std::string name() const
    {
        return mName;
    }

    void setSuccess(bool &aVal)
    {
        mSuccessFul=aVal;
    }

    bool wasSuccess() const
    {
        return mSuccessFul;
    }

    void setDetails(const std::string &aDetails)
    {
        mDetails=aDetails;
    }

    void appendDetails(const std::string &aDetails)
    {
        mDetails.append(aDetails);
    }

    std::string details() const
    {
        return mDetails;
    }


};

class GTestResults
{
public:
    GTestResults()
    {

    }

    void print()
    {
        for( std::vector<GTest *>::const_iterator i = mList.begin(); i != mList.end(); ++i)
        {
            GTest *test=*i;
            std::cout<<test->name();
            if(test->wasSuccess())
            {
                std::cout<<" [ Success ]";
            }
            else
            {
                std::cout<<" [ Failed ]";
                std::cout<<std::endl<<test->details();
            }
            std::cout<<std::endl;

        }
    }

    int getAverage()
    {
        return 0;
    }

    ~GTestResults()
    {
        mList.clear();
    }

    bool addNew(std::string aName)
    {
        GTest *aObj=new GTest();
        if(!aObj)
            return false;
        aObj->setName(aName);
        mList.push_back(aObj);
    }

    bool updateSuccess(bool aResult)
    {
        if(mList.size()==0)
            return false;
        mList.back()->setSuccess(aResult);
        return true;
    }

    bool appendDetails(std::string aDetails)
    {
        if(mList.size()==0)
            return false;

        mList.back()->appendDetails(aDetails);
        return true;
    }

private:
    std::vector<GTest*> mList;
};



#endif // CONSTANTS_H
