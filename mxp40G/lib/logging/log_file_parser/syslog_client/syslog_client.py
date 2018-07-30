import syslog
import sys

LOG_ERR = syslog.LOG_ERR

LOG_PID = syslog.LOG_PID 
LOG_CONS = syslog.LOG_CONS

LOG_USER = syslog.LOG_USER

def log_msg (msg):
	temp_ident = sys.argv[0].split('.')
	syslog.openlog(temp_ident[0],LOG_PID|LOG_CONS, LOG_USER)
	syslog.syslog(LOG_ERR,msg)
	syslog.closelog()