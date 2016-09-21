unsigned int silly1(const char* s){
	unsigned int rc=0;
	for(int i=0;s[i]!='\0';i++){
		rc+=s[i];
	}
}
unsigned int silly2(const char* s){
	unsigned int rc=0;
	for(int i=0;i<strlen(s);i++){
		rc+=s[i];
	}
}
unsigned int silly3(const char* s){
	unsigned int rc=0;
	int n=strlen(s);
	for(int i=0;i<n;i++){
		rc+=s[i];
	}
}