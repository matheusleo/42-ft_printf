folders=(ft_printf ft_print_char ft_print_str ft_print_int ft_print_int ft_print_uint ft_print_hex ft_print_ptr)

for i in "${folders[@]}"
do
	mkdir ${i}
	cd ${i}
	touch main.c
	cd ..
done
