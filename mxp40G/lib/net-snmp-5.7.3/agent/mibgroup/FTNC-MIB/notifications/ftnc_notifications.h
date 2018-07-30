#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../../lib/hl_configs/definitions.h"

static unsigned int period = 2;

void init_ftnc_notifications(void);

/* ***************** EDFA prototypes ***************** */

SNMPAlarmCallback send_edfaAmpStatusAlarm_notification;
static char edfaAmpStatusTemp[100] = "OK";

SNMPAlarmCallback send_edfaInputPowerAlarm_notification;
static unsigned int edfaInputPowerTemp = 0;

SNMPAlarmCallback send_edfaLopAlarm_notification;
static char edfaLopTemp[100] = "OFF";

SNMPAlarmCallback send_edfaOutputPowerAlarm_notification;
static unsigned int edfaOutputPowerTemp = 0;

SNMPAlarmCallback send_edfaLosAlarm_notification;
static char edfaLosTemp[100] = "OFF";

SNMPAlarmCallback send_edfaTemperatureAlarm_notification;
static unsigned int edfaTemperatureTemp = 0;

/* ***************** XFP1 prototypes ***************** */
SNMPAlarmCallback send_xfp1Presence_notification;
static unsigned int xfp1PresenceTemp = 0;

SNMPAlarmCallback send_xfp1RxLoss_notification;
static unsigned int xfp1RxLossTemp = 0;

SNMPAlarmCallback send_xfp1Ready_notification;
static unsigned int xfp1ReadyTemp = 0;

SNMPAlarmCallback send_xfp1TxPower_notification;
static unsigned int xfp1TxPowerTemp = 0;

SNMPAlarmCallback send_xfp1RxPower_notification;
static unsigned int xfp1RxPowerTemp = 0;

SNMPAlarmCallback send_xfp1Temperature_notification;
static unsigned int xfp1TemperatureTemp = 0;

SNMPAlarmCallback send_xfp1LowTxPower_notification;
static unsigned int xfp1LowTxPowerTemp = 0;

SNMPAlarmCallback send_xfp1HighTxPower_notification;
static unsigned int xfp1HighTxPowerTemp = 0;

SNMPAlarmCallback send_xfp1LowRxPower_notification;
static unsigned int xfp1LowRxPowerTemp = 0;

SNMPAlarmCallback send_xfp1HighRxPower_notification;
static unsigned int xfp1HighRxPowerTemp = 0;

SNMPAlarmCallback send_xfp1RxCdrLOL_notification;
static unsigned int xfp1RxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp1TxCdrLOL_notification;
static unsigned int xfp1TxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp1LaserFault_notification;
static unsigned int xfp1LaserFaultTemp = 0;

/* ***************** XFP2 prototypes ***************** */
SNMPAlarmCallback send_xfp2Presence_notification;
static unsigned int xfp2PresenceTemp = 0;

SNMPAlarmCallback send_xfp2RxLoss_notification;
static unsigned int xfp2RxLossTemp = 0;

SNMPAlarmCallback send_xfp2Ready_notification;
static unsigned int xfp2ReadyTemp = 0;

SNMPAlarmCallback send_xfp2TxPower_notification;
static unsigned int xfp2TxPowerTemp = 0;

SNMPAlarmCallback send_xfp2RxPower_notification;
static unsigned int xfp2RxPowerTemp = 0;

SNMPAlarmCallback send_xfp2Temperature_notification;
static unsigned int xfp2TemperatureTemp = 0;

SNMPAlarmCallback send_xfp2LowTxPower_notification;
static unsigned int xfp2LowTxPowerTemp = 0;

SNMPAlarmCallback send_xfp2HighTxPower_notification;
static unsigned int xfp2HighTxPowerTemp = 0;

SNMPAlarmCallback send_xfp2LowRxPower_notification;
static unsigned int xfp2LowRxPowerTemp = 0;

SNMPAlarmCallback send_xfp2HighRxPower_notification;
static unsigned int xfp2HighRxPowerTemp = 0;

SNMPAlarmCallback send_xfp2RxCdrLOL_notification;
static unsigned int xfp2RxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp2TxCdrLOL_notification;
static unsigned int xfp2TxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp2LaserFault_notification;
static unsigned int xfp2LaserFaultTemp = 0;

/* ***************** XFP3 prototypes ***************** */
SNMPAlarmCallback send_xfp3Presence_notification;
static unsigned int xfp3PresenceTemp = 0;

SNMPAlarmCallback send_xfp3RxLoss_notification;
static unsigned int xfp3RxLossTemp = 0;

