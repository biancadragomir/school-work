for i in *; do
	if test $i != newf; then
		cp -r $i newf
	fi
done
