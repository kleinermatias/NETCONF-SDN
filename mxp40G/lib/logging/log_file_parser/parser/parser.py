from datetime import * 
FMT = '%H:%M:%S'
import os
import matplotlib
matplotlib.use('Qt4Agg')
import matplotlib.pyplot as plt

monitor_interval=3

path = '/home/maguerreberry/Desktop/old_log_files/mxp2'
#path = "/home/maguerreberry/entrenamiento_Matt/c_proyects/nios2/RemoteSystemsTempFiles/172.16.0.42/var/log/mxp/"
os.chdir(path)

index_table_file = open('/home/maguerreberry/Desktop/old_log_files/titles_index_table','r')
index_table = index_table_file.read()
index_table = index_table.split('\n\n')
del index_table [0]
del index_table [1]
alarms_table = index_table[0].split('\n') 
num_var_table = index_table[1].split('\n')

for kk in range(len(alarms_table)):
	alarms_table[kk] = alarms_table[kk].split('_')
	del alarms_table[kk][0]
	alarms_table[kk]=alarms_table[kk][0]

for kk in range(len(num_var_table)):
	num_var_table[kk] = num_var_table[kk].split('_')
	del num_var_table[kk][0]
	num_var_table[kk]=num_var_table[kk][0]

for f in os.listdir(path):
	
	general_struct_num_var=[]
	general_struct_alarms=[]
	
	for kk in range(len(alarms_table)):
		general_struct_alarms.append([[],[],[]])
		general_struct_alarms[kk][0].append(alarms_table[kk])

	for kk in range(len(num_var_table)):
		general_struct_num_var.append([[],[],[]])
		general_struct_num_var[kk][0].append(num_var_table[kk])
		
	file_name, file_ext = os.path.splitext(f)
	
	mxp, year_f, month_f, day_f = file_name.split('_')
	print(mxp,year_f,month_f,day_f)

	ff = open(f,'r')	
	
	while (1):
		ff_content = ff.readline()
		if(ff_content == ''):
			ff.close()
			break
		
		first_split = ff_content.split(' ',2)
	
		#time
		msg_time = first_split[0]
		
		#app name
		if (first_split[1].find('[') == -1):
			app_info = first_split[1].split(':')
			#app_info[1] = aux_app_info[0]
		else:	
			app_info = first_split[1].split('[')
			aux_app_info = app_info[1].split(']')
			app_info[1] = aux_app_info[0]
		
		if app_info[0] == 'monitor':
		
			#type of message
			msg_raw_content = first_split[2].split(']',1)
			if msg_raw_content[0] == "[H":
				msg_raw_content[0] = "Hardware"
			elif msg_raw_content[0] == "[U":
				msg_raw_content[0] = "User"
				aux_msg_raw_content = msg_raw_content[1].split(';',1)
				msg_type = aux_msg_raw_content[0]
				msg_main_content = aux_msg_raw_content[1].split(';')
				del msg_main_content[len(msg_main_content)-1]
				if(msg_type == 'NumVal' or msg_type == 'InitialValues'):
					for jj in range(len(msg_main_content)):
						aux_msg_main_content = msg_main_content[jj].split('/')
#							aux_msg_main_content[1] = '0'
						
						if(aux_msg_main_content[0] == '19' or aux_msg_main_content[0] == '20' or aux_msg_main_content[0] == '21'):
							print msg_time,aux_msg_main_content
						if (aux_msg_main_content[0] == '27' or aux_msg_main_content[0] == '26'):
							aux_msg_main_content[1] = aux_msg_main_content[1].split(' ')
							general_struct_num_var[int(aux_msg_main_content[0])][1].append(msg_time)
							general_struct_num_var[int(aux_msg_main_content[0])][2].append(float(aux_msg_main_content[1][1]))	
						
						elif (aux_msg_main_content[0] == '30' or aux_msg_main_content[0] == '28'):
							general_struct_num_var[int(aux_msg_main_content[0])][1].append(msg_time)
							if (aux_msg_main_content[1] == 'C'):
								general_struct_num_var[int(aux_msg_main_content[0])][2].append(999)	
						
#						else:
#							general_struct_num_var[int(aux_msg_main_content[0])][1].append(msg_time)
#							general_struct_num_var[int(aux_msg_main_content[0])][2].append(float(aux_msg_main_content[1]))

#	for ii in range(len(general_struct_num_var)):#

#		y_title = general_struct_num_var[ii][0]		
#		x_time = [] #time
#		y_values = [] #value
#		
#		#if (y_title[0].find("Temp.") != -1):
#		if(1):
#			for jj in range(len(general_struct_num_var[ii][2])-1):
#				
#				tdelta = datetime.strptime(general_struct_num_var[ii][1][jj+1], FMT) - datetime.strptime(general_struct_num_var[ii][1][jj], FMT)
#				vrepeats = tdelta.seconds/monitor_interval#

#				x_time.append(datetime.strptime(general_struct_num_var[ii][1][jj],FMT))
#				for uu in range(vrepeats):
#					y_values.append(general_struct_num_var[ii][2][jj])
#				
#				for uu in range(vrepeats-1):					
#					dtime = timedelta(seconds=monitor_interval)
#					aux_time = x_time[-1]+dtime
#					x_time.append(aux_time)#

##				if (datetime.strptime(general_struct_num_var[ii][1][jj], FMT) > datetime.strptime('16:00:00', FMT)):
##					break
#			
#			y_values.append(general_struct_num_var[ii][2][len(general_struct_num_var[ii][2])-1])				
#			x_time.append(datetime.strptime(general_struct_num_var[ii][1][len(general_struct_num_var[ii][1])-1],FMT))
#			
#			for gg in range(len(x_time)):
#				if (x_time[gg].hour < 10):
#					temp_hour = '0'+str(x_time[gg].hour)
#				else:
#					temp_hour = str(x_time[gg].hour)
#				if (x_time[gg].minute < 10):
#					temp_minute = '0'+str(x_time[gg].minute)
#				else:
#					temp_minute = str(x_time[gg].minute)
#				if (x_time[gg].second < 10):
#					temp_second = '0'+str(x_time[gg].second)
#				else:
#					temp_second = str(x_time[gg].second)#

#				x_time[gg]=temp_hour+":"+temp_minute+":"+temp_second
#			
#			plt.figure(ii,figsize=(16, 9))
#			if (y_title[0].find("Temp.") != -1):
#				plt.ylim(0,60)
#			elif(y_title[0].find("dBm") != -1):
#				plt.ylim(-30,10)	
#			
#			if (len(y_values)<10):
#				interval = len(y_values)
#			else:
#				interval=len(y_values)/10
			
			#manager = plt.get_current_fig_manager()
			#manager.window.showMaximized()
#			plt.plot(y_values,'r.-')
#			plt.xticks(range(0,len(y_values),interval), x_time[0:len(x_time):interval], rotation='45')
#			plt.grid()
#			plt.title(y_title[0]+" Date:"+year_f+"/"+month_f+"/"+day_f)
			#print y_title[0]
			#plt.savefig('/home/maguerreberry/Desktop/old_log_files/graph_test/%s_%s%s%s.png'%(y_title[0].replace(" ","").replace("/","-"),year_f,month_f,day_f),format='png',dpi=200)
#plt.show()