#ifndef IALARMHOST_H
#define IALARMHOST_H
#include "alarmhostdefine.h"
#include "idevice.h"

class IAlarmHost :public IDevice
{
public:

	/****************************AlarmHost method begin******************************************/
	virtual _ALARMHOSTTYPE getAlarmHostType() = 0;

	/****************************AlarmHost method  end*******************************************/


	/****************************camera method  begin*********************************************/
	virtual _CAMERATYPE getCameraType(){return _OTHER_IPC;}
	virtual CameraId loginCamera(_OEASY_LOGINFO loginfo, _OEASY_LOGIN_RESULTINFO resultInfo) {return 0;}
	virtual OEASY_S32 logoutCamera() {return 0;}
	virtual void setLiveDataCB( LIVEDATACALLBACK videoDataCB, void *pUser ){}
	virtual LiveplayId openVideo(_STREAMTYPE streamtype, OEASY_BOOL bstartsms = OEASY_FALSE, OEASY_CHAR* mediaserverurl = "") {return 0;}
	virtual OEASY_BOOL closeVideo(LiveplayId handle) {return OEASY_TRUE;}
	virtual OEASY_S32 captureImage( OEASY_U8 *picBuffer, OEASY_DWORD bufferSize, OEASY_DWORD* sizeReturned ) {return 0;}
	virtual OEASY_S32 setAlarmParam( _ALARMSETTING *param ) {return 0;}
	virtual OEASY_S32 startAlarm(ALARMMESGCALLBACK alarmMsgCB, void *pUser) {return 0;}
	virtual OEASY_S32 stopAlarm() {return 0;}
	//unused
	virtual OEASY_BOOL release() {return OEASY_TRUE;}
	/****************************camera method  end**********************************************/

	/****************************Intercom method begin******************************************/
	virtual _INTERCOMTYPE getIntercomType() {return _OTHER_INERCOM;}
	virtual void Intercom_startServer( OEASY_U16 serverport ) {return;}
	virtual void Intercom_stopServer() {return;}
	/****************************Intercom method  end*******************************************/


};

#endif //IALARMHOST_H