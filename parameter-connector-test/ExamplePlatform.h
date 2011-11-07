/* <auto_header>
 * <FILENAME>
 * 
 * INTEL CONFIDENTIAL
 * Copyright © 2011 Intel 
 * Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel’s prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 *  AUTHOR: Patrick Benavoli (patrickx.benavoli@intel.com)
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 * 
 * 
 * </auto_header>
 */
#pragma once

#include <string>

using namespace std;

class CParameterMgrPlatformConnector;
class CParameterMgrPlatformConnectorLogger;
class ISelectionCriterionTypeInterface;
class ISelectionCriterionInterface;

class CExamplePlatform
{
public:
    enum State {
        EInitState,
        EState1,
        EState2,
        EState3,

        ENbStates
    };

    CExamplePlatform(const string& strClass);
    ~CExamplePlatform();

    // Start
    bool start(string& strError);

    // State
    bool setState(State eState, string& strError);

    // Dynamic parameter access
    bool setValue(const string& strPath, const string& strValue, string& strError);
    bool getValue(const string& strPath, string& strValue, string& strError) const;

private:
    // The connector
    CParameterMgrPlatformConnector* _pParameterMgrPlatformConnector;
    // Logger
    CParameterMgrPlatformConnectorLogger* _pParameterMgrPlatformConnectorLogger;
    // Criteria Types
    ISelectionCriterionTypeInterface* _pModeType;
    ISelectionCriterionTypeInterface* _pInputDeviceType;
    ISelectionCriterionTypeInterface* _pOutputDeviceType;

    // Criteria
    ISelectionCriterionInterface* _pMode;
    ISelectionCriterionInterface* _pSelectedInputDevice;
    ISelectionCriterionInterface* _pSelectedOutputDevice;
};