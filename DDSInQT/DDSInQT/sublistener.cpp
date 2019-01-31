#include "sublistener.h"
#include "sonarProtoTypeSupportC.h"
#include<stdio.h>
#include<iostream>

using org::omg::dds::SonarSimu::SonarProtocol;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupport_var;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;
using org::omg::dds::SonarSimu::SonarProtocolSeq;
using namespace  std;
void SubListener_::on_data_available(DDS::DataReader * dr)
{

    //Hello::StringMsgSeq   samples;
    SonarProtocolSeq samples;
    DDS::SampleInfoSeq    samples_info;
    DDS::ReturnCode_t      retval;
    DDS::SampleStateMask   ss = DDS::ANY_SAMPLE_STATE;
    DDS::ViewStateMask     vs = DDS::ANY_VIEW_STATE;
    DDS::InstanceStateMask is = DDS::ANY_INSTANCE_STATE;

    /* Convert to our type-specific DataReader */
    org::omg::dds::SonarSimu::SonarProtocolDataReader_var reader = org::omg::dds::SonarSimu::SonarProtocolDataReader::_narrow(dr);

    /* Take any and all available samples.  The take() operation
     * will remove the samples from the DataReader so they
     * won't be available on subsequent read() or take() calls.
     */

    retval =
    reader->read(samples,
        samples_info,
        DDS::LENGTH_UNLIMITED,
        DDS::ANY_SAMPLE_STATE,
        DDS::ANY_VIEW_STATE,
        DDS::ANY_INSTANCE_STATE);
    int count = 0;
    if (samples.length() > 0) {
        CORBA::Long sampleIndex = -1;
        CORBA::ULong i = 0;
        count++;
        while (i < samples.length())
        {
            SonarProtocol ddd = samples[i];
            par->sendData(ddd);
            ++i;
        }

    }
}

void SubListener_::on_requested_deadline_missed(
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus & status)
{
    printf("ERROR (%s) on_requested_deadline_missed\n",
        "DDS_error(retval)");
}

void SubListener_::on_requested_incompatible_qos(
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus & status)
{
    printf("ERROR (%s) on_requested_incompatible_qos\n",
        "DDS_error(retval)");
}

void SubListener_::on_liveliness_changed(
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus & status)
{
    printf("ERROR (%s) on_liveliness_changed\n",
        "DDS_error(retval)");
}

void SubListener_::on_subscription_matched(
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus & status
)
{
    printf("ERROR (%s) on_subscription_matched\n",
        "DDS_error(retval)");
}

void SubListener_::on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status
)
{
    printf("ERROR (%s) on_sample_rejected\n",
        "DDS_error(retval)");
}

void SubListener_::on_sample_lost(
    DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status
)
{
    printf("ERROR (%s) on_sample_lost\n",
        "DDS_error(retval)");
}


//SubListener::SubListener()
//{
//    ddsListener = new SubListener_;
//}

//SubListener::~SubListener()
//{

//}

void SubListener::sendData(org::omg::dds::SonarSimu::SonarProtocol data)
{
    QByteArray dat((char*)data.data.get_buffer(),data.OctetSeqLength);

    emitData(dat);
}
