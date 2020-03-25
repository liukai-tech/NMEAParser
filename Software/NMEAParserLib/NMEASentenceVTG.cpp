 /*
 * MIT License
 *
 *  Copyright (c) 2018 VisualGPS, LLC
 *
 *  Copyright (c) 2020 Caesar
 *
 *  Add VTG Sentence parse.
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


#include "NMEASentenceVTG.h"
#include <stdlib.h>

CNMEASentenceVTG::CNMEASentenceVTG() {
	// TODO Auto-generated constructor stub

}

CNMEASentenceVTG::~CNMEASentenceVTG() {
	// TODO Auto-generated destructor stub
}

CNMEAParserData::ERROR_E CNMEASentenceVTG::ProcessSentence(char *pCmd, char *pData) {

    UNUSED_PARAM(pCmd);
    char szField[c_nMaxField];

    //
    // TrackAngle
    //
	if (GetField(pData, szField, 0, c_nMaxField) == CNMEAParserData::ERROR_OK) {
        m_SentenceData.m_dTrackAngle = atof(szField);
    }else {
        m_SentenceData.m_dTrackAngle = 0.0;
    }

    //
    // MagneticAngle
    //
    if (GetField(pData, szField, 2, c_nMaxField) == CNMEAParserData::ERROR_OK) {
        m_SentenceData.m_dMagneticAngle = atof(szField);
    }else {
        m_SentenceData.m_dMagneticAngle = 0.0;
    }

	//
    // Speed over ground knots
	//
    if (GetField(pData, szField, 4, c_nMaxField) == CNMEAParserData::ERROR_OK)
	{
        m_SentenceData.m_dSpeedKnots = atof(szField);
    }else {
        m_SentenceData.m_dSpeedKnots = 0.0;
    }

    //
    // Speed over ground km/h
    //
    if (GetField(pData, szField, 6, c_nMaxField) == CNMEAParserData::ERROR_OK)
    {
        m_SentenceData.m_dSpeedKm = atof(szField);
    }else {
        m_SentenceData.m_dSpeedKm = 0.0;
    }

	return CNMEAParserData::ERROR_OK;
}

void CNMEASentenceVTG::ResetData(void) {
    m_SentenceData.m_dTrackAngle = 0.0;
    m_SentenceData.m_dMagneticAngle = 0.0;
    m_SentenceData.m_dSpeedKnots = 0.0;
    m_SentenceData.m_dSpeedKm = 0.0;
}
