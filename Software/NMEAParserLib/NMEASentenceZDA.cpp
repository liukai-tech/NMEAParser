/*
* MIT License
*
*  Copyright (c) 2018 VisualGPS, LLC
*
*  Copyright (c) 2020 Caesar
*
*  Add ZDA Sentence parse.
*
*  Modify by Caesar in 2020/03/25(792910363@qq.com)
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
*
*/
#include <stdlib.h>
#include "NMEASentenceZDA.h"

CNMEASentenceZDA::CNMEASentenceZDA()
{
	ResetData();
}

CNMEASentenceZDA::~CNMEASentenceZDA() {
}

CNMEAParserData::ERROR_E CNMEASentenceZDA::ProcessSentence(char * pCmd, char * pData)
{
    UNUSED_PARAM(pCmd);
    char szField[c_nMaxField];
	char szTemp[c_nMaxField];

    // Time
	if (GetField(pData, szField, 0, c_nMaxField) == CNMEAParserData::ERROR_OK) {
		m_SentenceData.m_nHour = (szField[0] - '0') * 10 + (szField[1] - '0');
		m_SentenceData.m_nMinute = (szField[2] - '0') * 10 + (szField[3] - '0');
		m_SentenceData.m_nSecond = (szField[4] - '0') * 10 + (szField[5] - '0');
        m_SentenceData.m_nMillisecond = (szField[7] - '0') * 10;
	}

	//
    // Day
	//
	if (GetField(pData, szField, 1, c_nMaxField) == CNMEAParserData::ERROR_OK)
	{
        szTemp[0] = szField[0];
        szTemp[1] = szField[1];
        szTemp[2] = '\0';
        m_SentenceData.m_nDay = atoi(szTemp);
	}

	//
    // Month
	//
    if (GetField(pData, szField, 2, c_nMaxField) == CNMEAParserData::ERROR_OK)
	{
        szTemp[0] = szField[0];
        szTemp[1] = szField[1];
        szTemp[2] = '\0';
        m_SentenceData.m_nMonth = atoi(szTemp);
	}

	//
    // Year
	//
    if (GetField(pData, szField, 3, c_nMaxField) == CNMEAParserData::ERROR_OK)
	{
        szTemp[0] = szField[0];
        szTemp[1] = szField[1];
        szTemp[2] = szField[2];
        szTemp[3] = szField[3];
        szTemp[4] = '\0';
        m_SentenceData.m_nYear = atoi(szTemp);
	}

	return CNMEAParserData::ERROR_OK;
}

void CNMEASentenceZDA::ResetData(void)
{
    m_SentenceData.m_nDay = 0;
    m_SentenceData.m_nHour = 0;
    m_SentenceData.m_nYear = 0;
    m_SentenceData.m_nMonth = 0;
    m_SentenceData.m_nMinute = 0;
    m_SentenceData.m_nSecond = 0;
    m_SentenceData.m_nMillisecond = 0;
}
