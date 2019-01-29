#include "configuration.h"
#include "ui_configuration.h"
#include "DDSInQT.h"
extern DDSInQT *mainWindow;
extern DDS::DomainParticipant_var participant;
extern std::string partition;
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include<iostream>

using org::omg::dds::SonarSimu::SonarProtocol;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupport_var;
using org::omg::dds::SonarSimu::SonarProtocolTypeSupportImpl;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter;
using org::omg::dds::SonarSimu::SonarProtocolDataWriter_var;
using org::omg::dds::SonarSimu::SonarProtocolDataReader;
using org::omg::dds::SonarSimu::SonarProtocolDataReader_var;
Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);
}

Configuration::~Configuration()
{
    delete ui;
}
