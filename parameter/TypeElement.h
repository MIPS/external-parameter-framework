/*
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
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 */
#pragma once

#include "Element.h"

class CMappingData;
class CInstanceConfigurableElement;

class CTypeElement : public CElement
{
public:
    CTypeElement(const string& strName = "");
    virtual ~CTypeElement();

    // Instantiation
    CInstanceConfigurableElement* instantiate() const;

    // Mapping info
    virtual bool getMappingData(const string& strKey, const string*& pStrValue) const;
    virtual bool hasMappingData() const;

    /**
     * Returns the mapping associated to the current TypeElement instance
     *
     * @return A string containing the mapping as a comma separated key value pairs
     */
    virtual string getFormattedMapping() const;

    // Element properties
    virtual void showProperties(string& strResult) const;

    // From IXmlSink
    virtual bool fromXml(const CXmlElement& xmlElement, CXmlSerializingContext& serializingContext);

    // From IXmlSource
    virtual void toXml(CXmlElement& xmlElement, CXmlSerializingContext& serializingContext) const;

    // Scalar or Array?
    bool isScalar() const;

    // Array Length
    uint32_t getArrayLength() const;

    /**
     * Converts size optimized integer input data (int8, int16, int32) to plain int
     *
     * @param[in] iSizeOptimizedData the data to convert
     *
     * @return the data with int type
     */
    virtual int toPlainInteger(int iSizeOptimizedData) const;

protected:
    // Object creation
    virtual void populate(CElement* pElement) const;
private:
    CTypeElement(const CTypeElement&);
    CTypeElement& operator=(const CTypeElement&);
    // Actual instance creation
    virtual CInstanceConfigurableElement* doInstantiate() const = 0;

    // Mapping data creation and access
    CMappingData* getMappingData();

    // For Arrays. 0 means scalar
    uint32_t _uiArrayLength;

    // Mapping info
    CMappingData* _pMappingData;
};
