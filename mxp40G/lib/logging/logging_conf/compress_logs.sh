LOG_DIR=/var/log/mxp/

echo "Checking for logs to compress ... "
   
    while [ `ls -1 $LOG_DIR | grep mxp_ | grep -v .gz | wc -l` -gt 1 ]; do #como condición establezco que haya mínimo 2 archivos de logeo en el directorio para iniciar la compresión y así evitar problemas con los archivos que esta escribiendo el syslog actualmente
      
      TO_COMPRESS=`ls -t $LOG_DIR | grep mxp_ | grep -v .gz | tail -1`

      if [ "$TO_COMPRESS" != "" ]; then
          #statements        
          xz -f "$LOG_DIR/$TO_COMPRESS"
          echo "Compressed: $TO_COMPRESS to save space"
          logger -i $TO_COMPRESS compressed to save space -t compress_logs      
      else 
          break
      fi

    done

echo "Nothing more to compress"    