SNMPAlarmCallback send_xfp3Ready_notification;
static unsigned int xfp3ReadyTemp = 0;

SNMPAlarmCallback send_xfp3TxPower_notification;
static unsigned int xfp3TxPowerTemp = 0;

SNMPAlarmCallback send_xfp3RxPower_notification;
static unsigned int xfp3RxPowerTemp = 0;

SNMPAlarmCallback send_xfp3Temperature_notification;
static unsigned int xfp3TemperatureTemp = 0;

SNMPAlarmCallback send_xfp3LowTxPower_notification;
static unsigned int xfp3LowTxPowerTemp = 0;

SNMPAlarmCallback send_xfp3HighTxPower_notification;
static unsigned int xfp3HighTxPowerTemp = 0;

SNMPAlarmCallback send_xfp3LowRxPower_notification;
static unsigned int xfp3LowRxPowerTemp = 0;

SNMPAlarmCallback send_xfp3HighRxPower_notification;
static unsigned int xfp3HighRxPowerTemp = 0;

SNMPAlarmCallback send_xfp3RxCdrLOL_notification;
static unsigned int xfp3RxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp3TxCdrLOL_notification;
static unsigned int xfp3TxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp3LaserFault_notification;
static unsigned int xfp3LaserFaultTemp = 0;

/* ***************** XFP4 prototypes ***************** */
SNMPAlarmCallback send_xfp4Presence_notification;
static unsigned int xfp4PresenceTemp = 0;

SNMPAlarmCallback send_xfp4RxLoss_notification;
static unsigned int xfp4RxLossTemp = 0;

SNMPAlarmCallback send_xfp4Ready_notification;
static unsigned int xfp4ReadyTemp = 0;

SNMPAlarmCallback send_xfp4TxPower_notification;
static unsigned int xfp4TxPowerTemp = 0;

SNMPAlarmCallback send_xfp4RxPower_notification;
static unsigned int xfp4RxPowerTemp = 0;

SNMPAlarmCallback send_xfp4Temperature_notification;
static unsigned int xfp4TemperatureTemp = 0;

SNMPAlarmCallback send_xfp4LowTxPower_notification;
static unsigned int xfp4LowTxPowerTemp = 0;

SNMPAlarmCallback send_xfp4HighTxPower_notification;
static unsigned int xfp4HighTxPowerTemp = 0;

SNMPAlarmCallback send_xfp4LowRxPower_notification;
static unsigned int xfp4LowRxPowerTemp = 0;

SNMPAlarmCallback send_xfp4HighRxPower_notification;
static unsigned int xfp4HighRxPowerTemp = 0;

SNMPAlarmCallback send_xfp4RxCdrLOL_notification;
static unsigned int xfp4RxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp4TxCdrLOL_notification;
static unsigned int xfp4TxCdrLOLTemp = 0;

SNMPAlarmCallback send_xfp4LaserFault_notification;
static unsigned int xfp4LaserFaultTemp = 0;

/* ***************** TXP prototypes ***************** */

SNMPAlarmCallback send_txpEolAlarm_notification;
static unsigned char txpEolTemp[100] = "--";

SNMPAlarmCallback send_txpModTempAlarm_notification;
static unsigned char txpModTempTemp[100] = "--";

SNMPAlarmCallback send_txpTxooaAlarm_notification;
static unsigned char txpTxooaTemp[100] = "--";

SNMPAlarmCallback send_txpTxLofAlarm_notification;
static unsigned char txpTxLofTemp[100] = "--";

SNMPAlarmCallback send_txpTxDscAlarm_notification;
static unsigned char txpTxDscTemp[100] = "--";

SNMPAlarmCallback send_txpLsWavAlarm_notification;
static unsigned char txpLsWavTemp[100] = "--";

SNMPAlarmCallback send_txpLsBiasAlarm_notification;
static unsigned char txpLsBiasTemp[100] = "--";

SNMPAlarmCallback send_txpLsTempAlarm_notification;
static unsigned char txpLsTempTemp[100] = "--";

SNMPAlarmCallback send_txpTxLockAlarm_notification;
static unsigned char txpTxLockTemp[100] = "--";

SNMPAlarmCallback send_txpLsPowAlarm_notification;
static unsigned char txpLsPowTemp[100] = "--";

SNMPAlarmCallback send_txpModBiasAlarm_notification;
static unsigned char txpModBiasTemp[100] = "--";

SNMPAlarmCallback send_txpLatchedTxFifoAlarm_notification;
static unsigned char txpLatchedTxFifoTemp[100] = "--";

