folders=(ft_printf ft_print_char ft_print_str ft_print_int ft_print_uint ft_print_hex ft_print_ptr bonus)

for i in "${folders[@]}"
do
	mkdir ${i}
	cd ${i}
	touch test_${i}.c
	cd ..
done
