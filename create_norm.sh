dir="./for-norme"
m="Makefile"
srcdir="./extra_functions ./main_part"

mkdir -p for-norme
cat ./sh/mf_p1 > $dir/$m
find $srcdir -name "*.c" -exec basename {} \; | awk 'NF{print $0 "\\"}' >> $dir/$m
cat ./sh/mf_p2 >> $dir/$m
find $srcdir -name "*.c" -exec cp {} $dir \;
cp libft.h $dir
#cp extra_functions/*.h $dir

unset dir
unset m
