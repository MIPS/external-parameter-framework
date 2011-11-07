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

#include "ParameterType.h"

class CIntegerParameterType : public CParameterType
{
public:
    CIntegerParameterType(const string& strName);

    // From IXmlSink
    virtual bool fromXml(const CXmlElement& xmlElement, CXmlSerializingContext& serializingContext);

    // Conversion
    virtual bool asInteger(const string& strValue, uint32_t& uiValue, CParameterAccessContext& parameterAccessContext) const;
    virtual void asString(const uint32_t& uiValue, string& strValue, CParameterAccessContext& parameterAccessContext) const;

    // Default value handling (simulation only)
    virtual uint32_t getDefaultValue() const;

    // Element properties
    virtual void showProperties(string& strResult) const;

    // CElement
    virtual string getKind() const;
private:
    // Range checking
    template <typename type> bool checkValueAgainstRange(const string& strValue, type value, CParameterAccessContext& parameterAccessContext, bool bHexaValue) const;

    // Signing
    bool _bSigned;
    // Range
    uint32_t _uiMin;
    uint32_t _uiMax;
};