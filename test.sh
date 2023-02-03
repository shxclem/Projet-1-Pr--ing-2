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