SNMPAlarmCallback send_txpRxPowAlarm_notification;
static unsigned char txpRxPowTemp[100] = "--";

SNMPAlarmCallback send_txpRxLosAlarm_notification;
static unsigned char txpRxLosTemp[100] = "--";

SNMPAlarmCallback send_txpRxLockAlarm_notification;
static unsigned char txpRxLockTemp[100] = "--";

SNMPAlarmCallback send_txpRxsAlarm_notification;
static unsigned char txpRxsTemp[100] = "--";

SNMPAlarmCallback send_txpPrbsErrAlarm_notification;
static unsigned char txpPrbsErrTemp[100] = "--";

SNMPAlarmCallback send_txpPsummaryAlarm_notification;
static unsigned char txpPsummaryTemp[100] = "--";

SNMPAlarmCallback send_txpP5vAnalogAlarm_notification;
static unsigned char txpP5vAnalogTemp[100] = "--";

SNMPAlarmCallback send_txpN5v2AnalogAlarm_notification;
static unsigned char txpN5v2AnalogTemp[100] = "--";

SNMPAlarmCallback send_txpP3p3vAnalogAlarm_notification;
static unsigned char txpP3p3vAnalogTemp[100] = "--";

SNMPAlarmCallback send_txpP3p3vDigitalAlarm_notification;
static unsigned char txpP3p3vDigitalTemp[100] = "--";

SNMPAlarmCallback send_txpLvDigitalAlarm_notification;
static unsigned char txpLvDigitalTemp[100] = "--";

SNMPAlarmCallback send_txpN5p2vDigitalAlarm_notification;
static unsigned char txpN5p2vDigitalTemp[100] = "--";

/* ***************** TP prototypes line ***************** */
SNMPAlarmCallback send_tp_lineFramerFssmmtrb3s_notification;
static unsigned int lineFramerFssmmtrb3sTemp = 0;

SNMPAlarmCallback send_tp_lineFramerFssmmtrb2s_notification;
static unsigned int lineFramerFssmmtrb2sTemp = 0;

SNMPAlarmCallback send_tp_lineFramerFssmmtrb1s_notification;
static unsigned int lineFramerFssmmtrb1sTemp = 0;

SNMPAlarmCallback send_tp_lineFramerFsmms_notification;
static unsigned int lineFramerFsmmsTemp = 0;

SNMPAlarmCallback send_tp_lineFramerSif_notification;
static unsigned int lineFramerSifTemp = 0;

SNMPAlarmCallback send_tp_lineFramerSoof_notification;
static unsigned int lineFramerSoofTemp = 0;

SNMPAlarmCallback send_tp_lineFramerSlof_notification;
static unsigned int lineFramerSlofTemp = 0;

SNMPAlarmCallback send_tp_lineFramerFst_notification;
static unsigned int lineFramerFstTemp = 0;

SNMPAlarmCallback send_tp_lineLosstatLosf_notification;
static unsigned int lineLosstatLosfTemp = 0;

SNMPAlarmCallback send_tp_lineSecmonFlom_notification;
static unsigned int lineSecmonFlomTemp = 0;

SNMPAlarmCallback send_tp_lineSecmonDiae_notification;
static unsigned int lineSecmonDiaeTemp = 0;

SNMPAlarmCallback send_tp_lineSecmonDbdi_notification;
static unsigned int lineSecmonDbdiTemp = 0;

SNMPAlarmCallback send_tp_lineSecmonBipsfs_notification;
static unsigned int lineSecmonBipsfsTemp = 0;

SNMPAlarmCallback send_tp_lineSecmonLom_notification;
static unsigned int lineSecmonLomTemp = 0;

SNMPAlarmCallback send_tp_linePathmonAccstat_notification;
static unsigned int linePathmonAccstatTemp = 0;

SNMPAlarmCallback send_tp_linePathmonMsiunst_notification;
static unsigned int linePathmonMsiunstTemp = 0;

SNMPAlarmCallback send_tp_linePathmonDais_notification;
static unsigned int linePathmonDaisTemp = 0;

SNMPAlarmCallback send_tp_linePathmonDlck_notification;
static unsigned int linePathmonDlckTemp = 0;

SNMPAlarmCallback send_tp_linePathmonDbdi_notification;
static unsigned int linePathmonDbdiTemp = 0;

/* ***************** TP prototypes Client 1 ***************** */
SNMPAlarmCallback send_tp_client1FramerFsmms_notification;
static unsigned int client1FramerFsmmsTemp = 0;

SNMPAlarmCallback send_tp_client1FramerFssusts_notification;
static unsigned int client1FramerFssustsTemp = 0;

