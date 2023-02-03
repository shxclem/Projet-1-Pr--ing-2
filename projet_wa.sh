#!bin/bash 
 
exist_csv=false				
exist_place=false
exist_sort=false
exist_para=false
temp=0

for arg in "$@"
do
	if [[ "$arg" == *.csv  ]] && [ "$exist_csv" = false ]; then	   #The argument is a .csv et no other .csv has been written
		exist_csv=true
		csv_file="$arg"
		
	elif [[ "$arg" == *.csv  ]] && [ "$exist_csv" = true ]; then       #The argument is a .csv and another .csv has been written
		echo "Too much .csv files among arguments"
		exit 2	
		
	elif [[ ( "$arg" == "-F"  || "$arg" == "-G" || "$arg" == "-S" || "$arg" == "-A" || "$arg" == "-O" || "$arg" == "-Q" ) && "$exist_place" = true ]] ; then   #The argument corresponds to a place and a place has already been written
		echo "Too much places among arguments"
		exit 2	

	elif [[ ( "$arg" == "-F"  || "$arg" == "-G" || "$arg" == "-S" ) && "$exist_place" = false ]]; then   #The argument corresponds to a place and no place has been written
		exist_place=true
		place="$arg"
		var[temp]="$arg"
		temp=$temp+1
		echo "test"
		
	elif [[ ( "$arg" == "-A"  || "$arg" == "-O" || "$arg" == "-Q" ) && "$exist_place" = false ]]; then
		exist_place=true
		place="$arg"
		var[temp]="$arg"
		temp=$temp+1
		echo "test"
		
	elif [[ ( "$arg" == "--tab" || "$arg" == "--abr" || "$arg" == "--avl" ) && "$exist_sort" = true ]]; then   #The argument corresponds to a type of sorting and a type of sorting has already been written
		echo "Too much types of sorting among arguments"
		exit 2

	elif [[ ( "$arg" == "--tab" || "$arg" == "--abr" || "$arg" == "--avl" ) && "$exist_sort" = false ]]; then #The argument corresponds to a type of sorting and no type of sorting has already been written
		exist_sort=true
		sort="$arg"

	elif [[ ( "$arg" == "-p1"  || "$arg" == "-p2" || "$arg" == "-p3" || "$arg" == "-t1" || "$arg" == "-t2" || "$arg" == "-t3" || "$arg" == "-w" || "$arg" == "-h" || "$arg" == "-m" ) ]]; then  #The argument is a decent parameter, we collect it	
		exist_para=true
		var[temp]="$arg"
		temp=$temp+1
	else 
		echo "Parameters are wrong or missing"
		exit 1
	fi
done

if [[ ( "$exist_csv" = true ) && ( "$exist_para" = true ) ]]; then		#Verifying that the program is based on a ressource file and atleast one paramater then displaying them
	echo "$csv_file"
	echo "$sort"
	for (( i=0 ; i<$temp ; i++))
	do
		echo "${var[i]}"
	done
else
	echo "No .csv or no parameters has been written among arguments"
	exit 1
fi 

if [ -z "$place" ]; then 
	place=default
fi

case $place in					#Defining which IDs are we going to be interested about depending on which place has been given
"-F")
cond='!~ /61980|67005|81408|81415|81401|81405|71805|78890|78897|78922|78925|78894|61972|61976|61998/'
;;
"-O")
cond="~ /61980|67005/"
;;
"-G")
cond="~ /81408|81415|81401|81405/"
;;
"-S")
cond="~ /71805/"
;;
"-A")
cond="~ /78890|78897|78922|78925|78894/"
;;
"-Q")
cond="~ /61972|61976|61998/"
;;
"default")
cond="~ /[0-9]+/"
;;
esac

if [ -z "$sort" ]; then 									#If no type of sorting has been given, default one is used
	sort=--avl
fi

gcc -o main *.c -I ./

for (( j=0 ; j<$i ; j++))									#Deciding what to do depending on the parameters that have been given
do
	if [[ "${var[j]}" = "-t1" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$12 }' $csv_file > fileT1m.csv
		echo "fileT1m.csv generated"
		./main fileT1m.csv exitT1m.csv "$sort" -id
		
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$13 }' $csv_file > fileT1M.csv
		echo "fileT1M.csv generated"
		./main fileT1M.csv exitT1M.csv "$sort" -id
		
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$11 }' $csv_file > fileT1.csv
		echo "fileT1.csv generated"
		./main fileT1.csv exitT1.csv "$sort" -id
	fi
	
	if [[ "${var[j]}" = "-t2" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$11 }' $csv_file > fileT2.csv
		echo "fileT2.csv generated"
		./main fileT2.csv exitT2.csv "$sort" -date	
		
	fi	
	
	if [[ "${var[j]}" = "-t3" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$11 }' $csv_file > fileT3.csv
		echo "fileT3.csv generated"
		./main fileT3.csv exitT3a.csv "$sort" -date
		./main fileT3.csv exitT3b.csv "$sort" -id
		
	fi
	
	if [[ "${var[j]}" = "-p1" ]]; then
		echo "This argument is not available in this version"
	fi
	
	if [[ "${var[j]}" = "-p2" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$7 }' $csv_file > fileP2.csv
		echo "fileP2.csv generated"
		./main fileP2.csv exitP2.csv "$sort" -date
		
	fi
	
	if [[ "${var[j]}" = "-p3" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$7 }' $csv_file > fileP3.csv
		echo "fileP3.csv generated"
		./main fileP3.csv exitP3a.csv "$sort" -date
		./main fileP3.csv exitP3b.csv "$sort" -id
	fi
	
	if [[ "${var[j]}" = "-w" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$4 }' $csv_file > fileWD.csv
		echo "fileWD.csv generated"
		./main fileWD.csv exitWD.csv "$sort" -id 
			
	
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$5 }' $csv_file > fileWS.csv
		echo "fileWS.csv generated"
		./main fileWS.csv exitWS.csv "$sort" -id
		 
		echo "Files created but plotting not available in this version"
	fi

	if [[ "${var[j]}" = "-h" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$14 }' $csv_file > fileH.csv	
		echo "fileH.csv generated"
		./main fileH.csv exitH.csv "$sort" -id -r 
		echo "File created but plotting not available in this version"	
	fi

	if [[ "${var[j]}" = "-m" ]]; then
		awk -F ","  'BEGIN {OFS=","} { if ($1 '"$cond"') print $1,$2,$6 }' $csv_file > fileM.csv
		echo "fileM.csv generated"
		./main fileM.csv exitM.csv "$sort" -id -r 
		echo "File created but plotting not available in this version"	
	fi
done
