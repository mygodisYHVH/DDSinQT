#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DDSInQT.h"
#include "sonarProtoTypeSupportC.h"
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
class DDSInQT : public QMainWindow
{
	Q_OBJECT

public:
	DDSInQT(DDS::DomainParticipant_var participant,
		const std::string& partition,QWidget *parent = Q_NULLPTR);

private:
	Ui::DDSInQTClass ui;
	DDS::Topic_var             simuTopic_;
	DDS::DomainParticipant_var participant_;
	DDS::Publisher_var         publisher_;
	DDS::Subscriber_var        subscriber_;
};
