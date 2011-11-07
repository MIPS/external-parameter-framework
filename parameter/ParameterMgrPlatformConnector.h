/*  ParameterMgrPlatformConnector.h
 **
 ** Copyright © 2011 Intel
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **     http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 **
 ** AUTHOR: Patrick Benavoli (patrickx.benavoli@intel.com)
 ** CREATED: 2011-06-01
 ** UPDATED: 2011-07-27
 **
 */
#pragma once

#include "SelectionCriterionTypeInterface.h"
#include "SelectionCriterionInterface.h"

class CParameterMgr;
class CParameterMgrLogger;

class CParameterMgrPlatformConnector
{
    friend class CParameterMgrLogger;
public:
    // Logger interface
    class ILogger
    {
    public:
        virtual void log(const std::string& strLog) = 0;
    };

    // Construction
    CParameterMgrPlatformConnector(const std::string& strSystemClassName);
    ~CParameterMgrPlatformConnector(); // Not virtual since not supposed to be derived!

    // Selection Criteria interface. Beware returned objects are lent, clients shall not delete them!
    // Should be called before start
    ISelectionCriterionTypeInterface* createSelectionCriterionType(bool bIsInclusive = false);
    ISelectionCriterionInterface* createSelectionCriterion(const std::string& strName, const ISelectionCriterionTypeInterface* pSelectionCriterionType);
    // Selection criterion retrieval
    ISelectionCriterionInterface* getSelectionCriterion(const std::string& strName);

    // Logging
    // Should be called before start
    void setLogger(ILogger* pLogger);

    // Start
    bool start(std::string& strError);

    // Configuration application
    bool applyConfigurations(std::string& strError);

    // Dynamic parameter handling
    bool setValue(const std::string& strPath, const std::string& strValue, std::string& strError, bool bRawValueSpace = false);
    bool getValue(const std::string& strPath, std::string& strValue, std::string& strError, bool bRawValueSpace = false, bool bHexOutputRawFormat = false) const;

private:
    // Private logging
    void doLog(const std::string& strLog);

    // Implementation
    CParameterMgr* _pParameterMgr;
    // State
    bool _bStarted;
    // Logging
    ILogger* _pLogger;
    // Private logging
    CParameterMgrLogger* _pParameterMgrLogger;
};
