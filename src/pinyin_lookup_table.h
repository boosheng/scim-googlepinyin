/*
 * Copyright (C) 2009 Kov Chai <tchaikov@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GOOGLEPINYIN_LOOKUP_TABLE_H
#define GOOGLEPINYIN_LOOKUP_TABLE_H

#define Uses_SCIM_LOOKUP_TABLE
#include <scim.h>

using namespace scim;

class DecodingInfo;

class PinyinLookupTable : public LookupTable
{
    const DecodingInfo* m_dec_info;
    
    PinyinLookupTable (const PinyinLookupTable &);
    const PinyinLookupTable & operator= (const PinyinLookupTable &);

public:
    PinyinLookupTable(const DecodingInfo *decoding_info,
                      int page_size = 10);
    ~PinyinLookupTable();
    virtual WideString get_candidate (int index) const;
    /**
     * @param index global offset
     */
    virtual AttributeList get_attributes (int index) const;
    virtual uint32 number_of_candidates () const;
    virtual void clear();
};

#endif//GOOGLEPINYIN_LOOKUP_TABLE_H
