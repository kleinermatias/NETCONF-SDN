#ifndef _LOGMSG_H_
#define _LOGMSG_H_

/* TXP Tx */
#define EOLALM "%s TXP Tx Laser end of life alarm"
#define ModTEMPALM "%s TXP Tx Modulator Temperature Alarm"
#define TxOOA "%s TXP Tx SFI-5 DESKEW alarm"
#define TxLOFALM "%s TXP Tx Loss of Frame alarm"
#define TxDSCERR "%s TXP Tx Latching SFI-5 DESKEW Channel error"
#define LsWAVALM "%s TXP Tx Laser Wavelength alarm"
#define TxALM_INT "%s TXP Tx summary alarm"
#define LsBIASALM "%s TXP Tx Laser bias current alarm"
#define LsTEMPALM "%s TXP Tx Laser temperature alarm"
#define TxLOCKERR "%s TXP Tx Loss of TxPLL lock indicator"
#define LsPOWALM "%s TXP Tx Laser power alarm"
#define ModBIASALM "%s TXP Tx Modulator bias alarm"
#define TxFIFOERR "%s TXP Tx Historical Mux FIFO error indicator"

/* TXP Rx */
#define RxALM_INT "%s TXP Rx summary alarm"
#define RxPOWALM "%s TXP Rx Loss average optical power alarm"
#define RxLOS "%s TXP Rx Loss AC (modulated) power alarm"
#define RxLOCKERR "%s TXP Rx Loss of RxPLL lock indicator"
#define RXS "%s TXP Rx SFI-5 DEMUX status"
#define PRBSERRDET "TXP Rx an error was detected by the PRBS error checker"

/* TXP Power Supply */
#define PSUMMARY "%s TXP Power summary alarm"
#define P5VANALOG "%s  TXP +5V analog"
#define N5V2ANALOG "%s  TXP -5.2V analog"
#define P3P3VANALOG "%s TXP +3.3V analog"
#define P3P3VDIGITAL "%s TXP +3.3V digital"
#define LVDIGITAL "%s TXP +1.8V digital"
#define N5P2VDIGITAL "%s TXP –5.2V digital"

/* XFP */
#define XFP_RxLOS "(ID=%d) %s Rx LOS"
#define XFP_TxPWR "(ID=%d) %s Tx High Power: %d"
#define XFP_RxPWR "(ID=%d) %s Rx High Power: %d"

/* QSFP */
#define QSFP_RxLOS "%s QSFP Rx%d LOS"
#define QSFP_TxLOS "%s QSFP Tx%d LOS"
#define QSFP_TxFault "%s QSFP%d Tx Fault"
#define QSFP_TempHighAlm "%s QSFP High Temperature Alarm: %d"
#define QSFP_TempLowAlm "%s QSFP Low Temperature Alarm: %d"
#define QSFP_TempHighWng "%s QSFP High Temperature Warnning: %d"
#define QSFP_TempLowWng "%s QSFP Low Temperature Warnning: %d"
#define QSFP_Tx1BiasHighAlm "%s QSFP Tx1 High Bias"
#define QSFP_Tx2BiasHighAlm "%s QSFP Tx2 High Bias"
#define QSFP_Tx3BiasHighAlm "%s QSFP Tx3 High Bias"
#define QSFP_Tx4BiasHighAlm "%s QSFP Tx4 High Bias"
#define QSFP_Rx1PwrAlm "%s QSFP Rx1 High Power"
#define QSFP_Rx2PwrAlm "%s QSFP Rx1 High Power"
#define QSFP_Rx3PwrAlm "%s QSFP Rx1 High Power"
#define QSFP_Rx4PwrAlm "%s QSFP Rx1 High Power"

/* TMP */
#define TMP_OVERT "%s TMP Channel %d Overt High Temperature: %f"
#define TMP_ALERT "$s TMP Channel %d Alert High Temperature: %f"
#define TMP_DIODEFAULT "%s TMP Channel %d Diode Fault"
#define TMP_ALERTLOW "%s TMP Channel %d Low Temperature: %f"

/* HMD */
#define HMD_ALERT "%s HMD High Humidity: %d"

/* T41 OTN */
#define T41_OTU_GLOBAL_STATUS_LOSF "%s OTU Client Port %d Global LOS"
#define T41_OTU_OFSTAT_SLOF "%s OTU Client Port %d LOF"
#define T41_OTU_SM_STATUS_LOM "%s OTU Client Port %d LOM"
#define T41_OTU_SM_STATUS_DBDI "%s OTU Client Port %d BDI"
#define T41_OTU_SM_STATUS_DIAE "OTU Client Port %d IAE"
#define T41_SM_STATUS_BIPSDS "%s OTU Client Port %d BIP"
#define T41_OTU_SM_STATUS_BEISDS "%s OTU Client Port %d BEI"
#define T41_ODU_PM_STATUS_DAIS "%s OTU Client Port %d AIS"
#define T41_ODU_PM_STATUS_DBDI "%s OTU Client Port %d BDI"
#define T41_ODU_PM_STATUS_DOCI "%s OTU Client Port %d OCI"
#define T41_ODU_PM_STATUS_DLCK "%s OTU Client Port %d LKC"
#define T41_ODU_PM_STATUS_BIPSDS "%s OTU Client Port %d BIP"
#define T41_ODU_PM_STATUS_BEISDS "%s OTU Client Port %d BEI"

/* T41 ETHOTN */
#define T41_ETHOTN_PCS_RX_SYNCDETS "%s ETHOTN Rx%d LOS"
#define T41_ETHOTN_PCS_RX_BERHIGHS "%s ETHOTN Rx%d High BER"
#define T41_ETHOTN_PCS_RX_PATSYNCS "%s ETHOTN Rx%d Loss of Pattern Sync"
#define T41_ETHOTN_RS_RX_STATUS_RFS "%s ETHOTN RS Rx%d Remote Fault"
#define T41_ETHOTN_RS_RX_STATUS_LFS "%s ETHOTN RS Rx%d Local Fault"
#define T41_ETHOTN_RS_RX_STATUS_UNKNOWNORDS "%s ETHOTN Rx%d UNKNOWORDS"
#define T41_ETHOTN_RS_RX_STATUS_REMOTEORDS "%s ETHOTN Rx%d REMOTEORDS"
#define T41_ETHOTN_RS_RX_STATUS_LOCALORDS "%s ETHOTN Rx%d LOCALORDS"
#define T41_ETHOTN_XAUI_RX_LOCALFAULT "%s ETHOTN Rx%d XGXS Local Fault"
#define T41_ETHOTN_XAUI_RX_REMOTEFAULT "%s ETHOTN Rx%d XGXS Remote Fault"
#define T41_ETHOTN_XAUI_RX_XGXS_CPAT_LOCK "%s ETHOTN Rx%d XGXS CPAT LOCK"
#define T41_ETHOTN_XAUI_RX_XGXS_ALIGN_DET "%s ETHOTN Rx%d XGXS ALIGN DET"
#define T41_ETHOTN_XAUI_RX_SYNCDET3 "%s ETHOTN Rx%d SYNCDET3"
#define T41_ETHOTN_XAUI_RX_SYNCDET2 "%s ETHOTN Rx%d SYNCDET2"
#define T41_ETHOTN_XAUI_RX_SYNCDET1 "%s ETHOTN Rx%d SYNCDET1"
#define T41_ETHOTN_XAUI_RX_SYNCDET0 "%s ETHOTN Rx%d SYNCDET0"

#endif /* _LOGMSG_H_ */