SNMPAlarmCallback send_tp_client1FramerSif_notification;
static unsigned int client1FramerSifTemp = 0;

SNMPAlarmCallback send_tp_client1FramerSoof_notification;
static unsigned int client1FramerSoofTemp = 0;

SNMPAlarmCallback send_tp_client1FramerSlof_notification;
static unsigned int client1FramerSlofTemp = 0;

SNMPAlarmCallback send_tp_client1FramerFst_notification;
static unsigned int client1FramerFstTemp = 0;

SNMPAlarmCallback send_tp_client1LosstatLosf_notification;
static unsigned int client1LosstatLosfTemp = 0;

SNMPAlarmCallback send_tp_client1SecmonFlom_notification;
static unsigned int client1SecmonFlomTemp = 0;

SNMPAlarmCallback send_tp_client1SecmonBipsfs_notification;
static unsigned int client1SecmonBipsfsTemp = 0;

SNMPAlarmCallback send_tp_client1SecmonDiae_notification;
static unsigned int client1SecmonDiaeTemp = 0;

SNMPAlarmCallback send_tp_client1SecmonDbdi_notification;
static unsigned int client1SecmonDbdiTemp = 0;

SNMPAlarmCallback send_tp_client1SecmonLom_notification;
static unsigned int client1SecmonLomTemp = 0;

SNMPAlarmCallback send_tp_client1PathmonAccstat_notification;
static unsigned int client1PathmonAccstatTemp = 0;

SNMPAlarmCallback send_tp_client1PathmonMsiunst_notification;
static unsigned int client1PathmonMsiunstTemp = 0;

SNMPAlarmCallback send_tp_client1PathmonDais_notification;
static unsigned int client1PathmonDaisTemp = 0;

SNMPAlarmCallback send_tp_client1PathmonDlck_notification;
static unsigned int client1PathmonDlckTemp = 0;

SNMPAlarmCallback send_tp_client1PathmonDbdi_notification;
static unsigned int client1PathmonDbdiTemp = 0;

/* ***************** TP prototypes Client 2 ***************** */
SNMPAlarmCallback send_tp_client2FramerFsmms_notification;
static unsigned int client2FramerFsmmsTemp = 0;

SNMPAlarmCallback send_tp_client2FramerFssusts_notification;
static unsigned int client2FramerFssustsTemp = 0;

SNMPAlarmCallback send_tp_client2FramerSif_notification;
static unsigned int client2FramerSifTemp = 0;

SNMPAlarmCallback send_tp_client2FramerSoof_notification;
static unsigned int client2FramerSoofTemp = 0;

SNMPAlarmCallback send_tp_client2FramerSlof_notification;
static unsigned int client2FramerSlofTemp = 0;

SNMPAlarmCallback send_tp_client2FramerFst_notification;
static unsigned int client2FramerFstTemp = 0;

SNMPAlarmCallback send_tp_client2LosstatLosf_notification;
static unsigned int client2LosstatLosfTemp = 0;

SNMPAlarmCallback send_tp_client2SecmonFlom_notification;
static unsigned int client2SecmonFlomTemp = 0;

SNMPAlarmCallback send_tp_client2SecmonBipsfs_notification;
static unsigned int client2SecmonBipsfsTemp = 0;

SNMPAlarmCallback send_tp_client2SecmonDiae_notification;
static unsigned int client2SecmonDiaeTemp = 0;

SNMPAlarmCallback send_tp_client2SecmonDbdi_notification;
static unsigned int client2SecmonDbdiTemp = 0;

SNMPAlarmCallback send_tp_client2SecmonLom_notification;
static unsigned int client2SecmonLomTemp = 0;

SNMPAlarmCallback send_tp_client2PathmonAccstat_notification;
static unsigned int client2PathmonAccstatTemp = 0;

SNMPAlarmCallback send_tp_client2PathmonMsiunst_notification;
static unsigned int client2PathmonMsiunstTemp = 0;

SNMPAlarmCallback send_tp_client2PathmonDais_notification;
static unsigned int client2PathmonDaisTemp = 0;

SNMPAlarmCallback send_tp_client2PathmonDlck_notification;
static unsigned int client2PathmonDlckTemp = 0;

SNMPAlarmCallback send_tp_client2PathmonDbdi_notification;
static unsigned int client2PathmonDbdiTemp = 0;

/* ***************** TP prototypes Client 3 ***************** */
SNMPAlarmCallback send_tp_client3FramerFsmms_notification;
static unsigned int client3FramerFsmmsTemp = 0;

