#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DDSInQT.h"
#include "sonarProtoTypeSupportC.h"
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include "sonarProtoTypeSupportImpl.h"
#include"sonarProtoTypeSupportC.h"
#include"sonarProtoC.h"
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DdsDcpsInfrastructureC.h>

#include"sublistener.h"
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;
class DDSInQT : public QMainWindow
{
	Q_OBJECT

public:
	DDSInQT(DDS::DomainParticipant_var participant,
		const std::string& partition,QWidget *parent = Q_NULLPTR);
    DDS::DomainParticipant_var participant_;
    DDS::Topic_var             simuTopic_;
    DDS::Publisher_var         publisher_;
    DDS::Subscriber_var        subscriber_;
    DDS::DataWriter_var writer_;
    SubListener   *listener_;
    SonarProtocolDataWriter_var dw;
    SonarProtocolDataReader_var dr;
    int domainID;
    QString topicName;
    QString memberName;
public slots:
    void  receiveDataFromDDS(QByteArray data);
private slots:
    void on_toolButton_clicked();

    void on_write_clicked();

private:
	Ui::DDSInQTClass ui;



};
