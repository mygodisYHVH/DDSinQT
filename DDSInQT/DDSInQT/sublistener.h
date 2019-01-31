#ifndef SUBLISTENER_H
#define SUBLISTENER_H

#include "sonarProtoTypeSupportC.h"
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include "sonarProtoTypeSupportImpl.h"
#include"sonarProtoTypeSupportC.h"
#include"sonarProtoC.h"
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <QObject>
using org::omg::dds::SonarSimu::SonarProtocol;
class SubListener;
class SubListener_ : public DDS::DataReaderListener
{
public:
    void on_data_available(DDS::DataReader * dr);
    void on_requested_deadline_missed(
        DDS::DataReader_ptr reader,
        const DDS::RequestedDeadlineMissedStatus & status);

    void on_requested_incompatible_qos(
        DDS::DataReader_ptr reader,
        const DDS::RequestedIncompatibleQosStatus & status);

    void on_liveliness_changed(
        DDS::DataReader_ptr reader,
        const DDS::LivelinessChangedStatus & status);

    virtual void on_subscription_matched(
        DDS::DataReader_ptr reader,
        const DDS::SubscriptionMatchedStatus & status
    );

    void on_sample_rejected(
        DDS::DataReader_ptr reader,
        const DDS::SampleRejectedStatus& status
    );

    void on_sample_lost(
        DDS::DataReader_ptr reader,
        const DDS::SampleLostStatus& status
    );
    SubListener *par;
};

class SubListener:public QObject
{
    Q_OBJECT
public:
	SubListener(){
		ddsListener.par = this;
    }

    ~SubListener(){

    }

    SubListener_ ddsListener;
    void sendData(SonarProtocol data);
signals:
    void emitData(QByteArray data);
};

//class SubListener
//{
//public:
//    SubListener();
//};

#endif // SUBLISTENER_H
