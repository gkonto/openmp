BLACKLIST=(
		"builds/c4_1"
		"builds/c4_1_0"
		"builds/c4_1_0_simd"
		"builds/c4_1_O2"

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
