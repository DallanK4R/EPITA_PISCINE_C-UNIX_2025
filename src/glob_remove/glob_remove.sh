if [ $# -eq 0 ]; then
	if [ ! -f "*.txt" ]; then
		rm *.txt
	else 
		exit 1
	fi
else
	if [ ! -f "*.$1" ]; then
		rm *."$1"
	else
		exit 1
	fi
fi
