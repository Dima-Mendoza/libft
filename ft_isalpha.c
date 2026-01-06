int ft_isalpha(int c) {
    
    unsigned char alpha = (unsigned char) c;

	if (alpha >= 65 && alpha <= 90) return 1;
	if (alpha >= 97 && alpha <= 122) return 1;
	return 0;
}
