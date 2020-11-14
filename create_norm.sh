dir="./for-norme"
m="Makefile"

mkdir -p for-norme
cat ./sh/mf_p1 > $dir/$m
find . -name "*.c" -exec basename {} \; | awk 'NF{print $0 "\\"}' >> $dir/$m
cat ./sh/mf_p2 >> $dir/$m
find . -name "*.c" -exec cp {} $dir \;
cp libft.h $dir

unset dir
unset m