SNMPAlarmCallback send_tp_client3FramerFssusts_notification;
static unsigned int client3FramerFssustsTemp = 0;

SNMPAlarmCallback send_tp_client3FramerSif_notification;
static unsigned int client3FramerSifTemp = 0;

SNMPAlarmCallback send_tp_client3FramerSoof_notification;
static unsigned int client3FramerSoofTemp = 0;

SNMPAlarmCallback send_tp_client3FramerSlof_notification;
static unsigned int client3FramerSlofTemp = 0;

SNMPAlarmCallback send_tp_client3FramerFst_notification;
static unsigned int client3FramerFstTemp = 0;

SNMPAlarmCallback send_tp_client3LosstatLosf_notification;
static unsigned int client3LosstatLosfTemp = 0;

SNMPAlarmCallback send_tp_client3SecmonFlom_notification;
static unsigned int client3SecmonFlomTemp = 0;

SNMPAlarmCallback send_tp_client3SecmonBipsfs_notification;
static unsigned int client3SecmonBipsfsTemp = 0;

SNMPAlarmCallback send_tp_client3SecmonDiae_notification;
static unsigned int client3SecmonDiaeTemp = 0;

SNMPAlarmCallback send_tp_client3SecmonDbdi_notification;
static unsigned int client3SecmonDbdiTemp = 0;

SNMPAlarmCallback send_tp_client3SecmonLom_notification;
static unsigned int client3SecmonLomTemp = 0;

SNMPAlarmCallback send_tp_client3PathmonAccstat_notification;
static unsigned int client3PathmonAccstatTemp = 0;

SNMPAlarmCallback send_tp_client3PathmonMsiunst_notification;
static unsigned int client3PathmonMsiunstTemp = 0;

SNMPAlarmCallback send_tp_client3PathmonDais_notification;
static unsigned int client3PathmonDaisTemp = 0;

SNMPAlarmCallback send_tp_client3PathmonDlck_notification;
static unsigned int client3PathmonDlckTemp = 0;

SNMPAlarmCallback send_tp_client3PathmonDbdi_notification;
static unsigned int client3PathmonDbdiTemp = 0;

/* ***************** TP prototypes Client 4 ***************** */
SNMPAlarmCallback send_tp_client4FramerFsmms_notification;
static unsigned int client4FramerFsmmsTemp = 0;

SNMPAlarmCallback send_tp_client4FramerFssusts_notification;
static unsigned int client4FramerFssustsTemp = 0;

SNMPAlarmCallback send_tp_client4FramerSif_notification;
static unsigned int client4FramerSifTemp = 0;

SNMPAlarmCallback send_tp_client4FramerSoof_notification;
static unsigned int client4FramerSoofTemp = 0;

SNMPAlarmCallback send_tp_client4FramerSlof_notification;
static unsigned int client4FramerSlofTemp = 0;

SNMPAlarmCallback send_tp_client4FramerFst_notification;
static unsigned int client4FramerFstTemp = 0;

SNMPAlarmCallback send_tp_client4LosstatLosf_notification;
static unsigned int client4LosstatLosfTemp = 0;

SNMPAlarmCallback send_tp_client4SecmonFlom_notification;
static unsigned int client4SecmonFlomTemp = 0;

SNMPAlarmCallback send_tp_client4SecmonBipsfs_notification;
static unsigned int client4SecmonBipsfsTemp = 0;

SNMPAlarmCallback send_tp_client4SecmonDiae_notification;
static unsigned int client4SecmonDiaeTemp = 0;

SNMPAlarmCallback send_tp_client4SecmonDbdi_notification;
static unsigned int client4SecmonDbdiTemp = 0;

SNMPAlarmCallback send_tp_client4SecmonLom_notification;
static unsigned int client4SecmonLomTemp = 0;

SNMPAlarmCallback send_tp_client4PathmonAccstat_notification;
static unsigned int client4PathmonAccstatTemp = 0;

SNMPAlarmCallback send_tp_client4PathmonMsiunst_notification;
static unsigned int client4PathmonMsiunstTemp = 0;

SNMPAlarmCallback send_tp_client4PathmonDais_notification;
static unsigned int client4PathmonDaisTemp = 0;

SNMPAlarmCallback send_tp_client4PathmonDlck_notification;
static unsigned int client4PathmonDlckTemp = 0;

SNMPAlarmCallback send_tp_client4PathmonDbdi_notification;
static unsigned int client4PathmonDbdiTemp = 0;

#ifdef __cplusplus
}
#endif

#endif /* NOTIFICATION_H */
