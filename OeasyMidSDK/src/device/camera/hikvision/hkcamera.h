#ifndef HK_CAMERA_H
#define HK_CAMERA_H

#include "cameradefine.h"
#include "icamera.h"
#include <iostream>
#include<map>
#include<string>
#include "OeasyMidSdk.h"
#include "HCNetSDK.h"
using namespace OeasyMidIPC;

using namespace std;
using namespace OeasyMid;

namespace OeasyMid_HK{

	class HKCamera : public ICamera
	{
	public:
		HKCamera();
		virtual ~HKCamera();
		virtual _CAMERATYPE getCameraType();
		virtual CameraId loginCamera(_OEASY_LOGINFO loginfo, _OEASY_LOGIN_RESULTINFO resultInfo);
		virtual OEASY_S32 logoutCamera();
		virtual void setLiveDataCB( LIVEDATACALLBACK videoDataCB, void *pUser );
		virtual LiveplayId openVideo(_STREAMTYPE streamtype, OEASY_BOOL bstartsms = OEASY_FALSE, OEASY_CHAR* mediaserverurl = "");
		virtual OEASY_BOOL closeVideo(LiveplayId liveid);
		virtual OEASY_S32 captureImage( OEASY_U8 *picBuffer, OEASY_DWORD bufferSize, OEASY_DWORD* sizeReturned );

		virtual OEASY_S32 setAlarmParam( _ALARMSETTING *param );
		virtual OEASY_S32 startAlarm(ALARMMESGCALLBACK alarmMsgCB, void *pUser);
		virtual OEASY_S32 stopAlarm();

		//callback 
		static void exceptionCB(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
		static void CALLBACK realDataCallback(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser);
		//alarm
		static BOOL CALLBACK MsgCallBack(LONG lCommand, NET_DVR_ALARMER *pAlarmer, char *pAlarmInfo, DWORD dwBufLen, void* pUser);

	private:
		CameraId m_cameraID;
		LiveplayId m_liveplayID;
		OEASY_BOOL m_bmainstartSMS; //主码流是否上传到流服务器
		OEASY_BOOL m_bsubstartSMS; //子码流是否上传到流服务器
		LIVEDATACALLBACK m_liveDataCB;
		void *m_pUserData; 
		ALARMMESGCALLBACK m_alarmMsgCB;
		void *m_pAlarmUserData;
	};
}

#endif //HK_CAMERA_H
