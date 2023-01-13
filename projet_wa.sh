#!bin/bash 

#On vérifie qu'exactement un fichier .csv ait été inscrit en argument pour pouvoir continuer
exist_csv=false
temp=0

for arg in "$@"
do
	if [[ "$arg" == *.csv  ]] && [ "$exist_csv" = false ]; then	   #L'argument est un csv et aucun csv n'a déjà été traité
		exist_csv=true
		csv_file="$arg"
	elif [[ "$arg" == *.csv  ]] && [ "$exist_csv" = true ]; then       #L'argument est un csv et un csv a déjà été traité
		echo "Trop de fichiers format csv en arguments"
		exit 2				
	else 			      					   #L'argument n'est pas un csv, on le récupère
		var[temp]="$arg"
		temp=$temp+1
	fi
done

if [ "$exist_csv" = true ]; then
	echo "$csv_file"
	for (( i=0 ; i<$temp ; i++))
	do
		echo "${var[i]}"
	done
else
	echo "Aucun fichier format csv n'a été passé en entrée"
	exit 1
fi


