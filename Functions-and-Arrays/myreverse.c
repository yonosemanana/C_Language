
void reversestr(int len, char line[], char newline[]) {
	for (int i = 0; i < len; ++i)
		newline[len-1 - i] = line[i];

}
