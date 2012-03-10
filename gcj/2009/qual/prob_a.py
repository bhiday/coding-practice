#!/usr/bin/python

#Main
inp = raw_input()
inp_list = inp.split(" ")
l = int(inp_list[0])
d = int(inp_list[1])
n = int(inp_list[2])

#print l,d,n
words=[]

i = d
while i > 0 :
	inp=raw_input()
	words.append(inp)
	i = i - 1
#print words
counter = 1

cases = n
while cases > 0 :
	inp=raw_input()
	symbols = list(inp)
	
	wordsformed = []
	wordsformed.append(symbols)
	
	currword = 0
	currindex = 0
	done = 1
	
	
	for i in range (len(wordsformed)) :
		if (("(") in wordsformed[i]) :
			currword = i
			openbrack = wordsformed[i].index("(")
			closebrack = wordsformed[i].index(")") 
			done = 0
	
	while ( done == 0 ): 
		
		i = openbrack + 1
		
		while (i < closebrack):
			temp = []
			
			if (openbrack != 0) :
				temp.extend(wordsformed[currword][:openbrack])
			temp.append(wordsformed[currword][i])
			if (closebrack != len(wordsformed[currword])+1) :
				temp.extend(wordsformed[currword][closebrack+1:])
			
			#optimization code
			for j in range (len(words)):
				if (words[j][:openbrack + 1]==str(temp[:openbrack+1]).strip("['']").replace("', '","")): 
					wordsformed.append(temp)
			#print str(temp[:openbrack+1]).strip("['']").replace("', '","")
					break
			
			
			del temp
			i = i + 1
		
		wordsformed.remove(wordsformed[currword])
		
		done = 1
		for i in range (len(wordsformed)) :
			if (("(") in wordsformed[i]) :
				currword = i
				openbrack = wordsformed[i].index("(")
				closebrack = wordsformed[i].index(")") 
				done = 0
	
	tempcount = 0
	for i in range (len(wordsformed)) :
		if (str(wordsformed[i][:]).strip("['']").replace("', '","") in words):
			tempcount = tempcount + 1
	
	print "Case #" + str(counter) + ": " + str(tempcount)
	
	counter = counter + 1
	cases = cases - 1
	
	
