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

#include "Syncer.h"
#include <stdint.h>

class CInstanceConfigurableElement;

class CSubsystemObject : public ISyncer
{
public:
    CSubsystemObject(CInstanceConfigurableElement* pInstanceConfigurableElement);
    virtual ~CSubsystemObject();

    // from ISyncer
    virtual bool sync(CParameterBlackboard& parameterBlackboard, bool bBack, string& strError);

protected:
    // Blackboard data location
    uint8_t* getBlackboardLocation() const;
    // Size
    uint32_t getSize() const;
    // Conversion utility
    static uint32_t asInteger(const string& strValue);
    static string asString(uint32_t uiValue);

    // Sync to/from HW
    virtual bool sendToHW(string& strError);
    virtual bool receiveFromHW(string& strError);
    // Fall back HW access
    virtual bool accessHW(bool bReceive, string& strError);
    // Blackboard access from subsystems
    void blackboardRead(void* pvData, uint32_t uiSize);
    void blackboardWrite(const void* pvData, uint32_t uiSize);
    // Logging
    void log(const string& strMessage, ...) const;
private:
    // Instance element to sync from/to
    CInstanceConfigurableElement* _pInstanceConfigurableElement;
    // Data size
    uint32_t _uiDataSize;
    // Blackboard data location
    uint8_t* _pucBlackboardLocation;
    // Accessed index for Subsystem read/write from/to blackboard
    uint32_t _uiAccessedIndex;
};
