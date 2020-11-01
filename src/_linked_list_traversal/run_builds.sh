BLACKLIST=(
		)

for entry in "builds"/*
do
	if [[ ! " ${BLACKLIST[@]} " =~ " ${entry} " ]]; then
		echo ${entry}
		./${entry} $1
		echo
	else 
		echo ${entry}
		echo "BLACKLISTED. Takes too long..."
		echo
	fi
done
