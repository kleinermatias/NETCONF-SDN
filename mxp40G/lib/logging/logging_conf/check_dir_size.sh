LOG_DIR=/var/log/mxp/
MAX_DIR_SIZE=1000  #el  tmño esta en kilobyte
echo "Checking /mnt/mxp/ size ... "
    while [ `du $LOG_DIR | awk '{print $1}'` -gt "$MAX_DIR_SIZE" ]; do
        # yes, too little, find oldest named directory to delete
        if [[ `ls -1 $LOG_DIR | wc -l` -lt 2 ]]; then #corta la eliminación de archivos cuando queda solo 1 archivos, para no eliminar donde esta escribiendo el syslog 
            break
        fi       
        
        TO_DELETE=`ls -t $LOG_DIR | tail -1` 
        
        if [ "$TO_DELETE" != "" ]; then
          # don't ever delete a blank 
          # (would delete *everything*)
          rm  "$LOG_DIR/$TO_DELETE"
          echo "Deleted: $TO_DELETE to save space"
          logger -i $TO_DELETE deleted to save space -t check_dir_size      
        fi
    done
echo "Nothing more to delete"    