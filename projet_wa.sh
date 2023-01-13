#!bin/bash 

#On vérifie qu'exactement un fichier .csv ait été inscrit en argument pour pouvoir continuer
exist_csv=false

for arg in "$@"
do
	if [[ "$arg" == *.csv  ]] && [ "$exist_csv" = false ]; then	
		exist_csv=true
		csv_file="$arg"
	elif [ "$exist_csv" = true ]; then
		echo "Trop de fichiers format csv en arguments"
		exit 2			        #Au moins deux fichiers csv ont été saisis en arguments
	fi
done

if [ "$exist_csv" = true ]; then
	echo "$csv_file"
else 
	echo "Aucun fichier format csv n'a été passé en entrée"
	exit 1
fi


