for arg; do
	args=$args$arg
done
mv *.[!$args] trash/
