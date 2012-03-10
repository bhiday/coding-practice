todo=list("welcome to code jam")

def play (strin,tofind,ccount):
	ans=0
	if (tofind == 18):
		while(todo[tofind] in strin):
			ans = ans + int(ccount[strin.index(todo[tofind])])
			ccount= ccount[strin.index(todo[tofind])+1:]
			strin = strin[strin.index(todo[tofind])+1:]
			
	
	while (todo[tofind] in strin):
		ans = ans + int(ccount[strin.index(todo[tofind])]) * play(strin[strin.index(todo[tofind])+1:],tofind+1,ccount[strin.index(todo[tofind])+1:])
		ccount= ccount[strin.index(todo[tofind])+1:]
		strin = strin[strin.index(todo[tofind])+1:]
	return ans
	
cases=input()
casecount=1
while (cases!=0):
	
	string=raw_input()
	chars=list(string)
	ccount=[]
	
	i=0
	while(i<len(chars)):
		#for j in range(i):
		if (i==0): 
			ccount.append(1)
			i = i + 1
			continue
		if(chars[i]==chars[i-1]):
			#print i-1
			ccount[i-1] = ccount[i-1]+1
			del chars[i]
			i = i - 1
		else:
			ccount.append(1)
		i = i + 1
		
	#print chars
	#print ccount
	answer=play(chars,0,ccount)
	
	print "Case #"+str(casecount)+": "+str(answer%10000).zfill(4)
	casecount = casecount+1
	cases = cases - 1