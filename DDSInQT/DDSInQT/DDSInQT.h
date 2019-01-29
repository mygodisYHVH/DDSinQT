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
    SubListener   listener_;
    int domainID;
    QString topicName;
    QString memberName;
private slots:
    void on_toolButton_clicked();

private:
	Ui::DDSInQTClass ui;



};
