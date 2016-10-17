/*this function returnst true if the string
between firstIdx and lastIdx inclusive is a palidrome*/
bool isPalidrome(const char* s, int firstIdx, int lastIdx){
	bool rc;
	if(firstIdx >= lastIdx){
		rc=true;
	}
	else{
		if(s[firstIdx]!=s[lastIdx]){
			rc=false;
		}
		else{
			rc=isPalidrome(s,firstIdx+1,lastIdx-1);
		}
	}
}
bool isPalidrome(const char* s){
	return isPalidrome(s,0,strlen(s)-1);
}